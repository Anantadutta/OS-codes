#include<stdio.h>
void main(){
	int p[20], bt[20], wt[20], tat[20], total=0, i, j, n, temp, pos;
	float avg_wt, avg_tat;
	
	printf("Enter total no. of processes (max -> 20):");
	scanf("%d", &n);
	
	printf("\n Enter Process Burst Time\n");
	for(i=0; i<n; i++){
		printf("P[%d]: ",i+1);
		scanf("%d", &bt[i]);
		p[i]=i+1;  
	}
	for(i=0; i<n; i++){
		pos=i;
		for(j=i+1; j<n; j++){
			if(bt[j]<bt[pos])
				pos=j;
		}
		
	
		temp = bt[i];
		bt[i] = bt[pos];
		bt[pos] = temp;
		
		temp = p[i];
		p[i] = p[pos];
		p[pos] = temp; 
	}
	
	wt[0]=0;
	
	for(i=1; i<n; i++){
		wt[i]=0;
		for(j=0; j<i; j++)
			wt[i]+=bt[j];
		
		total+=wt[i];
	}
	avg_wt=(float)total/n;
	total=0;

	printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time");
	for(i=0; i<n; i++){
		tat[i] = bt[i] + wt[i];
		total+=tat[i];
		printf("\nP[%d]\t%d\t\t%d\t\t%d",p[i], bt[i], wt[i], tat[i]);
	}
	
	avg_tat=(float)total/n;
	printf("\n Average Waiting Time: %f",avg_wt);
	printf("\n Average Turnaround Time: %f",avg_tat);
}
