#include <fstream>
#include <cstdlib>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  int n=500;
  int m=100000;
  int i,l,iidx,jidx,i0,j0,sum;
  double x,c;
  double cumul = 0.0;
  vector <double> times(m);
  vector <vector<int> > grid(n,vector <int> (n));
  unordered_map<int, int> freq;

  grid.assign(n, vector < int >(n, 0));
  ofstream file1("ex6_freq.txt");
  ofstream file2("ex6_cumul.txt");

  srand(4372);
  c = 0.001; // trap density
  l = c*n*n; // number of traps

  for(i=0;i<l;i++){ // set traps
    iidx = rand()%n;
    jidx = rand()%n;
    grid[iidx][jidx] = -1;
  }

  for(i=0;i<m;i++){
    sum = 0; // number of steps
    do {
      i0 = rand()%n;
      j0 = rand()%n;
      if(grid[i0][j0]==-1){ // check if particle is placed in trap
        break;
      }
      x = ((double) rand() / (RAND_MAX));
      if(x<0.25){
        if(j0==n-1){ // check if we are on the edge of the grid
          j0 = 0;
        } else{
          j0 = j0+1;
        }
      } else if(x<0.5){
        if(i0==n-1){
          i0 = 0;
        } else{
          i0 = i0+1;
        }
      } else if(x<0.75){
        if(j0==0){
          j0 = n-1;
        } else{
          j0 = j0-1;
        }
      } else {
        if(i0==0){
          i0 = n-1;
        } else{
          i0 = i0-1;
        }
      }
      sum += 1;
    } while(grid[i0][j0]!=-1);

    times[i] = sum; // trapping time
  }

  // trapping time frequencies
  for(i=0;i<m;i++)
    freq[times[i]]++;

  for(auto x : freq)
    file1 << x.first << "\t" << x.second << endl;

  // cumulative frequencies
  set<pair<int, int> > st;

  for(auto x : freq)
    st.insert({ x.first, x.second });

  for(auto x : st){
    cumul += x.second;
    file2 << x.first << "\t" << 1-cumul/m << endl;
  }
  return 0;
}
