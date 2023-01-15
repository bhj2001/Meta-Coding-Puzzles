#include <bits/stdc++.h>
using namespace std;
// Write any include statements here

bool is_possible(int x, int num1, int num2, int num3) {
  if(x == 0) {
    return true;
  }
  if(x == 1) {
    return num1 != 0;
  }
  if(x == 2) {
    return (num2 != 0) || (num1 >= 2);
  }
  if(x == 3) {
    return (num3 != 0) || (num1 != 0 && num2 != 0);
  }
  if(x % 3 == 0 && num3 >= x / 3) return true;
  if(num1 != 0 && x - 1 >= 0 && is_possible(x - 1, num1 - 1, num2, num3)) return true; 
  if(num2 != 0 && x - 2 >= 0 && is_possible(x - 2, num1, num2 - 1, num3)) return true; 
  return false;
}

int getMinProblemCount(int N, vector<int> S) {
  // Write your code here
  int mini = 1e9;
  sort(S.begin(), S.end());
  int maxi = S.back() / 3;
  for(int num1 = 0; num1 <= 2; num1++) {
    for(int num2 = 0; num2 <= 2; num2++) {
      for(int num3 = max(0, maxi - 2); num3 <= maxi; num3++) {
        bool isok = true;
        for(auto it : S) {
          if(!is_possible(it, num1, num2, num3)) {
            isok = false;
          }
        }
        if(isok) {
          mini = min(mini, num1 + num2 + num3);
        }
      }
    }
  }
  return mini;
}
