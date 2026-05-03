#pragma once

class Process
{
private:
    int id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;

public:
    Process(int id, int arrival_time, int burst_time);
    
    // Geters
    int getId();
    int getArrivalTime();
    int getBurstTime();
    int getRemainingTime();
    int getCompletionTime();
    int getTurnaroundTime();
    int getWaitingTime();

    // Setters
    void setRemainingTime(int remaining_time);
    void setCompletionTime(int completion_time);
    void setTurnaroundTime(int turnaround_time);
    void setWaitingTime(int waiting_time);

    ~Process() {};
};
