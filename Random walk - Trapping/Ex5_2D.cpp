#include <fstream>
#include <cstdlib>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
  int i,j,i0,j0;
  int n=1000;
  int m=10000;
  double x,sum;
  double list[11][m];
  vector<vector<int> > tiles(n,vector<int> (n)); //2D grid

  srand(4372);
  ofstream file("ex5_2d.txt");

  for(j=0;j<m;j++){
    i0 = 500;
    j0 = 500;
    tiles.assign(n, vector < int >(n, 0)); //intial values of grid = 0
    sum = 0;

    for(i=0;i<n+1;i++){
      x = ((double) rand() / (RAND_MAX));
      if(x<0.25){
        if(tiles[i0][j0+1]==0){ //if tile hasn't been visited before
          tiles[i0][j0+1] = 1;  //change 0 to 1
          sum += 1;
        }
        j0 = j0+1; //particle's new position
      }else if(x<0.5){
        if(tiles[i0+1][j0]==0){
          tiles[i0+1][j0] = 1;
          sum += 1;
        }
        i0 = i0+1;
      }else if(x<0.75){
        if(tiles[i0][j0-1]==0){
          tiles[i0][j0-1] = 1;
          sum += 1;
        }
        j0 = j0-1;
      }else {
        if(tiles[i0-1][j0]==0){
          tiles[i0-1][j0] = 1;
          sum += 1;
        }
        i0 = i0-1;
      }
      if(i%100==0){
        list[i/100][j] = sum; //keep S for every 100 steps
      }
    }
  }

// mean calculation
  for(i=1;i<11;i++){
      sum = 0;
      for(j=0;j<m;j++){
        sum += list[i][j];
      }
      file << i*100 << "\t" << sum/m << endl;
  }

  return 0;
}
