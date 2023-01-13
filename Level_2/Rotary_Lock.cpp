#include <bits/stdc++.h>
using namespace std;
// Write any include statements here

long long getMinCodeEntryTime(int N, int M, vector<int> C) {
  // Write your code here
  long long n = N;
  long long dp[M][M + 1];
  C.push_back(1);
  for(int i = 0; i < M; i++) {
    for(int j = 0; j <= M; j++) {
      dp[i][j] = 1e18;
    }
  }
  dp[0][M] = min(abs(1ll - C[0]), n - abs(1 - C[0]));
  for(int i = 1; i < M; i++) {
    for(int j = 0; j <= M; j++) {
      // i - 1, j
      long long a = C[i - 1], b = C[j], c = C[i];
      // i - 1, i
      // i, j
      // i3 j0
      dp[i][i - 1] = min(dp[i][i - 1], dp[i - 1][j] + min(abs(b - c), n - abs(b - c)));
      dp[i][j] = min(dp[i][j], dp[i - 1][j] + min(abs(a - c), n - abs(a - c)));
    }
  }
  long long mini = 1e18;
  for(int i = 0; i <= M; i++) {
    mini = min(mini, dp[M - 1][i]);
  }
  return mini;
}
