#include <iostream>
using namespace std;

struct process
{
    int id;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int turnAroundTime;
    int waitingTime;
};

int main()
{
    int num, timeQuanta, count = 0, time = 0;
    cout << "Enter number of processes: ";
    cin >> num;
    cout << endl
    << "Enter time Quantum: ";
    cin >> timeQuanta;

    process p[num];
    for (int i = 0; i < num; i++)
    {
        p[i].id = i + 1;
        cout << "Enter Burst time for Process " << i + 1 << " :" << endl;
        cin >> p[i].burstTime;
        cout << "Enter Arrival Time for Process " << i + 1 << " :" << endl;
        cin >> p[i].arrivalTime;
    }

    while (count != num)
    {
        for (int i = 0; i < num; i++)
        {
            if (p[i].arrivalTime <= time)
            {
                if (p[i].burstTime > timeQuanta)
                {
                    time += timeQuanta;
                    p[i].burstTime -= timeQuanta;
                    
                }
                else if (p[i].burstTime <= timeQuanta && p[i].burstTime > 0)
                {
                    time += p[i].burstTime;
                    p[i].burstTime = 0;
                    p[i].completionTime = time;
                    p[i].turnAroundTime = p[i].completionTime - p[i].arrivalTime;
                    p[i].waitingTime = p[i].turnAroundTime - p[i].burstTime;

                    cout << "Process " << p[i].id << " completed at " << p[i].completionTime << endl;
                    cout << "Turn Around Time: " << p[i].turnAroundTime << endl;
                    cout << "Waiting Time: " << p[i].waitingTime << endl;
                    count++;
                }
            }
        }
    }

    return 0;
}
