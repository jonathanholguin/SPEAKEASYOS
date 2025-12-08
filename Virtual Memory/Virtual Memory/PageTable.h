#ifndef PAGETABLE_H
#define PAGETABLE_H
#include <vector>

class PageTable {
public:
    PageTable(int tableSize);
    int getFrame(int pageNumber) const;
    void setFrame(int pageNumber, int frameNumber);
private:
    std::vector<int> entries;
};
#endif