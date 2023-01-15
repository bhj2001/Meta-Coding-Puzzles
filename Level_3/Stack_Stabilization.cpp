#include <bits/stdc++.h>

#define F       first
#define S       second
#define ll      long long
using namespace std;
// Write any include statements here

long long getMinimumSecondsRequired(int N, vector<int> R, int A, int B) {
  // Write your code here
  map<int, int> ma;
  for(auto x : R) {
    for(int i = -50; i <= 50; i++) {
      if(x + i >= 1) ma[x + i] = 1;
    }
  }
  int cnt = 1;
  for(auto it : ma) {
    ma[it.F] = cnt++;
  }
  ll int points[cnt];
  for(auto it : ma) {
    points[it.S] = it.F;
  }
  ll int dp[N + 1][cnt];
  for(int i = 0; i <= N; i++) {
    for(int j = 0; j < cnt; j++) {
      dp[i][j] = 1e18;
    }
  }
  for(int j = 0; j < cnt; j++) {
    dp[N][j] = 0;
  }
  ll int a = A, b = B;
  for(int i = N - 1; i >= 0; i--) {
    for(int j = 1; j < cnt; j++) {
      for(int k = 1; k < cnt; k++) {
        if(points[j] < points[k]) {
          ll int cost = dp[i + 1][k];
          if(R[i] <= points[j]) {
            cost += a * (points[j] - R[i]);
          }
          else {
            cost += b * (R[i] - points[j]);
          }
          dp[i][j] = min(dp[i][j], cost);
        }
      }
    }
  }
  ll int mini = 1e18;
  for(int i = 1; i < cnt; i++) {
    mini = min(mini, dp[0][i]);
  }
  return mini;
}
