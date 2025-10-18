#include <iostream>
#include "process.hpp"
using namespace std;

int main() {
    // pid, arrival, burst, priority, initial state, io_operation flag
    Process p1(1, 0.0, 5.0, 1, ProcessState::NEW, false);
    Process p2(2, 2.0, 3.0, 2, ProcessState::NEW, false);
    Process p3(3, 4.0, 8.0, 1, ProcessState::NEW, false);

    int currentTime = 0;

    while (currentTime < 30) {
        cout << "\nTime = " << currentTime << "\n";
        bool ran = false; // we let at most one process run per tick

        if (p1.getState() == ProcessState::NEW && currentTime >= p1.getArrivalTime()) {
            p1.setState(ProcessState::READY);
            cout << "PID " << p1.getPid() << " -> READY\n";
            p1.waitingTimeUpdate(0); // Initialize waiting time
        }
        if (p2.getState() == ProcessState::NEW && currentTime >= p2.getArrivalTime()) {
            p2.setState(ProcessState::READY);
            cout << "PID " << p2.getPid() << " -> READY\n";
            p2.waitingTimeUpdate(0); // Initialize waiting time
        }
        if (p3.getState() == ProcessState::NEW && currentTime >= p3.getArrivalTime()) {
            p3.setState(ProcessState::READY);
            cout << "PID " << p3.getPid() << " -> READY\n";
            p3.waitingTimeUpdate(0); // Initialize waiting time
        }

        if (p1.getState() == ProcessState::READY) p1.waitingTimeUpdate(1.0);
        if (p2.getState() == ProcessState::READY) p2.waitingTimeUpdate(1.0);
        if (p3.getState() == ProcessState::READY) p3.waitingTimeUpdate(1.0);

        // Process 1
        switch (p1.getState()) {
            case ProcessState::READY:
                if (!ran && p1.getRemainingTime() > 0) {
                    p1.setState(ProcessState::RUNNING);
                    cout << "PID " << p1.getPid() << " RUNNING\n";
                    p1.timeTicking(1.0);

                    if (p1.getRemainingTime() <= 0) {
                        p1.processCompletion(currentTime + 1);
                        cout << "PID " << p1.getPid() << " -> TERMINATED\n";
                    } else {
                        p1.setState(ProcessState::READY);
                    }
                    ran = true;
                }
                break;
            default:
                break;
        }

        //Process 2
        switch (p2.getState()) {
            case ProcessState::READY:
                if (!ran && p2.getRemainingTime() > 0) {
                    p2.setState(ProcessState::RUNNING);
                    cout << "PID " << p2.getPid() << " RUNNING\n";
                    p2.timeTicking(1.0);

                    if (p2.getRemainingTime() <= 0) {
                        p2.processCompletion(currentTime + 1);
                        cout << "PID " << p2.getPid() << " -> TERMINATED\n";
                    } else {
                        p2.setState(ProcessState::READY);
                    }
                    ran = true;
                }
                break;
            default:
                break;
        }

        // Process 3
        switch (p3.getState()) {
            case ProcessState::READY:
                if (!ran && p3.getRemainingTime() > 0) {
                    p3.setState(ProcessState::RUNNING);
                    cout << "PID " << p3.getPid() << " RUNNING\n";
                    p3.timeTicking(1.0);

                    if (p3.getRemainingTime() <= 0) {
                        p3.processCompletion(currentTime + 1);
                        cout << "PID " << p3.getPid() << " -> TERMINATED\n";
                    } else {
                        p3.setState(ProcessState::READY);
                    }
                    ran = true;
                }
                break;
            default:
                break;
        }

        if (!ran) {
            cout << "(CPU idle)\n";
        }

        // Checks for all processes terminated
        if (p1.getState() == ProcessState::TERMINATED &&
            p2.getState() == ProcessState::TERMINATED &&
            p3.getState() == ProcessState::TERMINATED) {
            break;
        }

        currentTime++;
    }

    cout << "\nFinal Process States:\n";
    p1.printInfo();
    p2.printInfo();
    p3.printInfo();
    return 0;
}
