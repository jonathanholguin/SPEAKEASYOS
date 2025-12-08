#include "VirtualMemoryManager.h"

using namespace std;

//Calculates masks and sizes based on user-provided page sizes.
void VirtualMemoryManager::calculateAddressMasks() {
    int offsetBits = static_cast<int>(log2(pageSize));
    int pageBits = VIRTUAL_ADDR_BITS - offsetBits;

    offsetMask = (1 << offsetBits) - 1;
    pageMask = ((1 << pageBits) - 1) << offsetBits;
    pageTableSize = 1 << pageBits;
}

VirtualMemoryManager::VirtualMemoryManager(int pageSize, int numFrames)
    : pageSize(pageSize),
    pageTable(1), // Temporary size, will be resized below
    memoryManager(pageSize, numFrames)
{
    calculateAddressMasks();

    //Once the page table size ie is calculated, this will execute the Page Table correctly.
    pageTable = PageTable(pageTableSize);

    cout << "Virtual Memory Manager" << endl;
    cout << "Virtual Address Space: 16-bit (" << (1 << VIRTUAL_ADDR_BITS) << " addresses)" << endl;
    cout << "Page Size: " << pageSize << " bytes | Page Table Size: " << pageTableSize << " entries" << endl;
    cout << "Physical Frames (RAM): " << numFrames << endl << endl;
}

void VirtualMemoryManager::handlePageFault(int pageNumber) {
    pageFaultCount++;

    int freeFrame = memoryManager.getFreeFrame();

    if (freeFrame == -1) {
        cerr << "CRITICAL: RAM is full! Cannot load Page " << pageNumber << "." << endl;
        return;
    }
    memoryManager.writePage(freeFrame);
    pageTable.setFrame(pageNumber, freeFrame);
    cout << "[!] Page Fault: Loaded Page " << pageNumber
        << " -> Frame " << freeFrame << endl;
}

void VirtualMemoryManager::translateAddress(int virtualAddress) {
    totalRequests++;

    // 1. Address Splitting (Simplified Bitwise)
    int pageNumber = (virtualAddress & pageMask) >> static_cast<int>(log2(pageSize));
    int offset = virtualAddress & offsetMask;

    // 2. Lookup and Fault Handling
    int frameNumber = pageTable.getFrame(pageNumber);

    if (frameNumber == -1) {
        handlePageFault(pageNumber);
        frameNumber = pageTable.getFrame(pageNumber);
    }

    // 3. Physical Address Calculation and Data Access
    int physicalAddress = (frameNumber * pageSize) + offset;
    char value = memoryManager.readByte(frameNumber, offset);

    // Output formatting
    cout << "VA: " << setw(5) << virtualAddress
        << " [Pg " << setw(3) << pageNumber
        << " | Off " << setw(3) << offset << "]"
        << " -> PA: " << setw(5) << physicalAddress
        << " | Val: " << value << endl;
}

void VirtualMemoryManager::printStatistics() const {
    cout << "\n    Final Statistics    " << endl;
    cout << "Total Requests:    " << totalRequests << endl;
    cout << "Total Page Faults: " << pageFaultCount << endl;

    double hitRate = (totalRequests > 0)
        ? ((double)(totalRequests - pageFaultCount) / totalRequests) * 100.0
        : 0.0;

    cout << "Hit Rate:          " << fixed << setprecision(2) << hitRate << "%" << endl;
}