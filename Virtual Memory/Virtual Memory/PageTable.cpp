#include "PageTable.h"
#include <iostream>

using namespace std;

PageTable::PageTable(int tableSize) {
    // Initialize entries dynamically
    entries.resize(tableSize, -1);
}

int PageTable::getFrame(int pageNumber) const {
    return (pageNumber >= 0 && pageNumber < entries.size()) ? entries[pageNumber] : -1;
}

void PageTable::setFrame(int pageNumber, int frameNumber) {
    if (pageNumber >= 0 && pageNumber < entries.size()) {
        entries[pageNumber] = frameNumber;
    }
}