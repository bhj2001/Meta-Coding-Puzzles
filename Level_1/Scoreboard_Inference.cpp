#include <bits/stdc++.h>
using namespace std;
// Write any include statements here

int getMinProblemCount(int N, vector<int> S) {
  // Write your code here
  bool isodd = false;
  int maxi = 0;
  for(auto it : S) {
    if(it % 2 == 1) {
      isodd = true;
    }
    maxi = max(maxi, it);
  }
  if(!isodd) {
    return maxi / 2;
  }
  else {
    return 1 + (maxi / 2);
  }
}
