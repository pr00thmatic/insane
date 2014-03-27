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

int main(){
      ll cases = 0;

      while(true) {
	    int nc, indexCounter = 0;
	    set<ii> nodeScheduler;

	    scanf("%d", &nc);
	    
	    if(!nc)
		  break;	    

	    for(int i=0; i<nc; i++) {
		  int a, b;
		  scanf("%d%d", &a, &b);

		  if(!set.find(a)) {
			set.insert(pair(a, indexCounter));
			indexCounter++;
		  }
	    }
      }
}

