#include <bits/stdc++.h>
using namespace std;
// Write any include statements here

int getArtisticPhotographCount(int N, string C, int X, int Y) {
  // Write your code here
  C = "*" + C;
  int P[N + 1], B[N + 1];
  P[0] = B[0] = 0;
  for(int i = 1; i <= N; i++) {
    P[i] = P[i - 1] + (C[i] == 'P');
    B[i] = B[i - 1] + (C[i] == 'B');
  }
  int cnt = 0;
  for(int i = 1; i <= N; i++) {
    if(C[i] != 'A') continue;
    int nump = (P[max(0, i - X)] - P[max(0, i - Y - 1)]) * (B[min(N, i + Y)] - B[min(N, i + X - 1)]);
    int numb = (B[max(0, i - X)] - B[max(0, i - Y - 1)]) * (P[min(N, i + Y)] - P[min(N, i + X - 1)]);
    cnt += nump + numb;
  }
  return cnt;
}
