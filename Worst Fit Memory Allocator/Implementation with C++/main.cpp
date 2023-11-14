 /**
 * The following line includes the header file "MemoryAllocator.h" in the program.
 * This header file contains the declaration of the MemoryAllocator class, which is responsible for managing memory allocation
 * using the Worst Fit strategy. It provides functions for allocation, deallocation, and displaying allocation details.
 * Including this header allows us to use the MemoryAllocator class and its functions in the main program.
 **/



#include "MemoryAllocator.h"

void banner() {
    std::cout << "\n************************************************************************************************************************\n";
    std::cout << "*            This program demonstrates a Memory Allocator using the Worst Fit allocation strategy.                     *\n";
    std::cout << "*         It allows the user to input the sizes of processes and memory blocks and performs allocation                *\n";
    std::cout << "*       based on the Worst Fit algorithm. The allocation results, including the assigned block numbers and            *\n";
    std::cout << "*                           the fragmentation details, are displayed at the end.                                      *\n";
    std::cout << "*                                                                                                                      *\n";
    std::cout << "*                   Usage:                                                                                             *\n";
    std::cout << "*                         1. Enter the number of processes.                                                            *\n";
    std::cout << "*                         2. Enter the size of each process.                                                           *\n";
    std::cout << "*                         3. Enter the number of memory blocks.                                                        *\n";
    std::cout << "*                         4. Enter the size of each memory block.                                                      *\n";
    std::cout << "*                         5. The program will allocate the processes using the Worst Fit algorithm.                   *\n";
    std::cout << "*                         6. The allocation results and fragmentation details will be displayed.                       *\n";
    std::cout << "*                                                                                                                      *\n";
    std::cout << "************************************************************************************************************************\n";
}

int main() {
    banner();
    int num_processes;
    std::cout << "---> Enter the number of processes: ";
    std::cin >> num_processes;
    std::vector<int> processes(num_processes);
    for (int i = 0; i < num_processes; ++i) {
        std::cout << "---> Enter the size of process " << i + 1 << ": ";
        std::cin >> processes[i];
    }

    std::cout << "**************************************************************\n";
    int num_blocks;
    std::cout << "---> Enter the number of memory blocks: ";
    std::cin >> num_blocks;
    std::vector<int> blocks(num_blocks);
    for (int i = 0; i < num_blocks; ++i) {
        std::cout << "---> Enter the size of memory block " << i + 1 << ": ";
        std::cin >> blocks[i];
    }

    MemoryAllocator allocator(processes, blocks);
    allocator.worst_fit();
    allocator.display_allocation();
    return 0;
}