#pragma once

#include <vector>
#include <queue>
#include "Process.h"

class Scheduler
{
private:
    std::vector<Process> processes;
    std::queue<int> ids;
    int time_quantum;
    int current_time = 0;
    int enqueued_count = 0;
    void enqueueArrivedProcess();

public:
    Scheduler(std::vector<Process>& processes, int time_quantum);
    void run();
    void printQueue ();
    void printResult ();
    ~Scheduler() {};
};
