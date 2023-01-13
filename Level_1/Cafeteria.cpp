#include <bits/stdc++.h>
using namespace std;
// Write any include statements here

long long getMaxAdditionalDinersCount(long long N, long long K, int M, vector<long long> S) {
  // Write your code here
  long long ans = 0;
  sort(S.begin(), S.end());
  ans += (S[0] - 1) / (K + 1);
  ans += (N - S[M - 1]) / (K + 1);
  for(int i = 0; i + 1 < M; i++) {
    ans += (S[i + 1] - S[i] - K - 1) / (K + 1);
  }
  return ans;
}


