#include <bits/stdc++.h>
using namespace std;
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL)
#define ll long long int

struct Student {
  string student_id;
  float percentage;
  int c1, c2, c3;
  Student(string _student_id, float _percentage, int _c1, int _c2, int _c3)
      : student_id(_student_id),
        percentage(_percentage),
        c1(_c1),
        c2(_c2),
        c3(_c3){};
};
class comp {
 public:
  bool operator()(Student s1, Student s2) {
    if (s1.percentage == s2.percentage) return s1.student_id < s2.student_id;
    return s1.percentage > s2.percentage;
  }
};

int main() {
  int c, s;
  cin >> c >> s;
  priority_queue<Student, vector<Student>, comp> si;
  vector<int> college;
  for (int i = 0; i < c; i++) {
    int t;
    cin >> t;
    college.push_back(t);
    for (int i = 0; i < s; i++) {
      string student_id, _c1, _c2, _c3;
      float percentage;
      cin >> student_id >> percentage >> _c1 >> _c2 >> _c3;
      int choice1 = stoi(_c1.substr(2));
      int choice2 = stoi(_c2.substr(2));
      int choice3 = stoi(_c3.substr(2));
      Student st(student_id, percentage, choice1, choice2, choice3);
      si.push(st);
    }
  }
  while (!si.empty()) {
    cout << si.top().student_id << " " << si.top().percentage << endl;
    si.pop();
  }
}