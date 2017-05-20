#include <iostream>
#include <cstdio>
#include <cmath>
#include <time.h>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;

double random(double a, double b){
  return (double)rand() / ((double)RAND_MAX / (b - 1)) + a;
}

int main(){
  srand(time(0));
  ofstream inFile;
  inFile.open("ex4x.dat", ios::trunc);
  double x1, x2;
  int i = 0;
  for(i = 0; i < 40; i++){
      x1 = random(0, 5);
      x2 = random(0, (5-x1)/2);
      inFile << x1 << " " << x2 << endl;
  }

  for(i; i < 80; i++){
    x1 = random(0,5);
    x2 = random((5-x1)/2, 5);
    inFile << x1 << " " << x2 << endl;
  }
   
}
