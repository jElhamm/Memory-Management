/**
 * MemoryAllocator class manages the allocation of processes to memory blocks.
 * It provides methods for implementing the first fit algorithm and displaying the allocation.
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
    void first_fit();
    void display_allocation();
};

#endif