# This program simulates a memory manager with various page replacement algorithms. 
# It is used to manage the allocation of pages in memory and perform page replacement when there are no free frames available.


class PageTableEntry:
    def __init__(self, page_number, frame_number):
        self.page_number = page_number
        self.frame_number = frame_number

class MemoryManager:
    def __init__(self, num_pages, num_frames):
        self.page_table = [None] * num_pages
        self.frame_table = [None] * num_frames
        self.algorithm = None

    def set_page_replacement_algorithm(self, algorithm):
        self.algorithm = algorithm

    def allocate_memory(self, page_number):
        if self.page_table[page_number] is not None:
            print(f"Page {page_number} is already in memory.")
            return

        for i, frame in enumerate(self.frame_table):
            if frame is None:
                self.page_table[page_number] = PageTableEntry(page_number, i)
                self.frame_table[i] = page_number
                print(f"Allocated page {page_number} to frame {i}.")
                return

        print(f"No free frames available. Performing page replacement.")
        self.performPageReplacement(page_number)
 
    def performPageReplacement(self, page_number):
        if self.algorithm == "FIFO":
            self.perform_FIFO_pageReplacement(page_number)
        elif self.algorithm == "LFU":
            self.perform_LFU_pageReplacement(page_number)
        elif self.algorithm == "LRU":
            self.perform_LRU_pageReplacement(page_number)
        elif self.algorithm == "MFU":
            self.perform_MFU_pageReplacement(page_number)
        else:
            print("Invalid page replacement algorithm.")

    # Implementation of 'First-In-First-Out' algorithm
    def perform_FIFO_pageReplacement(self, page_number):
        oldest_page = self.frame_table[0]
        print(f"Replacing page {oldest_page} with page {page_number}.")
        self.page_table[oldest_page] = None
        self.page_table[page_number] = PageTableEntry(page_number, 0)
        self.frame_table[0] = page_number

    # Implementation of 'Least Frequently Used' algorithm   
    def perform_LFU_pageReplacement(self, page_number):
        least_frequently_used_page = min(
            self.frame_table, key=lambda x: self.page_access_count[x]
        )
        print(f"Replacing page {least_frequently_used_page} with page {page_number}.")
        self.page_table[least_frequently_used_page] = None
        self.page_table[page_number] = PageTableEntry(page_number, 0)
        self.frame_table[self.frame_table.index(least_frequently_used_page)] = page_number

    # Implementation of 'Least Recently Used' algorithm
    def perform_LRU_pageReplacement(self, page_number):
        least_recently_used_page = self.frame_table[0]
        print(f"Replacing page {least_recently_used_page} with page {page_number}.")
        self.page_table[least_recently_used_page] = None
        self.page_table[page_number] = PageTableEntry(page_number, 0)
        self.frame_table[0] = page_number

    # Implementation of 'Most Frequently Used' algorithm
    def perform_MFU_pageReplacement(self, page_number):
        most_frequently_used_page = max(self.frame_table, key=lambda x: self.frame_table.count(x))
        print(f"Replacing page {most_frequently_used_page} with page {page_number}.")
        self.page_table[most_frequently_used_page] = None
        self.page_table[page_number] = PageTableEntry(page_number, 0)
        self.frame_table[self.frame_table.index(most_frequently_used_page)] = page_number
 
    def print_memoryStatus(self):
        print("Page Table:")
        for entry in self.page_table:
            if entry is not None:
                print(f"Page {entry.page_number} => Frame {entry.frame_number}")
            else:
                print("Empty")

        print("Frame Table:")
        for frame in self.frame_table:
            if frame is not None:
                print(f"Frame {frame}")
            else:
                print("Empty")
 
    def print_memoryStatus(self):
        print("*****************************************************************")
        print(" *** Page Table:")
        for entry in self.page_table:
            if entry is not None:
                print(f"     Page {entry.page_number} => Frame {entry.frame_number}")
            else:
                print("     Empty")

        print("\n *** Frame Table:")
        for frame in self.frame_table:
            if frame is not None:
                print(f"     Frame {frame}")
            else:
                print("     Empty")


# Display Output

def banner():
    print("""
          
********************************************************************************************************************************************
*                                                 (:          Welcome          :)                                                          *
*                    It implements a memory manager that simulates page allocation and page replacement algorithms.                        *
*                It uses a page table and a frame table to keep track of pages and their corresponding frames in memory.                   *
*  Available page replacement algorithms are FIFO (first in first out), LFU (least used), LRU (least recently used) and MFU (most used).   *
********************************************************************************************************************************************
    """)

def main():
    banner()
    num_pages = int(input("---> Enter the number of pages: "))
    num_frames = int(input("---> Enter the number of frames: "))
    manager = MemoryManager(num_pages, num_frames)
    algorithm_choice = input("---> Enter the page replacement algorithm (FIFO, LFU, LRU, MFU): ")
    manager.set_page_replacement_algorithm(algorithm_choice)
    while True:
        page_number = int(input("Enter the page number to allocate (or -1 to quit): "))
        if page_number == -1:
            break
        manager.allocate_memory(page_number)
        manager.print_memoryStatus()


if __name__ == "__main__":
    main()