#include <bits/stdc++.h>
using namespace std;
// Write any include statements here

double getMaxExpectedProfit(int N, vector<int> V, int C, double S) {
  // Write your code here
  double dp[N + 1];
  dp[0] = 0;
  for(int i = 1; i <= N; i++) {
    double sm = 0, prob = 1;
    dp[i] = 0;
    for(int j = i; j >= 1; j--) {
      sm += V[j - 1] * prob;
      dp[i] = max(dp[i], dp[j - 1] + sm - C);
      prob = prob * (1 - S);
    }
  }
  double maxi = 0;
  for(int i = 1; i <= N; i++) {
    maxi = max(maxi, dp[i]);
  }
  return maxi;
}

