#include<stdio.h>
#include<stdbool.h>

int waitime(int p[],int n, int wt[],int q, int bt[]){
	int rem_bt[n],j,i;
	for(i=0;i<n;i++){
		rem_bt[i]=bt[i];
	}
	int t=0;
	while(1){
		bool done=true;
		for(j=0;j<n;j++){
			if(rem_bt[j]>0){
				done=false;
				if(rem_bt[j]>q){
					rem_bt[j]-=q;
					t+=q;				}
				else{
					t=t+rem_bt[j];
					wt[j]=t-bt[j];
					rem_bt[j]=0;
				}
			}
		}
		if (done==true){
			break;
		}
	}
	return 1;
}

int turntime(int p[],int n,int bt[],int wt[],int tat[]){
	int i;
	for(i=0;i<n;i++){
		tat[i]=bt[i]+wt[i];
	}
	return 1;
}
int avtime(int n,int p[],int bt[],int q){
	int i,wt[20],tat[20],totalwt=0,totat=0;
	float avgwt,avgtat;
	waitime(p,n,wt,q,bt);
	turntime(p,n,bt,wt,tat);
	for(i=0;i<n;i++){
		totalwt+=wt[i];
		totat+=tat[i];
		}
	printf("ProcessNumber\t BurstTime\t WaitingTime\t TurnaroundTime\n");
	for(i=0;i<n;i++){
		printf("%d\t\t %d\t\t %d\t\t %d\n",p[i],bt[i],wt[i],tat[i]);
	}
	avgwt=totalwt*1.0/n;
	avgtat=totat*1.0/n;
	printf("Average Waiting Time\n \t %f",avgwt);
	printf("Average Turnaround Time\n \t %f",avgtat);
	return 1;
}
int main(){
	int i,bt[20],p[20],n,q;
	printf("Enter number of processes   ");
	scanf("%d",&n);
	printf("Enter Burst Time");
	for(i=0;i<n;i++){
		printf("\n P[%d]",i+1);
		scanf("%d",&bt[i]);
		p[i]=i+1;
	}
	printf("Enter the quantum of round robin");
	scanf("\n %d",&q);
	avtime(n,p,bt,q);
	return 0;
}
