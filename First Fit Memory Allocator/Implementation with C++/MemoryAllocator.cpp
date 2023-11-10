 /**
 * This class represents a memory allocator that uses the First Fit algorithm.
 * It allocates memory blocks to processes based on their sizes and keeps track of internal and external fragmentation.
 * The allocated blocks are stored in the 'allocation' vector, and the total internal and external fragmentation is calculated and stored.
 * The allocation results can be displayed using the 'display_allocation' method.
 **/



#include "MemoryAllocator.h"
#include <iostream>

MemoryAllocator::MemoryAllocator(std::vector<int> processes, std::vector<int> blocks) {
    this->processes = processes;
    this->blocks = blocks;
    this->allocation = std::vector<int>(processes.size(), -1);
    this->internal_fragmentation = 0;
    this->external_fragmentation = 0;
}
void MemoryAllocator::first_fit() {
    std::vector<int> available_blocks = blocks;
    
    for (int i = 0; i < processes.size(); i++) {
        bool is_allocated = false;
        for (int j = 0; j < available_blocks.size(); j++) {
            if (available_blocks[j] >= processes[i]) {
                allocation[i] = j;                                                      // Allocate the process to the current block
                internal_fragmentation += available_blocks[j] - processes[i];           // Calculate the internal fragmentation
                available_blocks[j] -= processes[i];                                    // Reduce the available size of the block
                is_allocated = true;
                break;
            }
        }
        if (!is_allocated) {
            external_fragmentation += processes[i];             // If the process couldn't be allocated, add it to external fragmentation
        }
    }
}
void MemoryAllocator::display_allocation() {
    std::cout << "\n**************************************************************" << std::endl;
    std::cout << "Process ID\tProcess Size\tBlock number" << std::endl;
    for (int i = 0; i < processes.size(); i++) {
        std::cout << "     " << i + 1 << "\t\t  " << processes[i] << "\t\t\t";
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