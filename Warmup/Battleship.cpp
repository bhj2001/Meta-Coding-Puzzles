#include <bits/stdc++.h>
using namespace std;
// Write any include statements here

double getHitProbability(int R, int C, vector<vector<int>> G) {
  // Write your code here
  double num = 0;
  double den = R * C;
  for(auto vec : G) {
    for(auto it : vec) {
      num += it;
    }
  }
  double ans = num / den;
  return ans;
}
