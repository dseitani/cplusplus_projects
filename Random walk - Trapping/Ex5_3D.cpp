#include <fstream>
#include <cstdlib>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
  int i,j,i0,j0,k0;
  int n=1000;
  int m=10000;
  int v=250;
  double x,sum;
  double list[11][m];
  vector<vector<vector<int> >> tiles(v,vector<vector<int>> (v, vector<int> (v))); //3D grid

  srand(4372);
  ofstream file("ex5_3d.txt");

  for(j=0;j<m;j++){
    i0 = 125;
    j0 = 125;
    k0 = 125;
    tiles.assign(v,vector<vector<int>> (v, vector<int> (v,0)));//intial values of grid = 0
    sum = 0;

    for(i=0;i<n+1;i++){
      x = ((double) rand() / (RAND_MAX));
      if(x<1.0/6){
        if(tiles[i0][j0+1][k0]==0){ //if tile hasn't been visited before
          tiles[i0][j0+1][k0] = 1;  //change 0 to 1
          sum += 1;
        }
        j0 = j0+1; //particle's new position
      }else if(x<2.0/6){
        if(tiles[i0+1][j0][k0]==0){
          tiles[i0+1][j0][k0] = 1;
          sum += 1;
        }
        i0 = i0+1;
      }else if(x<3.0/6){
        if(tiles[i0][j0][k0+1]==0){
          tiles[i0][j0][k0+1] = 1;
          sum += 1;
        }
        k0 = k0+1;
      }else if(x<4.0/6){
        if(tiles[i0][j0-1][k0]==0){
          tiles[i0][j0-1][k0] = 1;
          sum += 1;
        }
        j0 = j0-1;
      }else if(x<5.0/6){
        if(tiles[i0-1][j0][k0]==0){
          tiles[i0-1][j0][k0] = 1;
          sum += 1;
        }
        i0 = i0-1;
      }else {
        if(tiles[i0][j0][k0-1]==0){
          tiles[i0][j0][k0-1] = 1;
          sum += 1;
        }
        k0 = k0-1;
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
