#include <fstream>
#include <cstdlib>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[]) {  // 1D random walk
  int i,j,N1,N2;
  int n=1000;
  int m=10000;
  double list[11][m];  // matrix to keep R^2
  double x,R,sum;

  srand(4372);
  ofstream f("ex3_1d.txt");

  for(i=0;i<m;i++){
    N1 = N2 = 0;

    for(j=0;j<n+1;j++){
      x = ((double) rand() / (RAND_MAX));
      if(x<0.5){
        N1 += 1;  //steps foreward
      }else {
        N2 += 1; //steps backward
      }
      if(j%100==0){
        R = pow(N1-N2,2);
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
