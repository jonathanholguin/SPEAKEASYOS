#include "process.hpp"
#include <iostream>
#include <string>

using namespace std;

Process::Process(int p, double atime, double btime, int pr, ProcessState st, bool io_op){
    pid = p;
    arrival_time = atime;
    burst_time = btime;
    priority = pr;
    state = st;
    io_operation = io_op;
    remaining_time = burst_time;
    waiting_time = 0;
    turnaround_time = 0;
}

//Defining Getters

int Process::getPid(){
    return pid;
}

double Process::getArrivalTime(){
    return arrival_time;
}

double Process::getBurstTime(){
    return burst_time;
}

int Process::getPriority(){
    return priority;
}

ProcessState Process::getState(){
    return state;
}

double Process::getRemainingTime(){
    return remaining_time;
}

double Process::getWaitingTime(){
    return waiting_time;
}

double Process::getTurnaroundTime(){
    return turnaround_time;
}

bool Process::getIoOperation(){
    return io_operation;
}

//Defining Setters

void Process::setState(ProcessState s){
    state = s;
}


void Process::timeTicking(double time){
    if(state == ProcessState::RUNNING){
        remaining_time -= time;
        if(remaining_time < 0){
            remaining_time = 0;
        }
    }
}

void Process::waitingTimeUpdate(double time){
    if(state == ProcessState::READY){
        waiting_time += time;
    }
}

void Process::processCompletion(double time){
    if(remaining_time <= 0){
        state = ProcessState::TERMINATED;
        turnaround_time = time - arrival_time;
    }
}

void Process::printInfo(){
    cout << "\nProcess ID: " << pid << endl;
    cout << "Arrival Time: " << arrival_time << endl;
    cout << "Burst Time: " << burst_time << endl;
    cout << "Priority: " << priority << endl;
    cout << "State: ";
    switch(state){
        case ProcessState::NEW:
            cout << "NEW" << endl;
            break;
        case ProcessState::READY:
            cout << "READY" << endl;
            break;
        case ProcessState::RUNNING:
            cout << "RUNNING" << endl;
            break;
        case ProcessState::WAITING:
            cout << "WAITING" << endl;
            break;
        case ProcessState::TERMINATED:
            cout << "TERMINATED" << endl;
            break;
    }
    cout << "Remaining Time: " << remaining_time << endl;
    cout << "Waiting Time: " << waiting_time << endl;
    cout << "Turnaround Time: \n" << turnaround_time << endl;
}