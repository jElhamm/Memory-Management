/** 
 * The FixedPartition class represents a fixed partition memory management scheme.
 * It allows allocating and deallocating memory blocks of fixed sizes for different processes.
 * The class maintains a memory map that tracks the allocation status of each block.
 * It also provides methods to allocate memory, deallocate memory, and display the memory map.
 **/ 



#ifndef FIXED_PARTITION_H
#define FIXED_PARTITION_H
#include <vector>

class FixedPartition {
private:
    int total_memory;
    std::vector<int> block_size;
    int num_blocks;
    std::vector<int> memory_map;

public:
    FixedPartition(int total_memory, int block_size, int num_blocks);
    bool allocate_memory(int process_id, int memory_required);
    bool deallocate_memory(int process_id);
    void display_memory_map();
};

#endif