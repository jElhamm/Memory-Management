 /**
 * Represents a Memory Allocator that allocates processes to memory blocks
 * using the Best Fit allocation strategy. It keeps track of the allocated
 * blocks and calculates internal and external fragmentation.
 **/



#ifndef MEMORY_ALLOCATOR_H
#define MEMORY_ALLOCATOR_H
#include <vector>

class MemoryAllocator {
private:
    std::vector<int> processes;
    std::vector<int> blocks;
    std::vector<int> allocation;
    int internal_fragmentation;
    int external_fragmentation;

public:
    MemoryAllocator(std::vector<int> processes, std::vector<int> blocks);
    void best_fit();
    void display_allocation();
};

#endif