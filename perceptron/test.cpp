#include<iostream>
#include<cstring>
#include<fstream>
#include<sstream>

#include "pri_perceptron.h"
using namespace std;
using std::cout;
using std::endl;
int main(){
  double x[80][2];
  double y[80];
  
  ifstream xStream;
  xStream.open("ex4x.dat", ios::in);
  ifstream yStream;
  yStream.open("ex4y.dat", ios::in);
  string xtemp, xtemp2, ytemp, ytemp2;
  int i = 0;
  while(getline(xStream, xtemp) && getline(yStream, ytemp)){
    istringstream xBand(xtemp);
    istringstream yBand(ytemp);
    for(int j = 0; j < 2; j++){
      xBand >> xtemp2;
      x[i][j] = atof(xtemp2.data());
    }
    yBand >> ytemp2;
    y[i] = atof(ytemp2.data());
    //cout << atof(ytemp2.data()) << endl;
    //cout << y[i] << " " << i << endl;
    i++;
  }
  for(int i = 0; i < 80; i++){
    cout << x[i][0] << " " << x[i][1] << " " << y[i] << endl;
  }
}

