#include <iostream>
#include <vector>
#include "Scheduler.cpp"


using namespace std;

int main()
{
    int time_quantum;
    cout << "Time Quantum: ";
    cin >> time_quantum;
    
    int number_of_Processes;
    cout << "Number of Processes: ";
    cin >> number_of_Processes;

    vector<Process> processes;
    for (int i = 1; i <= number_of_Processes; i++)
    {
        int arival_time, needed_time;

        cout << "Arrival Time of P" << i << ": ";
        cin >> arival_time;

        cout << "Needed Time of P" << i << ": ";
        cin >>needed_time;

        processes.push_back(Process(i, arival_time, needed_time));
        cout << endl;
    }

    Scheduler scheduler(processes, time_quantum);
    scheduler.run();
    scheduler.printResult();
}