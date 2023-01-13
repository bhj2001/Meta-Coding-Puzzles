#include <bits/stdc++.h>
using namespace std;
// Write any include statements here

void dfs(int node, vector<bool> &vis, vector<int> &dp, vector<int> &L) {
  vis[node] = true;
  if(!vis[L[node]]) {
    dfs(L[node], vis, dp, L);
  }
  dp[node] = 1 + dp[L[node]];
}

int getMaxVisitableWebpages(int N, vector<int> L) {
  // Write your code here
  for(int i = 0; i < N; i++) {
    L[i]--;
  }
  vector<int> deg(N, 0);
  for(auto it : L) {
    deg[it]++;
  }
  vector<bool> iscycle(N, true);
  queue<int> q;
  for(int i = 0; i < N; i++) {
    if(deg[i] == 0) {
      q.push(i);
    }
  }
  while(!q.empty()) {
    int node = q.front();
    q.pop();
    iscycle[node] = false;
    deg[L[node]]--;
    if(deg[L[node]] == 0) {
      q.push(L[node]);
    }
  }
  vector<bool> vis(N, false);
  vector<int> dp(N, 0);
  for(int i = 0; i < N; i++) {
    if(iscycle[i] && !vis[i]) {
      int ptr = i;
      vector<int> v;
      v.push_back(i);
      ptr = L[i];
      while(ptr != i) {
        v.push_back(ptr);
        ptr = L[ptr];
      }
      for(auto it : v) {
        vis[it] = true;
        dp[it] = v.size();
      }
    }
  }
  for(int i = 0; i < N; i++) {
    cout << dp[i] << " ";
  }
  cout << endl;
  for(int i = 0; i < N; i++) {
    if(!vis[i]) dfs(i, vis, dp, L);
  }
  sort(dp.begin(), dp.end());
  return dp.back();
}
