//#define NDEBUG

#include<string>
#include<queue>
#include<math.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
#include<fstream>
#include<assert.h>
#include<set>
#include<map>
#include<cstdio>

using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<char> vc;
typedef pair<int,int> ii;
typedef pair<string,string> ss;

int localBest(vector<int> V) {
  vector<int> B(V.size());

  B[0] = V[0];
  B[1] = V[1];

  for(int i=2; i<V.size(); i++) {
    V[i] = max(V[i]+V[i-2], V[i]+V[i-3]);
  }

  return max(V[V.size()-1], V[V.size()-2]);
}

int main(){
  while(true) {
    int n, m;
    cin >> n >> m;

    if(!n && !m)
      return 0;

    vector<vi> candy(n, vi(m));
  
    for(int i=0; i<n; i++) {
      for(int j=0; j<m; j++) {
	cin >> candy[i][j];
      }
    }

    vi lb(n);
  
    for(int i=0; i<n; i++) {
      lb[i] = localBest(candy[i]);
    }

    cout << localBest(lb) << endl; 
  }
    
}

