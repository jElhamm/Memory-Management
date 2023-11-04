# The following code simulates a memory manager that manages variable memory partitions.
# Processes can allocate and deallocate memory blocks from this manager using the MVT algorithm.


class VariablePartition:
    def __init__(self, total_memory):
        self.total_memory = total_memory
        self.partitions = []
        self.memory_map = {}

    def add_partition(self, start_address, size):
        self.partitions.append((start_address, size))

    def allocate_memory(self, process_id, memory_required):
        for i, partition in enumerate(self.partitions):
            start_address, size = partition
            if size >= memory_required:
                # Allocate memory for the process
                self.memory_map[process_id] = (start_address, memory_required)
                # Update the partition with the remaining memory
                self.partitions[i] = (start_address + memory_required, size - memory_required)
                return True
        return False
    
    def display_memory_map(self):
        print("Memory Map:")
        if not self.memory_map:
            print("No allocated memory.")
        else:
            for process_id, (start_address, size) in self.memory_map.items():
                print("Process", process_id, ": Start Address", start_address, ", Size", size)
        print("")
  