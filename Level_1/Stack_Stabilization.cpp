#include <bits/stdc++.h>
using namespace std;
// Write any include statements here

int getMinimumDeflatedDiscCount(int N, vector<int> R) {
  // Write your code here
  int prev = 1e9 + 1;
  int cnt = 0;
  for(int i = N - 1; i >= 0; i--) {
    if(R[i] < prev) {
      prev = R[i];
    }
    else {
      cnt++;
      prev = prev - 1;
      if(prev == 0) {
        return -1;
      }
    }
  }
  return cnt;
}
