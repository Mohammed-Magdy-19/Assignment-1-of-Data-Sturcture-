#include "Process.h"

Process::Process(int id, int arrival_time, int burst_time)
{
    this->id = id;
    this->arrival_time = arrival_time;
    this->burst_time = burst_time;

    this->remaining_time = burst_time;

    this->completion_time = 0;
    this->turnaround_time = 0;
    this->waiting_time = 0;
}

// Getters implementation

int Process::getId() { return this->id; }

int Process::getArrivalTime() { return this->arrival_time; }

int Process::getBurstTime() { return this->burst_time; }

int Process::getRemainingTime() { return this->remaining_time; }

int Process::getCompletionTime() { return this->completion_time; }

int Process::getTurnaroundTime() { return this->turnaround_time; }

int Process::getWaitingTime() { return this->waiting_time; }

// Setters implementation

void Process::setRemainingTime(int remaining_time) { this->remaining_time = remaining_time; }

void Process::setCompletionTime(int completion_time) { this->completion_time = completion_time; }

void Process::setTurnaroundTime(int turnaround_time) { this->turnaround_time = turnaround_time; }

void Process::setWaitingTime(int waiting_time) { this->waiting_time = waiting_time; }