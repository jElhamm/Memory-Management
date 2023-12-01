// This class represents a memory manager responsible for managing page and frame allocations
// It uses various page replacement algorithms such as FIFO, LFU, LRU, and MFU.


#ifndef MEMORYMANAGER_H
#define MEMORYMANAGER_H
#include <vector>
#include <string>
#include "PageTableEntry.h"

class MemoryManager {
private:
    std::vector<PageTableEntry*> page_table;
    std::vector<int> frame_table;
    std::string algorithm;

public:
    MemoryManager(int num_pages, int num_frames);
    void set_page_replacement_algorithm(const std::string& algorithm);
    void allocate_memory(int page_number);
    void performPageReplacement(int page_number);
    void perform_FIFO_pageReplacement(int page_number);
    void perform_LFU_pageReplacement(int page_number);
    void perform_LRU_pageReplacement(int page_number);
    void perform_MFU_pageReplacement(int page_number);
    void print_memoryStatus();
};

#endif