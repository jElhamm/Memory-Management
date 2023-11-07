/**
 * The VariablePartition class represents a memory manager that uses the Variable Partition method. 
 * It manages a variable memory partition with different sized partitions.
 * Processes can allocate and deallocate memory blocks from this manager.
 **/



#ifndef VARIABLE_PARTITION_H
#define VARIABLE_PARTITION_H
#include <iostream>
#include <map>
#include <vector>

class VariablePartition {
private:
    int total_memory;
    std::vector<std::pair<int, int>> partitions;
    std::map<int, std::pair<int, int>> memory_map;

public:
    VariablePartition(int total_memory);
    void add_partition(int start_address, int size);
    bool allocate_memory(int process_id, int memory_required);
    bool deallocate_memory(int process_id);
    void display_memory_map();
};

#endif