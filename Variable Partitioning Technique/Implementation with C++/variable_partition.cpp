// Class:        VariablePartition
// Description:  This class represents a memory manager that uses variable partitions to allocate 
//               and deallocate memory for processes.



#include "variable_partition.h"

VariablePartition::VariablePartition(int total_memory) {
    this->total_memory = total_memory;
}

void VariablePartition::add_partition(int start_address, int size) {
    partitions.push_back(std::make_pair(start_address, size));
}

bool VariablePartition::allocate_memory(int process_id, int memory_required) {
    for (int i = 0; i < partitions.size(); i++) {
        int start_address = partitions[i].first;
        int size = partitions[i].second;
        if (size >= memory_required) {
            // Allocate memory for the process
            memory_map[process_id] = std::make_pair(start_address, memory_required);
            // Update the partition with the remaining memory
            partitions[i] = std::make_pair(start_address + memory_required, size - memory_required);
            return true;
        }
    }
    return false;
}

bool VariablePartition::deallocate_memory(int process_id) {
    if (memory_map.count(process_id) > 0) {
        int start_address = memory_map[process_id].first;
        int size = memory_map[process_id].second;
        // Add the partition back to the list with its original size
        partitions.push_back(std::make_pair(start_address, size));
        // Remove the process from the memory map
        memory_map.erase(process_id);
        return true;
    }
    return false;
}

void VariablePartition::display_memory_map() {
    std::cout << "Memory Map:" << std::endl;
    if (memory_map.empty()) {
        std::cout << "No allocated memory." << std::endl;
    } else {
        for (auto it = memory_map.begin(); it != memory_map.end(); it++) {
            int process_id = it->first;
            int start_address = it->second.first;
            int size = it->second.second;
            std::cout << "Process " << process_id << ": Start Address " << start_address << ", Size " << size << std::endl;
        }
    }
    std::cout << std::endl;
}