/**
 * This class represents a Fixed Partition memory management scheme.
 * It provides functionality for allocating and deallocating memory blocks within fixed-sized partitions.
 **/


#include "fixed_partition.h"
#include <iostream>

FixedPartition::FixedPartition(int total_memory, int block_size, int num_blocks)
    : total_memory(total_memory),
      num_blocks(num_blocks),
      block_size(num_blocks, block_size),
      memory_map(num_blocks, -1) {}

bool FixedPartition::allocate_memory(int process_id, int memory_required) {
    for (int i = 0; i < num_blocks; i++) {
        // Check if the memory block is free and has sufficient size
        if (memory_map[i] == -1 && block_size[i] >= memory_required) {
            memory_map[i] = process_id;                     // Allocate the memory block to the process
            block_size[i] -= memory_required;               // Reduce the available size of the block
            return true;
        }
    }
    return false;
}
bool FixedPartition::deallocate_memory(int process_id) {
    for (int i = 0; i < num_blocks; i++) {
        // Find the memory block allocated to the given process
        if (memory_map[i] == process_id) {
            memory_map[i] = -1;                             // Deallocate the memory block
            block_size[i] += block_size[i];                 // Increase the available size of the block
            return true;
        }
    }
    return false;
}
void FixedPartition::display_memory_map() {
    std::cout << "Memory Map:\n";
    for (int i = 0; i < num_blocks; i++) {
        if (memory_map[i] == -1) {
            std::cout << "Block " << i + 1 << ": Free\n";
        } else {
            std::cout << "Block " << i + 1 << ": Process " << memory_map[i] << "\n";
        }
    }
    std::cout << "\n";
}