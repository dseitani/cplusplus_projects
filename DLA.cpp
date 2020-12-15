#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
  int i,j,j0,j1,iindx,jindx,steps,edge;
  int n=601;
  int m=400;
  double x;
  bool stop;
  vector<vector<int> > grid(n,vector<int> (n));

  ofstream f("dla.dat");
  srand(4372);

  grid.assign(n, vector < int >(n, 0));
  grid[n/2][n/2]=1;  // particle zero

  // create outer circle
  j0=n/2;
  j1=j0+1;
  grid[0][j0] = -1;
  j0=j0-1;
  for(i=1;i<n/2;i++){
      grid[i][j0] = -1;
      grid[i][j1] = -1;
      j0 = j0-1;
      j1 = j1+1;
    }
  j0=0;
  j1=n-1;
  for(i=n/2;i<n;i++){
    grid[i][j0] = -1;
    grid[i][j1] = -1;
    j0 = j0+1;
    j1 = j1-1;
  }

  //create stop condition on the edges of the grid
  for(i=0;i<n;i=i+n-1){
    for(j=0;j<n;j++){
      grid[i][j] = -1;
    }
  }

  for(j=0;j<n;j=j+n-1){
    for(i=0;i<n;i++){
      grid[i][j] = -1;
    }
  }

  loop:do {
    steps = 0;
    // generation of particles from inner circle
    x = ((double) rand() / (RAND_MAX))*2*M_PI;
    iindx = round(n/2 + m/2*sin(x));
    jindx = round(n/2 + m/2*cos(x));
    stop = false; // stop if particle attaches
    do {
      x = ((double) rand() / (RAND_MAX)); // random walk
      if(x<0.25){
        jindx = jindx + 1;
      } else if(x<0.5){
        iindx = iindx + 1;
      } else if(x<0.75){
        jindx = jindx - 1;
      } else {
        iindx = iindx - 1;
      }
      if(grid[iindx][jindx]==-1) { // if particle exceeds bounds take new particle
        goto loop;
      }
      if ((grid[iindx+1][jindx]==1) || (grid[iindx-1][jindx]==1)||(grid[iindx][jindx+1]==1)||(grid[iindx][jindx-1]==1)||(grid[iindx+1][jindx+1]==1)||(grid[iindx+1][jindx-1]==1)||(grid[iindx-1][jindx+1]==1)||(grid[iindx-1][jindx-1]==1)) {
        grid[iindx][jindx] = 1; // attach if there is a neighboring particle
        stop = true;
      }
      steps = steps + 1;
    } while(stop==false);
  } while(steps>2); // stop if too close to the inner circle

//write result on file
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      f << grid[i][j] << "\t";
    }
    f << endl;
  }

  return 0;
}
