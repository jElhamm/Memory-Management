// This program demonstrates the usage of the MemoryManager class


#include <iostream>
#include <string>
#include "MemoryManager.h"

int main() {
    int num_pages, num_frames;
    std::string algorithm;
    std::cout << "---> Enter the number of pages: ";
    std::cin >> num_pages;
    std::cout << "---> Enter the number of frames: ";
    std::cin >> num_frames;
    MemoryManager memory_manager(num_pages, num_frames);
    std::cout << "---> Choose a page replacement algorithm (FIFO, LFU, LRU, MFU): ";
    std::cin >> algorithm;
    memory_manager.set_page_replacement_algorithm(algorithm);
    int page_number;
    while (true) {
        std::cout << "---> Enter a page number to allocate memory (enter -1 to exit): ";
        std::cin >> page_number;
        if (page_number == -1) {
            break;
        }
        memory_manager.allocate_memory(page_number);
        memory_manager.print_memoryStatus();
    }
    return 0;
}