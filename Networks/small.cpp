#include <fstream>
#include <cstdlib>
using namespace std;

int main(int argc, char const *argv[]) {
  int i,j,y,sum;
  int N=1000;
  int k=14;
  double p=0.20;
  double x;
  int adjmatrix[N][N];

  srand(4372);
  ofstream f("small-world.txt");

  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      adjmatrix[i][j] = 0;
    }
  }

  // regular Watts-Strogatz network
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      if(abs(i-j)<=k/2 || abs(i-j)>(N-1-k/2)){
        adjmatrix[i][j] = 1;
      }
      if(i==j){
        adjmatrix[i][j] = 0;
      }
    }
  }

  //small world with probability p
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      if(adjmatrix[i][j]==1){
        x = ((double) rand() / (RAND_MAX));
        if(x<=p){
          adjmatrix[i][j] = 0;
          do{
            y = rand()%N;
          } while(y==i);
          adjmatrix[i][y] = 1;
        }
      }
    }
  }

  for(i=0;i<N;i++){
    sum = 0;
    for(j=0;j<N;j++){
      if(adjmatrix[i][j]==1){
        sum += 1;
      }
    }
    f << sum << endl;
  }

  return 0;
}
