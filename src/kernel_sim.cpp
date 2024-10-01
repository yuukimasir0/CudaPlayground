#include <kernel_sim.hpp>

int main() {
    blockDim_x = 32 * 8;
    blockDim_y = 1;
    gridDim_x = (1024 + 31) / 32; 
    gridDim_y = (1024 + 31) / 32; 
    auto f = []() {
        int global_x = blockIdx_x * blockDim_x + threadIdx_x;
        int global_y = blockIdx_y * blockDim_y + threadIdx_y;
        std::cout << "Global (" << global_x << ", " << global_y << ")\n";
    };
    kernel_simulation(f);

    return 0;
}