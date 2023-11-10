/**
 * The main function is the entry point of the program. It allows the user to input the number and sizes of processes
 * and memory blocks. It creates an instance of the MemoryAllocator class, performs first fit allocation, and displays
 * the allocation result.
 **/



#include "MemoryAllocator.h"
#include <iostream>
#include <vector>

int main() {
    int num_processes;
    std::cout << "---> Enter the number of processes: ";
    std::cin >> num_processes;

    std::vector<int> processes(num_processes);
    for (int i = 0; i < num_processes; i++) {
        int process_size;
        std::cout << "---> Enter the size of process " << i + 1 << ": ";
        std::cin >> process_size;
        processes[i] = process_size;
    }

    std::cout << "**************************************************************" << std::endl;
    int num_blocks;
    std::cout << "---> Enter the number of memory blocks: ";
    std::cin >> num_blocks;

    std::vector<int> blocks(num_blocks);
    for (int i = 0; i < num_blocks; i++) {
        int block_size;
        std::cout << "---> Enter the size of memory block " << i + 1 << ": ";
        std::cin >> block_size;
        blocks[i] = block_size;
    }

    MemoryAllocator allocator(processes, blocks);
    allocator.first_fit();
    allocator.display_allocation();
    return 0;
}