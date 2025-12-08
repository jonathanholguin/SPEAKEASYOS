//Team members: Jonathan Holguin, Arturo Galvez, Alan Verdugo

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <limits>

using namespace std;

struct Process {
    int id, arrivalTime, burstTime, completionTime, turnaroundTime, waitingTime, remainingTime;

    Process(int i, int at, int bt)
        : id(i), arrivalTime(at), burstTime(bt), remainingTime(bt),
        completionTime(0), turnaroundTime(0), waitingTime(0) {}
};

void calculate_metrics(vector<Process>& processes) {
    int total_tat = 0;
    int total_wt = 0;

    //I decided to make a table since a list format would look to messy.
    cout << "| PID | Arrival | Burst | Complete | Turnaround | Waiting |\n";

    for (Process& p : processes) {
        p.turnaroundTime = p.completionTime - p.arrivalTime;
        p.waitingTime = p.turnaroundTime - p.burstTime;

        total_tat += p.turnaroundTime;
        total_wt += p.waitingTime;

        cout << "| " << setw(3) << p.id
            << " | " << setw(7) << p.arrivalTime
            << " | " << setw(5) << p.burstTime
            << " | " << setw(8) << p.completionTime
            << " | " << setw(10) << p.turnaroundTime
            << " | " << setw(7) << p.waitingTime << " |\n";
    }

    double avg_tat = (double)total_tat / processes.size();
    double avg_wt = (double)total_wt / processes.size();

    cout << fixed << setprecision(2)
        << "  Average Turnaround Time: " << avg_tat << endl
        << "  Average Waiting Time:    " << avg_wt << endl << endl;
}

void FCFS(vector<Process> processes) {

    cout << "         First-Come, First-Served (FCFS)\n";

    sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
        if (a.arrivalTime != b.arrivalTime) {
            return a.arrivalTime < b.arrivalTime; 
        }
        return a.id < b.id; 
        });

    int currentTime = 0;

    for (Process& p : processes) {
        if (currentTime < p.arrivalTime) {
            currentTime = p.arrivalTime;
        }
        p.completionTime = currentTime + p.burstTime;
        currentTime = p.completionTime;
    }
    calculate_metrics(processes);
}

void SJF_NonPreemptive(vector<Process> processes) {

    cout << "   Shortest Job First (SJF) Non-Preemptive\n";

    //Sorts processes by Arrival Time initially for convenience
    sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
        return a.arrivalTime < b.arrivalTime;
        });

    int currentTime = 0;
    int completed = 0;
    int n = processes.size();
    vector<bool> isCompleted(n, false);

    while (completed != n) {
        int shortest_burst = 99999;
        int shortest_index = -1;


        for (int i = 0; i < n; i++) {
            if (processes[i].arrivalTime <= currentTime && !isCompleted[i]) {
                if (processes[i].burstTime < shortest_burst) {
                    shortest_burst = processes[i].burstTime;
                    shortest_index = i;
                }

                if (processes[i].burstTime == shortest_burst) {
                    if (processes[i].arrivalTime < processes[shortest_index].arrivalTime) {
                        shortest_index = i;
                    }
                }
            }
        }
        if (shortest_index == -1) {
            currentTime++;
        }
        else {
            Process& p = processes[shortest_index];
            currentTime += p.burstTime;
            p.completionTime = currentTime;
            isCompleted[shortest_index] = true;
            completed++;
        }
    }
    sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
        return a.id < b.id;
        });
    calculate_metrics(processes);
}

vector<Process> getInputProcesses() {
    int numProcesses;
    cout << "Enter the number of processes: ";
    while (!(cin >> numProcesses) || numProcesses <= 0) {
        cout << "Invalid input. Please enter a positive integer: ";
        cin.clear(); // Clear error flags
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    }

    vector<Process> inputProcesses;
    cout << "\n    Enter Process Details     \n";

    for (int i = 0; i < numProcesses; ++i) {
        int id, at, bt;

        cout << "Process ID : ";
        while (!(cin >> id) || id <= 0) {
            cout << "Invalid ID. Please enter a positive integer: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Arrival Time (P" << id << "): ";
        while (!(cin >> at) || at < 0) {
            cout << "Invalid AT. Please enter a non-negative integer: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Burst Time (P" << id << "): ";

        while (!(cin >> bt) || bt <= 0) {
            cout << "Invalid BT. Please enter a positive integer: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        inputProcesses.emplace_back(id, at, bt);

    }
    return inputProcesses;
}

void SRTF_Preemptive(vector<Process> processes) {
    cout << "  Shortest Remaining Time First (SRTF)\n";

    int n = processes.size();
    int currentTime = 0;
    int completed = 0;
    int total_burst_time = 0;

    //Calculates the total burst time to set the simulation limit
    for (const auto& p : processes) {
        total_burst_time += p.burstTime;
    }

    while(completed != n) {
        int shortest_remaining = 99999;
        int shortest_index = -1;

        //Checks for the shortest remaining time among all arrived processes
        for (int i = 0; i < n; i++) {
            if (processes[i].arrivalTime <= currentTime && processes[i].remainingTime > 0) {
                if (processes[i].remainingTime < shortest_remaining) {
                    shortest_remaining = processes[i].remainingTime;
                    shortest_index = i;
                }
                //This will be the tie-breaker
                if (processes[i].remainingTime == shortest_remaining) {
                    if (processes[i].arrivalTime < processes[shortest_index].arrivalTime) {
                        shortest_index = i;
                    }
                }
            }
        }
        if (shortest_index == -1) {
            currentTime++;
            continue;
        }
        Process& running_process = processes[shortest_index];
        running_process.remainingTime--;
        currentTime++;
        if (running_process.remainingTime == 0) {
            running_process.completionTime = currentTime;
            completed++;
        }
    }
    sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
        return a.id < b.id;
        });
    calculate_metrics(processes);
}


// I didn't know if you wanted the user to input the values for the ID, arrival time, and burst... but I implemented it as a user input. 
// If it was supposed to be randomized by the program, please let us know.,
int main() {

    vector<Process> userProcesses = getInputProcesses();
    vector<Process> processesFCFS = userProcesses;
    FCFS(processesFCFS);
    vector<Process> processesSJF = userProcesses;
    SJF_NonPreemptive(processesSJF);
    vector<Process> processesSRTF = userProcesses;
    SRTF_Preemptive(processesSRTF);

    return 0;

}
