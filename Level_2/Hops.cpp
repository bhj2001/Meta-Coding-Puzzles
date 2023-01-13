#include <bits/stdc++.h>
using namespace std;
// Write any include statements here

long long getSecondsRequired(long long N, int F, vector<long long> P) {
  // Write your code here
  long long mini = 1e18;
  for(auto it : P) {
    mini = min(mini, it);
  }
  return N - mini;
}
