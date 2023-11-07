// It allows the user to specify the total available memory and the number of partitions.
// Then, it prompts the user to enter the start addresses and sizes for each partition.
// After that, the user can enter the number of processes and their memory requirements.
// The class attempts to allocate memory for each process and displays the memory map.
// If memory allocation fails for a process, an appropriate message is displayed.
// The class serves as a memory management system using variable partitioning.


#include <iostream>
#include "variable_partition.h"

int main() {
    int total_memory;
    std::cout << "---> Enter total available memory: ";
    std::cin >> total_memory;
    VariablePartition memory_manager(total_memory);
    int num_partitions;
    std::cout << "---> Enter number of partitions: ";
    std::cin >> num_partitions;

    for (int i = 0; i < num_partitions; i++) {
        int start_address, size;
        std::cout << "---> Enter start address for partition " << i + 1 << ": ";
        std::cin >> start_address;
        std::cout << "---> Enter size for partition " << i + 1 << ": ";
        std::cin >> size;
        memory_manager.add_partition(start_address, size);
    }

    int num_processes;
    std::cout << "---> Enter number of processes: ";
    std::cin >> num_processes;

    for (int i = 0; i < num_processes; i++) {
        int process_id = i + 1;
        int memory_required;
        std::cout << "---> Enter memory required for process " << process_id << ": ";
        std::cin >> memory_required;
        if (memory_manager.allocate_memory(process_id, memory_required)) {
            std::cout << "Memory allocated for process " << process_id << std::endl;
        } else {
            std::cout << "Memory allocation failed for process " << process_id << std::endl;
        }
    }

    memory_manager.display_memory_map();
    return 0;
}