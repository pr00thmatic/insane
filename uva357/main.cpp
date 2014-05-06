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
#include<cstring>

#define MAXN 30001

using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<char> vc;
typedef pair<int,int> ii;
typedef pair<string,string> ss;

int main(){
  ll M[30001][5];
  int c[5] = {1, 5, 10, 25, 50};

  for(int i=0; i<MAXN; i++) {
    M[i][0] = 1;
  }

  for(int i=0; i<5; i++) 
    M[0][i] = 1;
  
  for(int i=1; i<5; i++) {
    for(int j=1; j<30001; j++) {
      if(c[i] <= j) {
	M[j][i] = M[j-c[i]][i] + M[j][i-1];
      } else {
	M[j][i] = M[j][i-1];
      }

    }
  }
  
  int n;

  while(scanf("%d", &n) != EOF) {
    if(M[n][4] == 1)
      printf("There is only %lld way to produce %d cents change.\n", M[n][4], n);
    else
      printf("There are %lld ways to produce %d cents change.\n", M[n][4], n);
  }
}

