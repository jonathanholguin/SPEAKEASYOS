#include "MemoryManager.h"
#include <iostream>

using namespace std;

MemoryManager::MemoryManager(int frameSize, int numFrames)
    : nextFreeFrame(0), frameSize(frameSize), numFrames(numFrames) {
    physicalMemory.resize(numFrames, vector<char>(frameSize));     // Initialize memory dynamically
}

int MemoryManager::getFreeFrame() {
    return (nextFreeFrame < numFrames) ? nextFreeFrame++ : -1;
}

void MemoryManager::loadPageFromDisk(int frameNumber) {
    // Simulates generating data for the frame.
    for (int i = 0; i < frameSize; i++) {
        physicalMemory[frameNumber][i] = 'A' + (i % 26);
    }
}

void MemoryManager::writePage(int frameNumber) {
    loadPageFromDisk(frameNumber);
}

char MemoryManager::readByte(int frameNumber, int offset) const {
    // Basic bounds check
    if (frameNumber >= 0 && frameNumber < numFrames && offset >= 0 && offset < frameSize) {
        return physicalMemory[frameNumber][offset];
    }
    return '\0';
}