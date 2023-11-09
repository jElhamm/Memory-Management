# The MemoryAllocator class represents a memory allocator that uses the Worst Fit allocation strategy.
# It takes a list of processes and a list of memory blocks as input.
# The class provides methods to perform worst fit allocation, display the allocation results, and calculate fragmentation.
# The allocation results include the assigned block numbers for each process, and the fragmentation details.


class MemoryAllocator:
    def __init__(self, processes, blocks):
        self.processes = processes
        self.blocks = blocks
        self.allocation = [-1] * len(processes)
        self.internal_fragmentation = 0
        self.external_fragmentation = 0

    def worst_fit(self):
        available_blocks = list(self.blocks)

        for i in range(len(self.processes)):
            worst_block_idx = -1
            worst_fit_size = -1

            for j in range(len(available_blocks)):
                # Check if the current block can accommodate the process
                if available_blocks[j] >= self.processes[i] and available_blocks[j] - self.processes[i] > worst_fit_size:
                    worst_block_idx = j
                    worst_fit_size = available_blocks[j] - self.processes[i]

            # Allocate the process to the worst fit block
            if worst_block_idx != -1:
                self.allocation[i] = worst_block_idx
                self.internal_fragmentation += available_blocks[worst_block_idx] - self.processes[i]
                available_blocks[worst_block_idx] -= self.processes[i]
            else:
                # Track external fragmentation if the process cannot be allocated
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
 