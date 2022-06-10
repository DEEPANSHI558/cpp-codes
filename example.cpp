#include <algorithm>
#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <unordered_map>
using namespace std;

struct Process {
  string id;
  int setTime;
  int arriveTime, burstTime, waitingTime, responseTime, turnAroundTime, lastRun;

  Process(string id, int arriveTime, int burstTime, int waitingTime = 0,
          int responseTime = 0, int turnAroundTime = 0, int lastRun = 0)
      : id(id),
        arriveTime(arriveTime),
        burstTime(burstTime),
        waitingTime(waitingTime),
        turnAroundTime(turnAroundTime),
        responseTime(responseTime),
        lastRun(arriveTime),
        setTime(burstTime) {}
};

struct comp {
  bool operator()(Process p1, Process p2) {
    if (p1.burstTime == p2.burstTime) return false;
    return p1.burstTime > p2.burstTime;
  }
};

struct compSet {
  bool operator()(Process p1, Process p2) const {
    if (p1.burstTime == p2.burstTime) return p1.arriveTime < p2.arriveTime;
    return p1.burstTime < p2.burstTime;
  }
};
bool arriveSort(Process p1, Process p2) {
  if (p1.arriveTime == p2.arriveTime) return p1.burstTime < p2.burstTime;
  return p1.arriveTime < p2.arriveTime;
}


vector<Process> preEmptive(vector<Process> input) {
  // priorituQueue for currently running processes
  priority_queue<Process, vector<Process>, comp> processQueue;
  // utility map for mapping arriveTime with process's name
  unordered_map<int, multiset<Process, compSet>> processes;
  vector<Process> table;  // table to update after each process finishes
  for (auto x : input) {
    processes[x.arriveTime].insert(x);
  }
  int time = 0;

  while (!processes.empty() || !processQueue.empty()) {
    if (processes.find(time) != processes.end()) {
      for (auto x : processes[time]) processQueue.push(x);

      processes.erase(time);
    }

    if (processQueue.empty()) {
      time++;
      continue;
    }
    Process process = processQueue.top();
    process.burstTime--;
    process.waitingTime += (time - process.lastRun);
    process.lastRun = time + 1;
    time++;
    processQueue.pop();

    if (process.burstTime == 0) {
      table.push_back(process);
      continue;
    }
    processQueue.push(process);
  }

  for (auto& process : table) {  // output final table
    process.turnAroundTime = process.setTime + process.waitingTime;
  }
  return table;
}

vector<Process> nonPreEmptive(vector<Process> input) {
  vector<Process> table;
  list<Process> queue;
  priority_queue<Process, vector<Process>, comp> processQueue;
  int t = 0;
  for (auto x : input) queue.push_back(x);
  while (!queue.empty() || !processQueue.empty()) {
    while (queue.front().arriveTime <= t) {
      Process process = queue.front();
      queue.pop_front();
      processQueue.push(process);
    }
    if (!processQueue.empty()) {
      Process process = processQueue.top();
      process.waitingTime = t - process.arriveTime;
      process.turnAroundTime = process.waitingTime + process.setTime;
      t += process.burstTime;
      table.push_back(process);
      processQueue.pop();
      continue;
    }
    t++;
  }
  return table;
}

int main() {
  vector<Process> input;
  int n;
  cout << "enter number of processes ";
  cin >> n;
  cout << "enter process name, arrive time, burst time\n";
  for (int i = 0; i < n; i++) {  // input n processes
    string id;
    int arriveTime, burstTime;

    cin >> id >> arriveTime >> burstTime;
    Process process(id, arriveTime, burstTime);
    input.push_back(process);
  }
  sort(input.begin(), input.end(), arriveSort);
  vector<Process> table;
  cout << "Enter the scheduling mechanism\n1.non-PreEmptive\n2.preEmptive\n";
  int c;
  cin >> c;
  switch (c) {
    case 1:
      table = nonPreEmptive(input);
      break;
    case 2:
      table = preEmptive(input);
      break;
    default:
      cout << "Invalid";
      exit(-1);
  }

  int wait = 0, tat = 0;
  for (auto x : table) {
    wait += x.waitingTime;
    tat += x.turnAroundTime;
  }

  for (auto process : table) {
    cout << process.id << "->waiting time: " << process.waitingTime
         << " turnaround time: " << process.turnAroundTime << "\n";
  }
  cout << "average wait time: " << 1.0 * wait / n
       << "\naverage turnaround time: " << 1.0 * tat / n << endl;
}