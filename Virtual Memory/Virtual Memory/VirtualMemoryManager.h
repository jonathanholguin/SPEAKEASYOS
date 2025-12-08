#ifndef VIRTUALMEMORYMANAGER_H
#define VIRTUALMEMORYMANAGER_H
#include "PageTable.h"
#include "MemoryManager.h"
#include <iostream>
#include <iomanip>
#include <cmath> // For std::log2

class VirtualMemoryManager {
public:
    // Takes user inputs for configuration
    VirtualMemoryManager(int pageSize, int numFrames);

    void translateAddress(int virtualAddress);
    void printStatistics() const;

private:
    // Fixed constants for the simulated address space
    static constexpr int VIRTUAL_ADDR_BITS = 16;

    int pageSize;
    int pageTableSize;
    int offsetMask;
    int pageMask;

    PageTable pageTable;
    MemoryManager memoryManager;

    int pageFaultCount = 0;
    int totalRequests = 0;

    void calculateAddressMasks();
    void handlePageFault(int pageNumber);
};
#endif // VIRTUALMEMORYMANAGER_H