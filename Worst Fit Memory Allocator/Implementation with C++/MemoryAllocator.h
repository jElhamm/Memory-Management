// The MemoryAllocator class is responsible for managing memory allocation using different strategies.


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
    MemoryAllocator(const std::vector<int>& processes, const std::vector<int>& blocks);
    void worst_fit();
    void display_allocation();
};

#endif