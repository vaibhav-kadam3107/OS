#include<iostream>
using namespace std;

void waiting_time(int processes[] , int n , int burst_time[] , int wt[]){
    wt[0] = 0;
    for (int i = 1; i < n; i++)
    {
        wt[i] = burst_time[i-1] + wt[i-1];
    }
    
}

void turn_around_time(int processes[] , int n , int burst_time[] , int tat[] , int wt[]){
    for (int i = 0; i < n; i++)
    {
        tat[i] = burst_time[i] + wt[i];
    }
    
}

void fcfs(int processes[] , int n , int burst_time[]){
    int wt[n] , tat[n] , total_wt = 0 , total_tat = 0;

    waiting_time(processes , n , burst_time , wt);

    turn_around_time(processes , n , burst_time , tat , wt);  

    printf("processes \t\t wt \t\t tat\n");
    for (int i = 0; i < n; i++)
    {
        total_tat += tat[i]; 
        total_wt += wt[i];
        cout<< "  " << i+1 << "\t\t" << burst_time[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << "\t\t"<<endl;
    }
    cout<<"average waiting time :"<< (float)total_wt/(float)n <<endl;
    cout<<"average tat time :"<< (float)total_tat/(float)n<<endl;
}

int main(){
    int processes[] = { 1 , 2 , 3 , 4 };
    int n = sizeof processes / sizeof processes[0];
    int burst_time[] = { 2 , 2 , 3 , 4};

    fcfs(processes , n , burst_time);
    return 0;
}