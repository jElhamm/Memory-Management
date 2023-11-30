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
 