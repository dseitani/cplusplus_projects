#include <fstream>
#include <cstdlib>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[]) {
  int i,j,z;
  double x,y;
  int N = 10000;
  double g1 = 3.0;
  double g2 = 2.0;
  double g3 = 2.5;
  double ymin = 1.0;
  double ymax = N-1.0;

  srand(4372);
  ofstream f1("power-law3.txt");
  ofstream f2("power-law2.txt");
  ofstream f3("power-law25.txt");

  // gamma = 3
  for(i=0;i<N;i++){
    x = ((double) rand() / (RAND_MAX));
    y = pow((pow(ymax,1.0-g1)-pow(ymin,1.0-g1))*x + pow(ymin,1.0-g1),1.0/(1.0-g1));
    z = floor(y);
    f1 << z << endl;
  }

  // gamma = 2
  for(i=0;i<N;i++){
    x = ((double) rand() / (RAND_MAX));
    y = pow((pow(ymax,1.0-g2)-pow(ymin,1.0-g2))*x + pow(ymin,1.0-g2),1.0/(1.0-g2));
    z = floor(y);
    f2 << z << endl;
  }

  // gamma = 2.5
  for(i=0;i<N;i++){
    x = ((double) rand() / (RAND_MAX));
    y = pow((pow(ymax,1.0-g3)-pow(ymin,1.0-g3))*x + pow(ymin,1.0-g3),1.0/(1.0-g3));
    z = floor(y);
    f3 << z << endl;
  }


  return 0;
}
