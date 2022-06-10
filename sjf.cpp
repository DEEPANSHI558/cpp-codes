#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<list>
#include<set>
using namespace std;
struct Process{
    string process_id;
    int arrivalTime, burstTime,responseTime,waitingTime,turnAroundTime,lastRun,setTime,priority;
    Process(string id,int aTime, int bTime,int r=0, int w=0, int t=0,int l=0,int p=0)
    :process_id(id),arrivalTime(aTime),burstTime(bTime),responseTime(r),waitingTime(w),turnAroundTime(t),lastRun(l),setTime(bTime),priority(p){};
};
struct CompareBurstTime {
    public:
    bool operator()(Process p1, Process  p2)
    {
        if(p1.burstTime==p2.burstTime) return false;
        return p1.burstTime < p2.burstTime;
    }
};
bool arriveSort(Process p1,Process p2){
    if(p1.arrivalTime==p2.arrivalTime)return p1.burstTime < p2.burstTime;
    return p1.arrivalTime<p2.arrivalTime;
}
struct compset{
    bool operator()(Process p1,Process p2)const{
    if(p1.burstTime==p2.burstTime)
        return p1.arrivalTime<p2.arrivalTime;
    return p1.burstTime<p2.burstTime;
    }
};
bool priority(Process p1,Process p2){
    if(p1.priority==p2.priority){
        return p1.arrivalTime<p2.arrivalTime;
    }
    return p1.priority>p2.priority;
}
vector<Process> preemptive(vector<Process> input){
     // we have to sort on the basis of arrival time 
    sort(input.begin(),input.end(),arriveSort);
    // now enter the processes according to arrival time and then save their waitng time and arival time in a different data structure so that it can store 
    priority_queue<Process, vector<Process>, CompareBurstTime > pqueue;
    // we have to enter the processes and then compare it with the remaining processes and with the least burstTime every time till the priority queue is empty
    unordered_map <int,multiset<Process,compset>>processes;
    vector<Process>ans;
    // first we have to fill the processes
    for(auto d:input){
        processes[d.arrivalTime].insert(d);
    }
    int time=0;
    while(!processes.empty()||!pqueue.empty()){
        if(processes.find(time)!=processes.end()){
            for(auto d:processes[time]){
                        pqueue.push(d);
            }
            processes.erase(time);
        }
        if(pqueue.empty()){
            time++;
            continue;
        }
        Process p=pqueue.top();
        p.waitingTime+=(time-p.lastRun);
        p.lastRun=time+1;
        p.burstTime--;
        time++;
        pqueue.pop();
        if(p.burstTime==0){
              ans.push_back(p);
              continue;
        }
        pqueue.push(p);
    }
      for (auto& process : ans) { 
    process.turnAroundTime = process.setTime + process.waitingTime;
  }
    return ans;
}

vector<Process> non_preemptive(vector<Process>input){ 
    priority_queue<Process,vector<Process>,CompareBurstTime>processQueue;
    vector<Process>table;
    // first we have to sort on the basis of arrivetime;
    sort(input.begin(),input.end(),arriveSort);
    list<Process>queue;
    for(auto d:input){
        queue.push_back(d);
    }
    int time=0;
    int lastRun=0;
    while(!queue.empty()||!processQueue.empty()){
         while(queue.front().arrivalTime<=time){
             Process process = queue.front();
            queue.pop_front();
             processQueue.push(process);
         }
         if(!processQueue.empty()){
             Process p=processQueue.top();
             p.waitingTime=(lastRun-p.arrivalTime);
             p.turnAroundTime=(p.waitingTime+p.burstTime);
             lastRun+=p.burstTime;
             table.push_back(p);
             processQueue.pop();
             continue;
         }
         time++;
    }
    return table;

    
     
}
vector<Process>priority_sceduling(vector<Process> input){
    sort(input.begin(),input.end(),priority);
    vector<Process> table;
    int lastRun=0;
    for( auto x:input){
        x.waitingTime=lastRun-x.arrivalTime;
        lastRun+=x.burstTime;
        x.turnAroundTime=x.waitingTime+x.burstTime;
        table.push_back(x);
    }
    return table;
}
int  main(){
    // enter the processes
    vector<Process>input;
    int n;
    cout<<"enter the number of processes";
    cin>>n;
    cout<<"Enter the processes";
    for(int i=0;i<n;i++){
        string p;
        int arrival,burst,priority;
        cin>>p>>arrival>>burst>>priority;
        Process process(p,arrival,burst);
        input.push_back(process);
    }
    int c;
    cout<<"Enter your choice \n1)for Pre-emptive 2)Non-pre-emptive";
    cin>>c;
    vector<Process> table;
    switch(c){
        case 1:table=preemptive(input);
               break;
        case 2:table=non_preemptive(input);
               break;
        case 3:table=priority_sceduling(input);
               break;
        default:cout<<"Wrong choice";              
    }
    cout<<"average avaiting time";
    int answ=0;
    int anst=0;
    for(auto s:table){
          answ+=s.waitingTime;
          anst+=(s.turnAroundTime);
    }
    for (auto process : table) {
    cout << process.process_id << "->waiting time: " << process.waitingTime
         << " turnaround time: " << process.turnAroundTime << "\n";
  }
  cout << "average wait time: " << 1.0 * answ/ n
       << "\naverage turnaround time: " << 1.0 * anst/ n << endl;
 


    return 0;
}