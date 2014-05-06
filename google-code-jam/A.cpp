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
      int t, cases=0;
      scanf("%d", &t);
      
      while(t--) {
	    cases++;
	    int cards[2][4][4];
	    int ans[2];
	    
	    for(int switches =0; switches < 2; switches++) {

		  scanf("%d", &(ans[switches]));

		  for(int row=0; row<4; row++) {
			for(int col=0; col<4; col++) {
			      int data;
			      scanf("%d", &data);
			      cards[switches][row][col] = data;
			}
		  }
		  
	    } 
	    ans[0]--; ans[1]--; //got the data!
	    
	    int qty = 0, common=0;

	    
	    for(int first=0; first<4; first++) {
		  for(int second=0; second<4; second++) {

			if(cards[0][ans[0]][first] == cards[1][ans[1]][second]) {
			      qty++;
			      common = cards[0][ans[0]][first];
			}

		  }
	    }
	    
	    printf("Case #%d: ", cases);
	    
	    if(qty == 1) {
		  printf("%d", common);
	    } else if(qty > 1) {
		  printf("Bad magician!");
	    } else
		  printf("Volunteer cheated!");

	    printf("\n");

	    
      }
}

