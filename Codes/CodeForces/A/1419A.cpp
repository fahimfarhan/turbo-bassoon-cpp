/*************************************************************************
  SPDX-License-Identifier: MIT
  Copyright (c) 2020 Qazi Fahim Farhan (@fahimfarhan)
  May the CodeForces be with you!
 ************************************************************************/
#include <iostream>
#include <climits>  // this includes INT_MIN, INT_MAX, ... ...
// #include <sstream>
// #include <cstdio>
// #include <cmath>
// #include <cstring>
// #include <cctype>
// #include <string>
#include <vector>
// #include <list>
// #include <set>
// #include <unordered_set>
// #include <map>
// #include <unordered_map>
// #include <queue>
// #include <stack>
#include <algorithm>
// #include <functional>
#include <iomanip>      // std::setprecision


using namespace std;

#define PI 2*acos(0)

//typedef long long int ll;
 #define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MOD = 1e9+7;

// int n,m;
vector<int> *g;
bool *isvisited;

void start() {}

void FastIO() {
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  /*
  std::cout << std::fixed;
  std::cout << std::setprecision(10);
  cout << num1 << endl;
  */
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  /*
---------- Interactive problems ---------

  on each interactive questions' end, add `cout.flush()`
  say, cout<<"some weirdo question";
  cout<<"\n"; // end of question
  cout.flush(); // <-- just like this

  if still confusing, check out 1363D.cpp
    
*/
}

int main(int argc, char const *argv[]){
  /* code */
  FastIO();

  ll T, n, m;
  vector<int> raze, breach;
  bool razeHasAtleastOneOdd = false;
    bool breachHasAtleastOneEven = false;
  string s;
  cin>>T;
  while(T--) {
    cin>>n;
    cin>>s;
    s = "#"+s;
    razeHasAtleastOneOdd = false;
    breachHasAtleastOneEven = false;
    for(int i=1; i<=n; i++) {
      m = s[i] - '0';
      if( (i&1) == 1) { 
        raze.push_back(m);   
        razeHasAtleastOneOdd = (razeHasAtleastOneOdd | ((m&1) == 1));  
      }
      else{ 
        breach.push_back(m);  
        breachHasAtleastOneEven = (breachHasAtleastOneEven | ((m&1) == 0));  
      }
    }
    if(raze.size() > breach.size()) {
      if(razeHasAtleastOneOdd) {  cout<<1<<"\n";  }
      else{ cout<<2<<"\n";  }
    }else{
      if(breachHasAtleastOneEven) {  cout<<2<<"\n";  }
      else{ cout<<1<<"\n";  }
    }
    raze.clear();
    breach.clear();
  }

  return 0;
}