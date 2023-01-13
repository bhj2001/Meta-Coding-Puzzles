#include <bits/stdc++.h>
#define INF   1e18
#define lli   long long

using namespace std;
// Write any include statements here
struct cht{
    struct Line{
	   lli a;
	   lli b;
	   lli val;
	   double xLeft;
	   bool type;
	   Line(lli _a = 0 , lli _b = 0){
		  a = _a;
		  b = _b;
		  xLeft = -INF;
		  type = 0;
		  val = 0;
	   }
	   lli valueAt(lli x) const{
		  return 1LL * a * x + b;
	   }
	   friend bool areParallel(const Line &l1, const Line &l2){
		  return l1.a == l2.a;
	   }
	   friend double intersectX(const Line &l1 , const Line &l2){
		  return areParallel(l1 , l2) ? INF : (l2.b - l1.b) / (double) (l1.a - l2.a);
	   }
	   bool operator < (const Line &l2) const{
		  if(!l2.type)
			 return a < l2.a;
		  return xLeft > l2.val;
	   }
    };
    set < Line >  hull;
    void init(){
    	hull.clear();
    }
    bool hasPrev(set < Line > :: iterator it){
	   return it != hull.begin();
    }
    bool hasNext(set < Line > :: iterator it){
	   return it != hull.end() && next(it) != hull.end();
    }
    bool irrelevant(const Line &l1 , const Line &l2 , const Line &l3){
	   return intersectX(l1,l3) <= intersectX(l1,l2);
    }
    bool irrelevant(set < Line > :: iterator it){
	   return hasPrev(it) && hasNext(it) && (irrelevant(*next(it) , *it , *prev(it)));
    }
    set < Line > :: iterator updateLeftBorder(set < Line > :: iterator it){
	   if(!hasNext(it)){
		  return it;
	   }
	   double val = intersectX(*it , *next(it));
	   Line buf(*it);
	   it = hull.erase(it);
	   buf.xLeft = val;
	   it = hull.insert(it, buf);
	   return it;
    }
    void addLine(lli a , lli b){
        // dbg("add",a,b);
	   Line l3 = Line(a, b);
	   auto it = hull.lower_bound(l3);
	   if(it != hull.end() && areParallel(*it , l3)){
		  if(it -> b > b){
			 it = hull.erase(it);
		  }
		  else{
			 return;
		  }
	   }
	   it = hull.insert(it, l3);
	   if(irrelevant(it)){
		  hull.erase(it);
		  return;
	   }
	   while(hasPrev(it) && irrelevant(prev(it))){
		  hull.erase(prev(it));
	   }
	   while(hasNext(it) && irrelevant(next(it))){
		  hull.erase(next(it));
	   }
	   it = updateLeftBorder(it);
	   if(hasPrev(it)){
		  updateLeftBorder(prev(it));
	   }
	   if(hasNext(it)){
		  updateLeftBorder(next(it));
	   }
    }
    lli getBest(lli x){
        // assert(!hull.empty());
        if(hull.empty())
            return INF;
	   Line q;
	   q.val = x;
	   q.type = 1;
	   auto bestLine = hull.lower_bound(q);
	   if(bestLine == hull.end()){
		  return INF;
	   }
	   return bestLine -> valueAt(x);
    }
};

double getMaxDamageDealt(int N, vector<int> H, vector<int> D, int B) {
  // Write your code here
  cht hull1;
  lli maxi = 0;
  for(int i = 0; i < N; i++) {
    lli h = H[i];
    lli d = D[i];
    maxi = max(maxi, h * d - hull1.getBest(d));
    hull1.addLine(-h, -h * d);
  }
  cht hull2;
  for(int i = N - 1; i >= 0; i--) {
    lli h = H[i];
    lli d = D[i];
    maxi = max(maxi, h * d - hull2.getBest(d));
    hull2.addLine(-h, -h * d);
  }
  double ans = (maxi * 1.0) / (1.0 * B);
  return ans;
}
