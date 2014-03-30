#include <vector>
#include <queue>
#include <iostream>
#include <cstdio>

#define INFINITY ((1<<31)-1)

using namespace std;

vector<vector<pair<int, int> > > graph;

void dijkstra(int start, vector<vector<pair<int, int> > > graph) {
      priority_queue<pair<int, int> > exploring;
      vector<int> parents(graph.size());
      vector<int> distance(graph.size(), INFINITY);
      vector<bool> visited(graph.size(), INFINITY);

      parents[start] = -1;
      distance[start] = 0;
      visited[start] = true;
      exploring.push(pair<int, int>(0, start));

      while(!exploring.empty()) {
	    cout << " i'm exploring the node " << exploring.top().second << endl;
	    if(exploring.top().second == 3)
		  cout << "!!!!!!!! got the 3 !!!!!!" << endl;
	    pair<int, int> front = exploring.top();
	    exploring.pop();
	    int father = front.second, weight = front.first;

	    if(weight < distance[father]) { 
		  cout << "oh, nvm, weight is smaller than distance... " 
		       << weight << " < " << distance[father] << endl;
		  continue;
	    }

	    for(int i=0; i<graph[father].size(); i++) {
		  pair<int, int> son = graph[father][i];
		  
		  cout << "current distance from " << father
		       << " to " << son.second << " is " 
		       << distance[son.second] << endl;

		  if(distance[father] + son.first < distance[son.second]) {
			cout << "it could be shortest..." << endl;
			distance[son.second] = distance[father] + son.first;
			parents[son.second] = father;
			exploring.push(
			      pair<int, int>(distance[son.second], son.second));
			cout << "\tgoing to explore " << son.second
			     << " btw, the new distance: " 
			     << distance[son.second] << endl;
			if(son.second == 3)
			      cout << "!!!! got the 3!!!!!!!!" << endl;
		  }		  
	    }

      }
      
      for(int i=1; i<graph.size(); i++) {
	    cout << "shortest path to " << i << " is " << distance[i] << endl;
      }
}

void readGraph(int nc, vector<vector<pair<int, int> > > *graph) { //undirected graph...

      for(int i=0; i<nc; i++) {
	    int a, b, c;
	    scanf("%d%d%d", &a, &b, &c);
	    (*graph)[a].push_back(pair<int, int>(c, b));
	    (*graph)[b].push_back(pair<int, int>(c, a));
      }
}

int main() {
      int nc, maxVertex;
      scanf("%d%d", &nc, &maxVertex);
      maxVertex++;
      graph.assign(maxVertex, vector<pair<int, int> >());
      readGraph(nc, &graph);
      dijkstra(1, graph);
}
