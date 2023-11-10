/** This program demonstrates a Memory Allocator using the Best Fit allocation strategy.
 * It allows the user to input the sizes of processes and memory blocks and performs allocation
 * based on the Best Fit algorithm. The allocation results, including the assigned block numbers and
 * the fragmentation details, are displayed at the end.
 **/



#include <iostream>
#include <vector>
#include "MemoryAllocator.h"

void banner() {
    std::cout << "\n************************************************************************************************************************" << std::endl;
    std::cout << "*            This program demonstrates a Memory Allocator using the Best Fit allocation strategy.                      *" << std::endl;
    std::cout << "*         It allows the user to input the sizes of processes and memory blocks and performs allocation                 *" << std::endl;
    std::cout << "*       based on the Best Fit algorithm. The allocation results, including the assigned block numbers and             *" << std::endl;
    std::cout << "*                           the fragmentation details, are displayed at the end.                                       *" << std::endl;
    std::cout << "*                                                                                                                      *" << std::endl;
    std::cout << "*                   Usage:                                                                                             *" << std::endl;
    std::cout << "*                         1. Enter the number of processes.                                                            *" << std::endl;
    std::cout << "*                         2. Enter the size of each process.                                                           *" << std::endl;
    std::cout << "*                         3. Enter the number of memory blocks.                                                        *" << std::endl;
    std::cout << "*                         4. Enter the size of each memory block.                                                      *" << std::endl;
    std::cout << "*                         5. The program will allocate the processes using the Best Fit algorithm.                    *" << std::endl;
    std::cout << "*                         6. The allocation results and fragmentation details will be displayed.                       *" << std::endl;
    std::cout << "*                                                                                                                      *" << std::endl;
    std::cout << "************************************************************************************************************************\n" << std::endl;
}

int main() {
    banner();
    int num_processes;
    std::cout << "---> Enter the number of processes: ";
    std::cin >> num_processes;
    std::vector<int> processes;
    for (int i = 0; i < num_processes; i++) {
        int process_size;
        std::cout << "---> Enter the size of process " << i + 1 << ": ";
        std::cin >> process_size;
        processes.push_back(process_size);
    }

    std::cout << "**************************************************************" << std::endl;
    int num_blocks;
    std::cout << "---> Enter the number of memory blocks: ";
    std::cin >> num_blocks;
    std::vector<int> blocks;
    for (int i = 0; i < num_blocks; i++) {
        int block_size;
        std::cout << "---> Enter the size of memory block " << i + 1 << ": ";
        std::cin >> block_size;
        blocks.push_back(block_size);
    }

    MemoryAllocator allocator(processes, blocks);
    allocator.best_fit();
    allocator.display_allocation();
    return 0;
}