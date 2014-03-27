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
      int cases = 0;

      while(true) {
	    map<int, vi> graph;
	    int nc;
	    scanf("%d", &nc);

	    if(!nc)
		  break;

	    for(int i=0; i<nc; i++) {
		  int a, b;
		  scanf("%d%d", &a, &b);
		  graph[a].push_back(b);
		  graph[b].push_back(a);
	    }
	    
	    while(true) {
		  int start, ttl;
		  scanf("%d%d", &start, &ttl);

		  if(!start && !ttl)
			break;
		  cases++;
		  
		  //BFS MOTHAFUCKAH!
		  map<int, int> dist;
		  map<int, bool> visited;
		  queue<int> explore;
		  explore.push(start);
		  visited[explore.front()] = true;
		  dist[explore.front()] = 0;

		  while(!explore.empty()) {
			
			if(dist[explore.front()] != ttl) {

			      for(int i=0; i<graph[explore.front()].size(); i++) {

				    if(!visited[graph[explore.front()][i]]) {
					  dist[graph[explore.front()][i]] =
						dist[explore.front()] + 1;
					  explore.push(graph[explore.front()][i]);
					  visited[graph[explore.front()][i]] = true;
				    } 

			      }

			} 
			
			explore.pop();
		  }
		  /* by now you know that the vector dist has
		     the optimus distance from the start to all 
		     the nodes he can go */

		  int notReachable = graph.size() - dist.size();
		  printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", cases, notReachable, start, ttl);
	    }

      }
}

