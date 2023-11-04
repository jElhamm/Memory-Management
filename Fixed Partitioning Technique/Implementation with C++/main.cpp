// main class


#include <iostream>
#include "fixed_partition.h"

int main() {
    int total_memory, block_size, num_blocks;
    std::cout << "Enter total available memory: ";
    std::cin >> total_memory;
    std::cout << "Enter block size: ";
    std::cin >> block_size;
    std::cout << "Enter number of blocks in memory: ";
    std::cin >> num_blocks;
    FixedPartition memory_manager(total_memory, block_size, num_blocks);
    int num_processes;
    std::cout << "Enter number of processes: ";
    std::cin >> num_processes;

    for (int i = 0; i < num_processes; i++) {
        int process_id = i + 1;
        int memory_required;
        std::cout << "Enter memory required for process " << process_id << ": ";
        std::cin >> memory_required;
        if (memory_manager.allocate_memory(process_id, memory_required)) {
            std::cout << "Memory allocated for process " << process_id << "\n";
        } else {
            std::cout << "Memory allocation failed for process " << process_id << "\n";
        }
    }

    memory_manager.display_memory_map();
    return 0;
}