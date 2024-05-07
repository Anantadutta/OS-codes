#include <iostream>
using namespace std;

struct process
{
    int id;
    int burstTime;
    int arrivalTime;
    int completionTime;
    int waitingTime;
    int turnAroundTime;
};

int main()
{
    int num, smallest;
    cout << "Enter number of Processes" << endl;
    cin >> num;
    process p[num];
    int time = 0;
    int count = 0;
    for (int i = 0; i < num; i++)
    {
        cout << "Enter burst time for process " << i + 1 << endl;
        cin >> p[i].burstTime;
        cout << "Enter arrival time for process " << i + 1 << endl;
        cin >> p[i].arrivalTime;
        p[i].id = i + 1;
    }
    for (time = 0; count !=num;time++){
        smallest = 9;
        for(int i=0; i < num; i++){
            if(p[i].arrivalTime<=time && p[i].burstTime<p[smallest].burstTime && p[i].burstTime>0 )
                smallest=i;
        }
        p[smallest].burstTime--;

        if (p[smallest].burstTime == 0)
        {
            count++;
            p[smallest].completionTime = time + 1;
            p[smallest].turnAroundTime = p[smallest].completionTime - p[smallest].arrivalTime;
            p[smallest].waitingTime = p[smallest].turnAroundTime - p[smallest].burstTime;
            cout << "Process " << p[smallest].id << " completed at time " << p[smallest].completionTime << endl
                 << "Waiting time: " << p[smallest].waitingTime << endl
                 << "Turn around time: " << p[smallest].turnAroundTime << endl;
        }
    }
    return 0;
}
