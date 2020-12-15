#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
using namespace std;

double fi(double u){
  return 1/(1 + exp(-u));
}

int main(int argc, char const *argv[]) {
  int i,j,t,epoch;
  int nw = 9;
  int ny = 5;
  double x,u,err;
  double w[nw];
  double dw[nw];
  double y[ny];
  double d[ny];
  double er_max = 0.01; // maximum acceptable error
  double h = 0.2; //learing rate
  bool trained;

  srand(4372);
  ofstream f("weights.txt");

  //initial weights
  for(i=0;i<nw;i++){
    x = -1.0 + ((double) rand() / (RAND_MAX))*(2.0);
    w[i] = x;
  }

  epoch = 1;
  do {
    trained = true;
    for(j=1;j<5;j++){
      // input & target
      switch (j) {
        case 1:
          y[0] = 1;
          y[1] = 1;
          t = 0;
          break;
        case 2:
          y[0] = 1;
          y[1] = 0;
          t = 1;
          break;
        case 3:
          y[0] = 0;
          y[1] = 1;
          t = 1;
          break;
        case 4:
          y[0] = 0;
          y[1] = 0;
          t = 0;
          break;
      }

      for(i=2;i<ny-1;i++){
        u = w[i-2]*y[0] + w[i]*y[1] + w[i+2];
        y[i] = fi(u);
      }

      u = w[6]*y[2] + w[7]*y[3] + w[8];
      y[4] = fi(u);

      err = pow(y[4]-t,2)/2;
      if(err<er_max){
        continue;
      }

      trained = false;

      // back propagation
      d[4] = y[4]*(1-y[4])*(t-y[4]);
      d[3] = y[3]*(1-y[3])*(d[4]*w[7]);
      d[2] = y[2]*(1-y[2])*(d[4]*w[6]);
      d[1] = y[1]*(1-y[1])*(d[3]*w[2] + d[2]*w[3]);
      d[0] = y[0]*(1-y[0])*(d[2]*w[1] + d[3]*w[0]);

      dw[0] = h*d[3]*y[0];
      dw[1] = h*d[2]*y[0];
      dw[2] = h*d[3]*y[1];
      dw[3] = h*d[2]*y[1];
      dw[4] = h*d[3];
      dw[5] = h*d[2];
      dw[6] = h*d[4]*y[2];
      dw[7] = h*d[4]*y[3];
      dw[8] = h*d[4];

      for(i=0;i<nw;i++){
        w[i] = w[i] + dw[i];
      }
    }
    if(trained == true){
      break;
    }
    epoch = epoch + 1;
  } while(epoch<10000);

  for(i=0;i<nw;i++){
    f << w[i] << endl;
  }

  return 0;
}
