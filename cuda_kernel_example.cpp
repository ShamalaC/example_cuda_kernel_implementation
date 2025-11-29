// Basic CUDA kernel that adds two arrays
__global__ void addArrays(const float* arrA, const float* arrB, float* arrOut, int count) {
    int id = blockIdx.x * blockDim.x + threadIdx.x;
    if (id < count) {
        arrOut[id] = arrA[id] + arrB[id];
    }
}

// Host function to launch the kernel
void runAddKernel(const float* hostA, const float* hostB, float* hostOut, int count) {
    float *devA, *devB, *devOut;

    cudaMalloc(&devA, count * sizeof(float));
    cudaMalloc(&devB, count * sizeof(float));
    cudaMalloc(&devOut, count * sizeof(float));

    cudaMemcpy(devA, hostA, count * sizeof(float), cudaMemcpyHostToDevice);
    cudaMemcpy(devB, hostB, count * sizeof(float), cudaMemcpyHostToDevice);

    int blockSize = 256;
    int gridSize = (count + blockSize - 1) / blockSize;

    addArrays<<<gridSize, blockSize>>>(devA, devB, devOut, count);

    cudaMemcpy(hostOut, devOut, count * sizeof(float), cudaMemcpyDeviceToHost);

    cudaFree(devA);
    cudaFree(devB);
    cudaFree(devOut);
}
