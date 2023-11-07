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