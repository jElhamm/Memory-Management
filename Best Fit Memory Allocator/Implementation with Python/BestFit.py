# The MemoryAllocator class represents a memory allocation system using the Best Fit algorithm.
# It allocates processes to memory blocks based on their sizes and aims to minimize internal fragmentation.
# The allocation results, including block assignments and fragmentation details, can be displayed.



class MemoryAllocator:
    def __init__(self, processes, blocks):
        self.processes = processes
        self.blocks = blocks
        self.allocation = [-1] * len(processes)
        self.internal_fragmentation = 0
        self.external_fragmentation = 0

    def best_fit(self):
        available_blocks = list(self.blocks)

        for i in range(len(self.processes)):
            best_block_idx = -1
            best_fit_size = float('inf')

            for j in range(len(available_blocks)):
                if available_blocks[j] >= self.processes[i] and available_blocks[j] - self.processes[i] < best_fit_size:
                    best_block_idx = j
                    best_fit_size = available_blocks[j] - self.processes[i]

            if best_block_idx != -1:
                self.allocation[i] = best_block_idx
                self.internal_fragmentation += available_blocks[best_block_idx] - self.processes[i]
                available_blocks[best_block_idx] -= self.processes[i]
            else:
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
 