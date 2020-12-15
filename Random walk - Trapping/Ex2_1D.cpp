#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

// 1D random walk for n steps for m runs

int main(int argc, char const *argv[]) {
  int m=10000;
  int n=1000;
  int i,j;
  int N1,N2;
  double x,sum,R[m];

  srand(4372);

  for(j=0;j<m;j++){
    N1=N2=0;
    for(i=0;i<n;i++){
      x = ((double) rand() / (RAND_MAX)); //random number in range (0,1)
      if(x<0.5){
        N1 += 1; //steps foreward
      } else{
        N2 += 1; //steps backward
      }
    }
    R[j] = pow(N1-N2,2);
  }

  // mean calculation
  sum = 0;
  for(i=0;i<m;i++){
    sum +=R[i];
  }

  cout << sum/m << endl;

  return 0;
}
