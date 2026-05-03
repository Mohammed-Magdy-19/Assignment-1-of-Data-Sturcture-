#include "Scheduler.h"
#include "Process.cpp"
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void Scheduler::enqueueArrivedProcess()
{
    while (enqueued_count < (int)processes.size() && processes[enqueued_count].getArrivalTime() <= current_time)
    {
        ids.push(processes[enqueued_count].getId());
        enqueued_count++;
    }
}

Scheduler::Scheduler(std::vector<Process> &processes, int time_quantum) : current_time(0), enqueued_count(0)
{
    this->processes = processes;
    this->time_quantum = time_quantum;
}

void Scheduler::run()
{
    sort(processes.begin(), processes.end(), [](Process a, Process b)
         { return a.getArrivalTime() < b.getArrivalTime(); });

    enqueueArrivedProcess();
    printQueue();


    while (!ids.empty())
    {
        // 1) Pick the next process
        int current_id = ids.front();
        ids.pop();
        auto it = find_if(processes.begin(), processes.end(), [current_id](Process &p)
                          { return p.getId() == current_id; });
        Process &current_process = *it;

        // 2) Run for one time slice
        int time_slice = min(time_quantum, current_process.getRemainingTime());
        current_process.setRemainingTime(current_process.getRemainingTime() - time_slice);
        current_time += time_slice;

        // 3) Enqueue newly arrived processes (before re-enqueqing current)
        enqueueArrivedProcess();

        // 4) handle current process outcome
        if (current_process.getRemainingTime() == 0)
        {
            current_process.setCompletionTime(current_time);
            current_process.setTurnaroundTime(current_process.getCompletionTime() - current_process.getArrivalTime());
            current_process.setWaitingTime(current_process.getTurnaroundTime() - current_process.getBurstTime());
        }
        else
        {
            ids.push(current_id);
        }
        printQueue();

        if (ids.empty() && enqueued_count < (int)processes.size())
        {
            current_time = processes[enqueued_count].getArrivalTime();
            enqueueArrivedProcess();
            printQueue();
        }
    }
}

void Scheduler::printQueue()
{
    if (ids.empty())
    {
        cout << "[ Empty ]" << endl;
        return;
    }

    queue<int> temp_queue = ids;
    cout << "[ ";
    while (!temp_queue.empty())
    {
        cout << "P" << temp_queue.front();
        temp_queue.pop();
        if (!temp_queue.empty())
            cout << ", ";
    }
    cout << " ]" << endl;
}

void Scheduler::printResult()
{
    // Table header
    cout << endl << string(65, '-') << endl;

    cout << left
         << setw(10) << "Process"
         << setw(20) << "Completion Time"
         << setw(20) << "Turnaround Time"
         << setw(15) << "Waiting Time"
         << endl;

    cout << string(65, '-') << endl;

    // Table rows
    float total_waiting_time = 0;

    for (Process &p : processes)
    {
        cout << left
             << setw(10) << ("P" + to_string(p.getId()))
             << setw(20) << p.getCompletionTime()
             << setw(20) << p.getTurnaroundTime()
             << setw(15) << p.getWaitingTime()
             << endl;

        total_waiting_time += p.getWaitingTime();
    }

    // Average waiting time
    cout << string(65, '-') << endl;
    cout << fixed << setprecision(2);
    cout << "Average Waiting Time: " << (total_waiting_time / processes.size()) << endl;
}
