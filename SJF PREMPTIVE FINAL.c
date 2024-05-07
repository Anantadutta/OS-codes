#include<iostream>
using namespace std;

struct Process{
    int pid;
    int arrivaltime;
    int bursttime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
};
void findsjf(Process proc[],int n){
    int remainingTime[n];
    for(int i=0;i<n;i++){
        remainingTime[i]=proc[i].bursttime;
    }
    int currenttime=99999999;
    int complete=0;
    int shortest=0;
    int last=-1;
    int minBurst=9999;
    for(int i=0;i<n;i++){
    	if (proc[i].arrivaltime<currenttime){
			currenttime=proc[i].arrivaltime;
		}
    	}
    while(complete<n){
        minBurst=9999;
        for(int i=0;i<n;i++){
            if(proc[i].arrivaltime<=currenttime&&remainingTime[i]<minBurst&&remainingTime[i]>0&&i!=last){
                minBurst=remainingTime[i];
                shortest=i;
                
            }
        }
            remainingTime[shortest]--;
            if(remainingTime[shortest]==0){
                complete++;
                proc[shortest].completionTime=currenttime+1;
                proc[shortest].turnaroundTime=proc[shortest].completionTime-proc[shortest].arrivaltime;
                proc[shortest].waitingTime=proc[shortest].turnaroundTime-proc[shortest].bursttime;  
				last=shortest;  
            }
            currenttime++;
        }
    }

void displayProcess(Process proc[],int n){
    cout<<"Process\tArrivalTime\tBurstTime\tCompletionTime\tTurnaroundTime\tWaitingTime"<<endl;
    for(int i=0;i<n;i++){
        cout<<proc[i].pid<<"\t\t"<<proc[i].arrivaltime<<"\t\t"<<proc[i].bursttime<<"\t\t"<<proc[i].completionTime<<"\t\t"<<proc[i].turnaroundTime<<"\t\t"<<proc[i].waitingTime<<endl;
    }
    cout<<endl;
}
int main(){
    int n;
    cin>>n;
    Process proc[n];
    cout<<"Enter pid, arrival time and burst time of processes"<<endl;
    for(int i=0;i<n;i++){
        cout<<"enter process"<<i+1<<endl;
        cin>>proc[i].pid>>proc[i].arrivaltime>>proc[i].bursttime;
    }
        findsjf(proc,n);
        displayProcess(proc,n);

        return 0;
}
