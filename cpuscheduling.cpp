#include<iostream>
using namespace std;
struct abc{
    int arrival_time;
    int burst_time;
    int start;
    int end;
    abc(){
        arrival_time=0;
        burst_time=0;
        start=0;
        end=0;
    }
};

int main(){
    int n;
    cout<<"Enter the number of processes";
    cin>>n;
    abc *ans=new abc[n];
    cout<<"Enter the arrival time and the burst time of the following processes"<<endl;
    for(int i=0;i<n;i++){
        int arrivalTime,burstTime;
        cin>>arrivalTime>>burstTime;
        ans[i].arrival_time=arrivalTime;
        ans[i].burst_time=burstTime;
    }
    int waitingTime=0;
    int tat=0;
    ans[0].start=ans[0].arrival_time;
    ans[0].end=ans[0].start+ans[0].burst_time;
    for(int i=1;i<n;i++){
        ans[i].start=ans[i-1].end;
        ans[i].end=ans[i].start+ans[i].burst_time;
    }
    for(int i=0;i<n;i++){
        waitingTime+=(ans[i].start-ans[i].arrival_time);
        tat+=(ans[i].end-ans[i].arrival_time);
    }
    cout<<"average waiting time :"<<(float)waitingTime/n<<endl;
    cout<<"Average turnAround Time"<<(float)tat/n<<endl;
    return 0;
        



       
}