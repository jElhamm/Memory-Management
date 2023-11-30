# Memory Management Simulation
# This program simulates memory management using different page replacement algorithms.
# It allows the user to input the number of pages and frames, as well as the page replacement algorithm (FIFO, LFU, LRU, MFU).


class PageTableEntry:
    def __init__(self, page_number, frame_number):
        self.page_number = page_number
        self.frame_number = frame_number


class MemoryManager:
    def __init__(self, num_pages, num_frames, replacement_strategy):
        self.page_table = [None] * num_pages
        self.frame_table = [None] * num_frames
        self.replacement_strategy = replacement_strategy

    def allocate_memory(self, page_number):
        if self.page_table[page_number] is not None:
            print(f"Page {page_number} is already in memory.")
            return

        frame_index = self.replacement_strategy.choose_frame(self.frame_table)
        if frame_index is not None:
            self.page_table[page_number] = PageTableEntry(page_number, frame_index)
            self.frame_table[frame_index] = page_number
            print(f"Allocated page {page_number} to frame {frame_index}.")
        else:
            print(f"No free frames available. Performing page replacement.")
            frame_to_replace = self.replacement_strategy.select_frame_to_replace(self.frame_table)
            if frame_to_replace is not None:
                old_page_number = self.frame_table[frame_to_replace]
                new_frame_index = frame_to_replace
                self.page_table[old_page_number] = None
                self.page_table[page_number] = PageTableEntry(page_number, new_frame_index)
                self.frame_table[new_frame_index] = page_number
                print(f"Replacing page {old_page_number} with page {page_number} in frame {new_frame_index}.")
            else:
                print("Invalid page replacement algorithm.")

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
 
#***********************************************************************************************
class ReplacementStrategy:
    def choose_frame(self, frame_table):
        raise NotImplementedError()

    def select_frame_to_replace(self, frame_table):
        raise NotImplementedError()

class FIFOReplacementStrategy(ReplacementStrategy):
    def choose_frame(self, frame_table):
        for i, frame in enumerate(frame_table):
            if frame is None:
                return i
        return None

    def select_frame_to_replace(self, frame_table):
        return 0

class LFUReplacementStrategy(ReplacementStrategy):
    def choose_frame(self, frame_table):
        for i, frame in enumerate(frame_table):
            if frame is None:
                return i
        return None

    def select_frame_to_replace(self, frame_table):
        least_frequently_used_page = min(frame_table, key=lambda x: frame_table.count(x))
        return frame_table.index(least_frequently_used_page)

class LRUReplacementStrategy(ReplacementStrategy):
    def choose_frame(self, frame_table):
        for i, frame in enumerate(frame_table):
            if frame is None:
                return i
        return None

    def select_frame_to_replace(self, frame_table):
        return 0

class MFUReplacementStrategy(ReplacementStrategy):
    def choose_frame(self, frame_table):
        for i, frame in enumerate(frame_table):
            if frame is None:
                return i
        return None

    def select_frame_to_replace(self, frame_table):
        most_frequently_used_page = max(frame_table, key=lambda x: frame_table.count(x))
        return frame_table.index(most_frequently_used_page)
#***********************************************************************************************
 
 
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
    num_pages = int(input("---> Enter the number of pages: "))
    num_frames = int(input("---> Enter the number of frames: "))
    algorithm_choice = input("---> Enter the page replacement algorithm (FIFO, LFU, LRU, MFU): ")
    replacement_strategy = None
    if algorithm_choice == "FIFO":
        replacement_strategy = FIFOReplacementStrategy()
    elif algorithm_choice == "LFU":
        replacement_strategy = LFUReplacementStrategy()
    elif algorithm_choice == "LRU":
        replacement_strategy = LRUReplacementStrategy()
    elif algorithm_choice == "MFU":
        replacement_strategy = MFUReplacementStrategy()
    else:
        print("(   ! Invalid page replacement algorithm. !   )")
        return
    manager = MemoryManager(num_pages, num_frames, replacement_strategy)
    while True:
        page_number = int(input("---> Enter the page number to allocate (or -1 to quit): "))
        if page_number == -1:
            break
        manager.allocate_memory(page_number)
        manager.print_memory_status()


if __name__ == "__main__":
    main()