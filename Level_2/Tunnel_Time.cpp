#include <bits/stdc++.h>

#define F     first
#define S     second

using namespace std;
// Write any include statements here

long long getSecondsElapsed(long long C, int N, vector<long long> A, vector<long long> B, long long K) {
  // Write your code here
  long long low = 0, high = 1e18;
  long long ans = -1;
  vector<pair<long long, long long>> v;
  for(int i = 0; i < N; i++) {
    v.push_back({A[i], B[i]});
  }
  sort(v.begin(), v.end());
  long long ttt = 0;
  for(auto it : v) {
    ttt += (it.S - it.F);
  }
  while(low <= high) {
    long long mid = (low + high) / 2;
    long long complete = mid / C;
    long long tt = complete * ttt;
    long long timeleft = mid % C;
    for(auto it : v) {
      long long l = min(it.F, timeleft);
      long long r = min(it.S, timeleft);
      tt += (r - l);
    }
    if(tt >= K) {
      ans = mid;
      high = mid - 1;
    }
    else {
      low = mid + 1;
    }
  }
  return ans;
}
