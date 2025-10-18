#include <iostream>
#include <string>

using namespace std;

enum class ProcessState{
    NEW,
    READY,
    RUNNING,
    WAITING,
    TERMINATED
};

class Process {

private:
    int pid;
    double arrival_time;
    double burst_time;
    int priority;
    ProcessState state;
    double remaining_time;
    double waiting_time;
    double turnaround_time;
    bool io_operation;

public:
    Process(int pid, double arrival_time, double burst_time, int priority, ProcessState state, bool io_operation);

    // Getters
    int getPid();
    double getArrivalTime();
    double getBurstTime();
    int getPriority();
    ProcessState getState();
    double getRemainingTime();
    double getWaitingTime();
    double getTurnaroundTime();
    bool getIoOperation();

    // Setters
    void setState(ProcessState s);
    void timeTicking(double time);
    void waitingTimeUpdate(double time);
    void processCompletion(double current_time);

    void printInfo();
};