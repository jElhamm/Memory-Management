// Implements a Memory Manager class for allocating and replacing pages in memory.


#include <iostream>
#include <algorithm>
#include "MemoryManager.h"

MemoryManager::MemoryManager(int num_pages, int num_frames) {
    page_table = std::vector<PageTableEntry*>(num_pages, nullptr);
    frame_table = std::vector<int>(num_frames, -1);
    algorithm = "";
}
void MemoryManager::set_page_replacement_algorithm(const std::string& algorithm) {
    this->algorithm = algorithm;
}
void MemoryManager::allocate_memory(int page_number) {
    if (page_table[page_number] != nullptr) {
        std::cout << "Page " << page_number << " is already in memory." << std::endl;
        return;
    }
    for (int i = 0; i < frame_table.size(); i++) {
        if (frame_table[i] == -1) {
            page_table[page_number] = new PageTableEntry(page_number, i);
            frame_table[i] = page_number;
            std::cout << "Allocated page " << page_number << " to frame " << i << "." << std::endl;
            return;
        }
    }
    std::cout << "No free frames available. Performing page replacement." << std::endl;
    performPageReplacement(page_number);
}
void MemoryManager::print_memoryStatus() {
    std::cout << "Page Table:" << std::endl;
    for (int i = 0; i < page_table.size(); i++) {
        if (page_table[i] != nullptr) {
            std::cout << "Page " << page_table[i]->page_number << " => Frame " << page_table[i]->frame_number << std::endl;
        } else {
            std::cout << "Empty" << std::endl;
        }
    }
    std::cout << "Frame Table:" << std::endl;
    for (int i = 0; i < frame_table.size(); i++) {
        if (frame_table[i] != -1) {
            std::cout << "Frame " << frame_table[i] << std::endl;
        } else {
            std::cout << "Empty" << std::endl;
        }
    }
}

//********************************************************************************************
void MemoryManager::performPageReplacement(int page_number) {
    if (algorithm == "FIFO") {
        perform_FIFO_pageReplacement(page_number);
    } else if (algorithm == "LFU") {
        perform_LFU_pageReplacement(page_number);
    } else if (algorithm == "LRU") {
        perform_LRU_pageReplacement(page_number);
    } else if (algorithm == "MFU") {
        perform_MFU_pageReplacement(page_number);
    } else {
        std::cout << "Invalid page replacement algorithm." << std::endl;
    }
}
void MemoryManager::perform_FIFO_pageReplacement(int page_number) {
    int oldest_page = frame_table[0];
    std::cout << "Replacing page " << oldest_page << " with page " << page_number << "." << std::endl;
    page_table[oldest_page] = nullptr;
    page_table[page_number] = new PageTableEntry(page_number, 0);
    frame_table[0] = page_number;
}
void MemoryManager::perform_LFU_pageReplacement(int page_number) {
    int least_frequently_used_page = *std::min_element(frame_table.begin(), frame_table.end(),
        [&](int a, int b) {
            return std::count(frame_table.begin(), frame_table.end(), a) < std::count(frame_table.begin(), frame_table.end(), b);
        });
    std::cout << "Replacing page " << least_frequently_used_page << " with page " << page_number << "." << std::endl;
    page_table[least_frequently_used_page] = nullptr;
    page_table[page_number] = new PageTableEntry(page_number, 0);
    std::replace(frame_table.begin(), frame_table.end(), least_frequently_used_page, page_number);
}
void MemoryManager::perform_LRU_pageReplacement(int page_number) {
    int least_recently_used_page = frame_table[0];
    std::cout << "Replacing page " << least_recently_used_page << " with page " << page_number << "." << std::endl;
    page_table[least_recently_used_page] = nullptr;
    page_table[page_number] = new PageTableEntry(page_number, 0);
    frame_table[0] = page_number;
}
void MemoryManager::perform_MFU_pageReplacement(int page_number) {
    int most_frequently_used_page = *std::max_element(frame_table.begin(), frame_table.end(),
        [&](int a, int b) {
            return std::count(frame_table.begin(), frame_table.end(), a) < std::count(frame_table.begin(), frame_table.end(), b);
        });
    std::cout << "Replacing page " << most_frequently_used_page << " with page " << page_number << "." << std::endl;
    page_table[most_frequently_used_page] = nullptr;
    page_table[page_number] = new PageTableEntry(page_number, 0);
    std::replace(frame_table.begin(), frame_table.end(), most_frequently_used_page, page_number);
}
//********************************************************************************************