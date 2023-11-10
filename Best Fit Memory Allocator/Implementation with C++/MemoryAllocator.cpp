/**
 * to allocate processes to memory blocks. It keeps track of the allocated
 * blocks, calculates internal and external fragmentation, and provides a
 * method to display the allocation details.
 **/



#include "MemoryAllocator.h"
#include <iostream>
#include <limits>

MemoryAllocator::MemoryAllocator(std::vector<int> processes, std::vector<int> blocks) {
    this->processes = processes;
    this->blocks = blocks;
    this->allocation = std::vector<int>(processes.size(), -1);
    this->internal_fragmentation = 0;
    this->external_fragmentation = 0;
}
void MemoryAllocator::best_fit() {
    std::vector<int> available_blocks = blocks;
    for (int i = 0; i < processes.size(); i++) {
        int best_block_idx = -1;
        int best_fit_size = std::numeric_limits<int>::max();

        for (int j = 0; j < available_blocks.size(); j++) {
            if (available_blocks[j] >= processes[i] && available_blocks[j] - processes[i] < best_fit_size) {
                best_block_idx = j;
                best_fit_size = available_blocks[j] - processes[i];
            }
        }
        if (best_block_idx != -1) {
            allocation[i] = best_block_idx;
            internal_fragmentation += available_blocks[best_block_idx] - processes[i];
            available_blocks[best_block_idx] -= processes[i];
        } else {
            external_fragmentation += processes[i];
        }
    }
}
void MemoryAllocator::display_allocation() {
    std::cout << "\n**************************************************************" << std::endl;
    std::cout << "Process ID\tProcess Size\tBlock number" << std::endl;
    for (int i = 0; i < processes.size(); i++) {
        std::cout << "     " << i + 1 << "\t\t  " << processes[i] << "\t\t   ";
        if (allocation[i] != -1) {
            std::cout << allocation[i] + 1 << std::endl;
        } else {
            std::cout << "Not Allocated" << std::endl;
        }
    }

    std::cout << "\nTotal Internal Fragmentation: " << internal_fragmentation << std::endl;
    std::cout << "Total External Fragmentation: " << external_fragmentation << std::endl;
    std::cout << "**************************************************************\n" << std::endl;
}