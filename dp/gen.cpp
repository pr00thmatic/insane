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
  ofstream fout("input");
  fout << "1\n100" << endl;
  for(int i=0; i<99; i++) {
    fout << 500 << " ";
  }
  fout << 499;
  fout << endl;
}

