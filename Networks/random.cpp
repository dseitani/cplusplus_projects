#include <fstream>
#include <cstdlib>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
  int i,j,k;
  int m=1000;
  int N1=1000;
  double p=0.16;
  double x,sum;
  vector<vector<int> > list1(N1);
  vector<vector<int> > size1(N1, vector<int>(m,0));

  srand(4372);
  ofstream f1("random.txt");

  for(k=0;k<m;k++){
    for(i=0;i<N1;i++){
      list1.push_back(vector<int>());
      for(j=i+1;j<N1;j++){
        x = ((double) rand() / (RAND_MAX));
        if(x<p){
          list1[i].push_back(j);
          list1[j].push_back(i);
        }
      }
    }

    for(i=0;i<N1;i++){
      size1[i][k] = list1[i].size();
    }
  }

  for(i=0;i<N1;i++){
    sum = 0;
    for(j=0;j<m;j++){
      sum += size1[i][j];
    }
    f1 << sum/m << endl;
  }

  return 0;
}
