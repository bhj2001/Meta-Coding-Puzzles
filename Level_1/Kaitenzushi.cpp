#include <bits/stdc++.h>
using namespace std;
// Write any include statements here

int getMaximumEatenDishCount(int N, vector<int> D, int K) {
  // Write your code here
  map<int, int> ma;
  deque<int> dq;
  int cnt = 0;
  for(auto it : D) {
    if(!ma[it]) {
      dq.push_back(it);
      ma[it]++;
      cnt++;
      if(dq.size() > K) {
        int x = dq.front();
        ma[x]--;
        dq.pop_front();
      }
    }
  }
  return cnt;
}
