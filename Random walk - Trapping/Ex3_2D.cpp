#include <fstream>
#include <cstdlib>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[]) {  // 2D random walk
  int i,j,N1,N2,N3,N4;
  int n=1000;
  int m=10000;
  double list[11][m];  // matrix to keep R^2
  double x,R,sum;

  srand(4372);
  ofstream f("ex3_2d.txt");

  for(i=0;i<m;i++){
    N4 = N1 = N2 = N3 = 0;

    for(j=0;j<n+1;j++){
      x = ((double) rand() / (RAND_MAX));
      if(x<0.25){
        N1 += 1; //steps foreward
      }else if(x<0.5){
        N2 += 1; //steps right
      }else if(x<0.75){
        N3 += 1; //steps backward
      }else {
        N4 += 1; //steps left
      }
      if(j%100==0){
        R = pow(N1-N3,2) + pow(N2-N4,2);
        list[j/100][i] = R; // keep R^2 for every 100 steps
      }
    }
  }

// mean calculation
for(j=1;j<11;j++){
    sum = 0;
    for(i=0;i<m;i++){
      sum += list[j][i];
    }
    f << j*100 << "\t" << sum/m << endl;
}
  return 0;
}
