#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

// 2D random walk for n steps for m runs

int main(int argc, char const *argv[]) {
  int m=10000;
  int n=1000;
  int i,j;
  int N1,N2,N3,N4;
  double x,sum,R[m];

  srand(4372);

  for(j=0;j<m;j++){
    N1=N2=N3=N4=0;
    for(i=0;i<n;i++){
      x = ((double) rand() / (RAND_MAX));
      if(x<0.25){
        N1 += 1; //steps foreward
      } else if(x<0.5){
        N2 += 1; //steps right
      } else if(x<0.75){
        N3 +=1; //steps backward
      } else {
        N4 +=1; //steps left
      }
    }
      R[j] = pow(N1-N3,2) + pow(N2-N4,2);
  }

  // mean calculation
  sum = 0;
  for(i=0;i<m;i++){
    sum +=R[i];
  }

  cout << sum/m << endl;

  return 0;
}
