#include <iostream>
#include <vector>
#include <cmath>
#include "VirtualMemoryManager.h"

using namespace std;

//Ensures the user inputs a power of 2 for Page Size
bool isPowerOfTwo(int n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}

int main() {
    int pageSize;
    int Frames;

    cout << "    Setup Virtual Memory Configuration    \n";

    //Get Page Size
    do {
        cout << "Page Size (must be a power of 2, e.g., 256): ";
        cin >> pageSize; 

        if (!isPowerOfTwo(pageSize) || pageSize <= 0) {
            system("cls");
            cout << "Page size invalid. Try again.\n";
        }

    } while (!isPowerOfTwo(pageSize) || pageSize <= 0);



    // Get Physical Memory Size (Number of Frames)
    cout << "Enter Number of Physical Frames (RAM size, e.g., 256): ";
    cin >> Frames;

    cout << "\nChecking... Valid. Simulation is starting...\n";

    VirtualMemoryManager vmm(pageSize, Frames);

    // Simulation Data (Fixed for testing)
    vector<int> logicalAddresses = { 16916, 62493, 30198, 16917, 1234, 30200 };

    cout << "    Starting Address Translation    \n";

    for (int address : logicalAddresses) {
        vmm.translateAddress(address);
    }

    vmm.printStatistics();

    return 0;
}