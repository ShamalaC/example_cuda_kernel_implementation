This project contains a very simple CUDA C++ program that demonstrates example of a kernel adding two float arrays on the GPU.

## Project Structure
cuda-addition/
│
├── add_arrays.cu        # Main CUDA file (kernel + host code)
└── README.md            # This file

## Prerequisites

To run and compile this project, you need:

NVIDIA GPU
CUDA Toolkit installed
g++ or nvcc compiler
Linux or WSL recommended (macOS doesn’t support CUDA natively)
Check your CUDA version with:
nvcc --version

## Kernel Explanation

The kernel performs a simple operation:
1. Each CUDA thread handles one element of the array
2. It reads values from two input arrays
3. It writes the sum into the output array

## This example demonstrates:
1. Thread indexing
2. Grid/block configuration
3. Copying data between CPU and GPU
4. Launching a CUDA kernel
5. Build and Run
6. Compile


This uses nvcc to compile the .cu file.
1. Run
./add_arrays

You should see output similar to:
Result: 11 22 33 44
