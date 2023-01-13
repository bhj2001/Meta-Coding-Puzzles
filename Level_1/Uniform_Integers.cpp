#include <bits/stdc++.h>
using namespace std;
// Write any include statements here

long long func(int d, int num) {
  long long ans = 0, base = 1;
  while(num--) {
    ans += base * d;
    base *= 10;
  }
  return ans;
}

int getUniformIntegerCountInInterval(long long A, long long B) {
  // Write your code here
  int cnt = 0;
  for(int d = 1; d <= 9; d++) {
    for(int num = 1; num <= 15; num++) {
      long long x = func(d, num);
      if(A <= x && x <= B) {
        cnt++;
      }
    }
  }
  return cnt;
}
