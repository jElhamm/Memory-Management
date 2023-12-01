// Constructor for the PageTableEntry class
// Initializes the page number and frame number of the entry


#include "PageTableEntry.h"

PageTableEntry::PageTableEntry(int page_number, int frame_number) {
    this->page_number = page_number;
    this->frame_number = frame_number;
}