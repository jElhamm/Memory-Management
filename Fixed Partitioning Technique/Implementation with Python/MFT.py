# This class represents a FixedPartition memory manager.
# It manages a fixed memory partition with blocks of equal size.
# Processes can allocate and deallocate memory blocks from this manager.


class FixedPartition:
    def __init__(self, total_memory, block_size, num_blocks):
        self.total_memory = total_memory
        self.block_size = [block_size] * num_blocks
        self.num_blocks = num_blocks
        self.memory_map = [-1] * num_blocks
    
    def allocate_memory(self, process_id, memory_required):
        for i in range(self.num_blocks):
            if self.memory_map[i] == -1 and self.block_size[i] >= memory_required:
                self.memory_map[i] = process_id
                self.block_size[i] -= memory_required
                return True
        return False
    
    def deallocate_memory(self, process_id):
        for i in range(self.num_blocks):
            if self.memory_map[i] == process_id:
                self.memory_map[i] = -1
                self.block_size[i] += self.block_size[i]
                return True
        return False
    
    def display_memory_map(self):
        print("Memory Map:")
        for i in range(self.num_blocks):
            if self.memory_map[i] == -1:
                print("Block", i + 1, ": Free")
            else:
                print("Block", i + 1, ": Process", self.memory_map[i])
        print("")
 