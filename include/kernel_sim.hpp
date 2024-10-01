#pragma once
#include <utils.hpp>

int blockIdx_x;
int blockIdx_y;
int threadIdx_x;
int threadIdx_y;
int gridDim_x;
int gridDim_y;
int blockDim_x;
int blockDim_y;

template <typename Fn>
void kernel_simulation(Fn kernel) {
    for (blockIdx_x = 0; blockIdx_x < gridDim_x; ++blockIdx_x) {
        for (blockIdx_y = 0; blockIdx_y < gridDim_y; ++blockIdx_y) {
            for (threadIdx_x = 0; threadIdx_x < blockDim_x; ++threadIdx_x) {
                for (threadIdx_y = 0; threadIdx_y < blockDim_y; ++threadIdx_y) {
                    std::cout << "=== Block (" << blockIdx_x << ", " << blockIdx_y << "), " << "Thread (" << threadIdx_x << ", " << threadIdx_y << ") ===\n";
                    kernel();
                }
            }
        }
    }
}