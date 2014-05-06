/**
   We can build a matrix with all the possible ways to 
   produce m < n change with coins of the value contained
   on vector<int> coins.
   
   The first coin must always be 1. What if you don't have
   a coin with value 1? (...)(l.45)
**/

#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

template<typename _td>
void printMatrix(vector< vector<_td> >);

vector< vector<int> > countWaysCC(int n, vector<int> coins) {
  /**
     this way you wont forget that your vector has length
     n+1 (you are also finding the solution for 0, so if you
     use only n, the solution will go only to n-1
  **/
  n++;
  /** 
      the files stands for the range from 0 to n. The V[i] file,
      represents a solution for i.

      the column stands for the coin. So the vector[x][i]
      represents a solution for a quantity 'x', using 
      unlimitted coins from coins[0] to coins[i].
      
  **/
  vector< vector<int> > ways(n, vector<int>(coins.size()));
  
  /**
     There is always one way to return 0 of change, with
     any coin: returning 0 coins.
  **/
  for(int i=0; i<coins.size(); i++) {
    ways[0][i] = 1;
  }

  /**
     There is only 1 way to give change to any quantity
     using only coins of value of 1: you give all the
     quantity with coins of 1 penny. 
     (for l.6, reconsider 0 ways on giving the change).

     !! i think your TODO is done !!
  **/
  for(int i=0; i<n; i++) {
    ways[i][0] = 1;
  }
  
  /**
     And for every "c"oin, for every "s"olution...

     how much ways to give the change for a mount "s"
     if you have all the coins from coins[0] to coins[c]
     are there?

     if s is lesser than the coin's value, then whether
     having this coin, or not having it, won't make any 
     difference, so the solution of ways[c][s] is the 
     same solution as ways[c-1][s]

     if s is greater than the coin's value, then '¬'
     well... i don't fully understand where all this 
     values come from... i only know that, the answer
     can be computed by summing the last different 
     solution to "s" with this coin, plus the solution
     without this coin.     
  **/
  for(int c=1; c<coins.size(); c++) {
    for(int s=1; s<n; s++) {
      if(s < coins[c]) 
	ways[s][c] = ways[s][c-1]; //having this coin doesn't make any difference
      else 
	ways[s][c] = ways[s-coins[c]][c] + ways[s][c-1];
    }
  }

  return ways;
}

/**
   Oh, don't mind me, i'm just printing a generic
   matrix...
**/ 
template<typename _tp>
void printMatrix(vector< vector<_tp> > M) {
  cout << M.size() << endl;
  cout << M[0].size() << endl;

  for(int i=0; i<M.size(); i++) {
    for(int j=0; j<M[i].size(); j++) {
      printf("%d ", M[i][j]);
    }
    printf("\n");
  }

}

int main() {
  vector<int> coins = {1, 5, 10, 25, 50};

  vector< vector<int> > M;
  M = countWaysCC(20, coins);
  printMatrix(M);
}   
   
