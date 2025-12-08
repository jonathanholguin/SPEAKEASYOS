#ifndef MEMORYMANAGER_H
#define MEMORYMANAGER_H
#include <vector>

class MemoryManager {
public:
    MemoryManager(int frameSize, int numFrames);
    int getFreeFrame();
    char readByte(int frameNumber, int offset) const;
    void writePage(int frameNumber);
private:
    std::vector<std::vector<char>> physicalMemory;
    int nextFreeFrame;
    int frameSize;
    int numFrames;

    void loadPageFromDisk(int frameNumber);
};
#endif 