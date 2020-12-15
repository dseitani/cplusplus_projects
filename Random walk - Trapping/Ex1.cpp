#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main(int argc, char const *argv[]) {
  int N[] = {10,100,1000,10000,100000,1000000};
  int i,j;
  double sum;

  srand(4372); // seed for random numbers
  ofstream file("ex1.txt");

  for(i=0;i<6;i++){
    sum = 0;
    for(j=0;j<N[i];j++){
      sum += ((double) rand() / (RAND_MAX));
    }
    file << N[i] << "\t" <<sum/N[i] << endl;
  }

  return 0;
}
