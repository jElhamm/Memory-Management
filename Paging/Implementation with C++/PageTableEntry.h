// This class represents an entry in the page table.
// It holds the page number and its corresponding frame number.


#ifndef PAGETABLEENTRY_H
#define PAGETABLEENTRY_H

class PageTableEntry {
public:
    int page_number;
    int frame_number;
    PageTableEntry(int page_number, int frame_number);
};

#endif 