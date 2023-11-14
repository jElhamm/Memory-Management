/**
 * The MemoryAllocator class is responsible for managing memory allocation using the Worst Fit strategy.
 * It takes the sizes of processes and memory blocks as parameters during initialization.
 * The class provides functions to perform the Worst Fit algorithm for allocation,
 * display the allocation results, and calculate internal and external fragmentation. 
 **/



#include "MemoryAllocator.h"
#include <iostream>

MemoryAllocator::MemoryAllocator(const std::vector<int>& processes, const std::vector<int>& blocks)
    : processes(processes), blocks(blocks), allocation(processes.size(), -1),
      internal_fragmentation(0), external_fragmentation(0) {}

void MemoryAllocator::worst_fit() {
    std::vector<int> available_blocks = blocks;

    for (int i = 0; i < processes.size(); ++i) {
        int worst_block_idx = -1;
        int worst_fit_size = -1;

        for (int j = 0; j < available_blocks.size(); ++j) {
            // Check if the current block can accommodate the process
            if (available_blocks[j] >= processes[i] && available_blocks[j] - processes[i] > worst_fit_size) {
                worst_block_idx = j;
                worst_fit_size = available_blocks[j] - processes[i];
            }
        }

        // Allocate the process to the worst fit block
        if (worst_block_idx != -1) {
            allocation[i] = worst_block_idx;
            internal_fragmentation += available_blocks[worst_block_idx] - processes[i];
            available_blocks[worst_block_idx] -= processes[i];
        } else {
            // Track external fragmentation if the process cannot be allocated
            external_fragmentation += processes[i];
        }
    }
}
void MemoryAllocator::display_allocation() {
    std::cout << "\n**************************************************************\n";
    std::cout << "Process ID\tProcess Size\tBlock number\n";
    for (int i = 0; i < processes.size(); ++i) {
        std::cout << "     " << i + 1 << "\t\t  " << processes[i] << "\t\t   ";
        if (allocation[i] != -1) {
            std::cout << allocation[i] + 1;
        } else {
            std::cout << "Not Allocated";
        }
        std::cout << '\n';
    }
    std::cout << "\nTotal Internal Fragmentation: " << internal_fragmentation << '\n';
    std::cout << "Total External Fragmentation: " << external_fragmentation << '\n';
    std::cout << "**************************************************************\n";
}