#include <bits/stdc++.h>

#define F     first
#define S     second
#define pii   pair<int, int>

using namespace std;
// Write any include statements here

bool isportal(char c) {
  return ('a' <= c && c <= 'z');
}

int n, m;

bool isvalid(pii p) {
  return (0 <= p.F && p.F < n && 0 <= p.S && p.S < m);
}

int getSecondsRequired(int R, int C, vector<vector<char>> G) {
  // Write your code here
  n = R, m = C;
  vector<vector<int>> dist(n, vector<int>(m, 1e9));
  vector<vector<bool>> vis(n, vector<bool>(m, false));
  map<char, vector<pii>> ma;
  queue<pii> q;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(isportal(G[i][j])) {
        ma[G[i][j]].push_back({i, j});
      }
      if(G[i][j] == 'S') {
        q.push({i, j});
        dist[i][j] = 0;
        vis[i][j] = true;
      }
    }
  }
  while(!q.empty()) {
    pii node = q.front();
    q.pop();
    if(isvalid({node.F + 1, node.S}) && G[node.F + 1][node.S] != '#' && !vis[node.F + 1][node.S]) {
      q.push({node.F + 1, node.S});
      dist[node.F + 1][node.S] = 1 + dist[node.F][node.S];
      vis[node.F + 1][node.S] = true;
    }
    if(isvalid({node.F - 1, node.S}) && G[node.F - 1][node.S] != '#' && !vis[node.F - 1][node.S]) {
      q.push({node.F - 1, node.S});
      dist[node.F - 1][node.S] = 1 + dist[node.F][node.S];
      vis[node.F - 1][node.S] = true;
    }
    if(isvalid({node.F, node.S + 1}) && G[node.F][node.S + 1] != '#' && !vis[node.F][node.S + 1]) {
      q.push({node.F, node.S + 1});
      dist[node.F][node.S + 1] = 1 + dist[node.F][node.S];
      vis[node.F][node.S + 1] = true;
    }
    if(isvalid({node.F, node.S - 1}) && G[node.F][node.S - 1] != '#' && !vis[node.F][node.S - 1]) {
      q.push({node.F, node.S - 1});
      dist[node.F][node.S - 1] = 1 + dist[node.F][node.S];
      vis[node.F][node.S - 1] = true;
    }
    for(auto it : ma[G[node.F][node.S]]) {
      if(!vis[it.F][it.S]) {
        q.push(it);
        dist[it.F][it.S] = 1 + dist[node.F][node.S];
        vis[it.F][it.S] = true;
      }
    }
  }
    
  int mini = 1e9;
  for(int i =0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(G[i][j] == 'E') mini = min(mini, dist[i][j]);
    }
  }
  if(mini == 1e9) mini = -1;
  return mini;
}
