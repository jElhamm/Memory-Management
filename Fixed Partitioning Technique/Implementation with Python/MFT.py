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
 


# Display Output

def banner():
    print("""
          
********************************************************************************************************
*                          Welcome to the FixedPartition Memory Manager!                               *
*                                                                                                      *
*         This program simulates a memory manager that manages a fixed memory partition with           *
*     blocks of equal size. Processes can allocate and deallocate memory blocks from this manager.     *
*                                                                                                      *
*       To get started, please provide the following information:                                      *
*       1. Total available memory                                                                      *
*       2. Block size                                                                                  *
*       3. Number of blocks in memory                                                                  *
*       4. Number of processes                                                                         *
*                                                                                                      *      
********************************************************************************************************
    """)

def main():
    banner()
    total_memory = int(input("---> Enter total available memory: "))
    block_size = int(input("---> Enter block size: "))
    num_blocks = int(input("---> Enter number of blocks in memory: "))
    memory_manager = FixedPartition(total_memory, block_size, num_blocks)
    num_processes = int(input("---> Enter number of processes: "))
    for i in range(num_processes):
        process_id = i + 1
        memory_required = int(input("---> Enter memory required for process {}: ".format(process_id)))
        if memory_manager.allocate_memory(process_id, memory_required):
            print("Memory allocated for process", process_id)
        else:
            print("Memory allocation failed for process", process_id)
    
    memory_manager.display_memory_map()


if __name__ == '__main__':
    main()