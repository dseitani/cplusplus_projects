#include <fstream>
#include <cstdlib>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
  int i,j,k,ii,l,m,temp,max;
  double temp2,count,sum1,sum2,sum3;
  double x;
  double p[] = {0.1,0.2,0.3,0.4,0.5,0.55,0.56,0.57,0.58,0.59, \
                0.6,0.61,0.62,0.63,0.64,0.65,0.7,0.8};
  int sizep = sizeof(p)/sizeof(p[0]);
  int n = 201;
  int N = 100;
  double Iav[sizep][N];
  double Iav2[sizep][N];
  double Pmax[sizep][N];
  vector<vector<int> > grid(n,vector<int> (n));
  int size = 100*n;
  int S[size];
  int L[size];

  for(i=0;i<size;i++){
    S[i] = 0;
    L[i] = 0;
  }

  srand(4372);
  ofstream f1("Iav.txt");
  ofstream f2("Iav2.txt");
  ofstream f3("Pmax.txt");

  for(m=0;m<N;m++){
    grid.assign(n, vector < int >(n, 0));
    for(l=0;l<sizep;l++){
      // clusters creation
      for(i=1;i<n;i++){
        for(j=1;j<n;j++){
          x = ((double) rand() / (RAND_MAX));
          if(x<p[l]){
            grid[i][j] = 1;
          }
        }
      }

      // CMLT
      k = 1;
      for(j=1;j<n;j++){
        for(i=1;i<n;i++){
          if(grid[i][j]==1){
            if(grid[i][j-1]==0){
              if(grid[i-1][j]==0){
                L[k] = k;
                grid[i][j] = L[k];
                S[L[grid[i][j]]]= S[L[grid[i][j]]] + 1;
                k = k + 1;
                continue;
              } else {
                grid[i][j] = grid[i-1][j];
                S[L[grid[i][j]]] = S[L[grid[i][j]]] + 1;
                continue;
              }
            } else {
              grid[i][j] = grid[i][j-1];
              S[L[grid[i][j]]] += 1;
              if(grid[i-1][j]==0 || grid[i-1][j]==grid[i][j-1]){
                continue;
              } else {
                temp = L[grid[i-1][j]];
                L[grid[i-1][j]] = L[grid[i][j-1]];
                for(ii=1;ii<size;ii++){
                  if(L[ii]==temp){
                    L[ii] = L[grid[i][j-1]];
                  }
                }
                S[L[grid[i][j-1]]] = S[L[grid[i][j-1]]] + S[grid[i-1][j]];
                S[grid[i-1][j]] = 0;
                continue;
              }
            }
          }
        }
      }

      //maximum size
      max = S[1];

      for(i=2;i<size;i++){
        if(S[i]>max){
          max = S[i];
        }
      }

      // Iav
      count = 0;
      for(i=1;i<size;i++){
        temp2 = S[i]/(p[l]*n*n);
        count += temp2*S[i];
      }
      Iav[l][m] = count;

      //Iav'
      count = 0;
      for(i=1;i<size;i++){
        if(S[i]!=max){
          temp2 = S[i]/(p[l]*n*n);
          count += temp2*S[i];
        }
      }
      Iav2[l][m] = count;

      //Pmax
      Pmax[l][m] = max/(p[l]*n*n);

      for(i=0;i<size;i++){
        S[i] = 0;
        L[i] = 0;
      }
    }
  }

  for(i=0;i<sizep;i++){
    sum1 = 0;
    sum2 = 0;
    sum3 = 0;
    for(j=0;j<N;j++){
      sum1 += Iav[i][j];
      sum2 += Iav2[i][j];
      sum3 += Pmax[i][j];
    }
    f1 << p[i] << " " << sum1/N << endl;
    f2 << p[i] << " " << sum2/N << endl;
    f3 << p[i] << " " << sum3/N << endl;
  }

  return 0;
}
