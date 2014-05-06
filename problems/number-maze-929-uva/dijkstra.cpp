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

#define INDET -1000

int whois(ii, int, int, int);
int indexOf(int, int, int);

int whois(ii coord, int i, int j, int row) {
      i += coord.first;
      j += coord.second;

      if(i>-1 && j>-1)
	    return indexOf(i, j, row);
      return INDET;      
}

int indexOf(int i, int j, int row) {
      return i*(row+1) + j;
}

int main(){
      int cases;
      scanf("%d", &cases);
      
      while(cases--) {
	    int row, column;
	    scanf("%d%d", &row, &column);
	    int M[row][column];

	    for(int i=0; i<row; i++) {
		  for(int j=0; j<column; j++) {
			scanf("%d", &(M[i][j]));
		  }
	    } //got the maze!
	    
	    
	    //graph it!
	    vector<vector<ii> > graph(row*column);

	    int st = 0;
	    priority_queue<int> exploring;
	    
      }
}

