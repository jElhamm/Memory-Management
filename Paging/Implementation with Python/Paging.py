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
        self.perform_page_replacement(page_number)
 