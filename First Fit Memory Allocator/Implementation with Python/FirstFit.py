# This program demonstrates a Memory Allocator using the First Fit allocation strategy.


class MemoryAllocator:
    def __init__(self, processes, blocks):
        self.processes = processes
        self.blocks = blocks
        self.allocation = [-1] * len(processes)
        self.internal_fragmentation = 0
        self.external_fragmentation = 0

    def first_fit(self):
        available_blocks = list(self.blocks)

        for i in range(len(self.processes)):
            is_allocated = False

            for j in range(len(available_blocks)):
                if available_blocks[j] >= self.processes[i]:
                    self.allocation[i] = j
                    self.internal_fragmentation += available_blocks[j] - self.processes[i]
                    available_blocks[j] -= self.processes[i]
                    is_allocated = True
                    break

            if not is_allocated:
                self.external_fragmentation += self.processes[i]

    def display_allocation(self):
        print("\n**************************************************************")
        print("Process ID\tProcess Size\tBlock number")
        for i in range(len(self.processes)):
            print(f"     {i + 1}\t\t  {self.processes[i]}\t\t   ", end="")
            if self.allocation[i] != -1:
                print(self.allocation[i] + 1)
            else:
                print("Not Allocated")

        print(f"\nTotal Internal Fragmentation: {self.internal_fragmentation}")
        print(f"Total External Fragmentation: {self.external_fragmentation}")
        print("**************************************************************\n")
 


# Display Output

def banner():
    print("""
          
************************************************************************************************************************
*            This program demonstrates a Memory Allocator using the First Fit allocation strategy.                     *
*         It allows the user to input the sizes of processes and memory blocks and performs allocation                 *
*       based on the First Fit algorithm. The allocation results, including the assigned block numbers and             *
*                           the fragmentation details, are displayed at the end.                                       *
*                                                                                                                      *
*                   Usage:                                                                                             *
*                         1. Enter the number of processes.                                                            *
*                         2. Enter the size of each process.                                                           *
*                         3. Enter the number of memory blocks.                                                        *
*                         4. Enter the size of each memory block.                                                      *
*                         5. The program will allocate the processes using the First Fit algorithm.                    *
*                         6. The allocation results and fragmentation details will be displayed.                       *
*                                                                                                                      *
************************************************************************************************************************
    """)

def main():
    banner()
    num_processes = int(input("---> Enter the number of processes: "))
    processes = []
    for i in range(num_processes):
        process_size = int(input(f"---> Enter the size of process {i + 1}: "))
        processes.append(process_size)

    print("**************************************************************")
    num_blocks = int(input("---> Enter the number of memory blocks: "))
    blocks = []
    for i in range(num_blocks):
        block_size = int(input(f"---> Enter the size of memory block {i + 1}: "))
        blocks.append(block_size)

    allocator = MemoryAllocator(processes, blocks)
    allocator.first_fit()
    allocator.display_allocation()


if __name__ == "__main__":
    main()