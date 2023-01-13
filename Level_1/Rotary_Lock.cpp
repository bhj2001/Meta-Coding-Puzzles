#include <bits/stdc++.h>
using namespace std;
// Write any include statements here

long long getMinCodeEntryTime(int N, int M, vector<int> C) {
  // Write your code here
  long long pos = 1;
  long long ans = 0;
  for(auto it : C) {
    ans += min(abs(it - pos), N - abs(it - pos));
    pos = it;
  }
  return ans;
}
