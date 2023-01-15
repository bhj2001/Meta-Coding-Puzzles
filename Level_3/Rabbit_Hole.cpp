#include <bits/stdc++.h>

#define pb      push_back

#define NN       500005
using namespace std;
// Write any include statements here

vector<int> adj[NN], adj_rev[NN];

bool vis[NN];

vector<int> order, component;

void dfs0(int node) {
  vis[node] = true;
  for(auto it : adj[node]) {
    if(!vis[it]) {
      dfs0(it);
    }
  }
  order.pb(node);
}

int dp[NN];

void dfs1(int node) {
  vis[node] = true;
  component.pb(node);
  for(auto it : adj_rev[node]) {
    if(!vis[it]) {
      dfs1(it);
    }
  }
}

int dfs2(int node) {
  vis[node] = true;
  int maxi = 0;
  for(auto it : adj[node]) {
    if(!vis[it]) {
      maxi = max(maxi, dfs2(it));
    }
    maxi = max(maxi, dp[it]);
  }
  return maxi;
}

int getMaxVisitableWebpages(int N, int M, vector<int> A, vector<int> B) {
  // Write your code here
  for(int i = 0; i < M; i++) {
    adj[A[i]].pb(B[i]);
    adj_rev[B[i]].pb(A[i]);
  }
  memset(vis, 0, sizeof(vis));
  for(int i = 1; i <= N; i++) {
    if(!vis[i]) {
      dfs0(i);
    }
  }
  reverse(order.begin(), order.end());
  memset(vis, 0, sizeof(vis));
  memset(dp, 0, sizeof(dp));
  vector<vector<int>> comps;
  for(auto it : order) {
    if(!vis[it]) {
      component.clear();
      dfs1(it);
      comps.pb(component);
    }
  }
  memset(vis, 0, sizeof(vis));
  reverse(comps.begin(), comps.end());
  for(auto comp : comps) {
    int x = dfs2(comp[0]);
    x += comp.size();
    for(auto it : comp) {
      dp[it] = x;
    }
  }
  int maxi = 0;
  for(int i = 1; i <= N; i++) {
    maxi = max(maxi, dp[i]);
  }
  return maxi;
}
