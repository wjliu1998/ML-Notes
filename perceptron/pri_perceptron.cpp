#include "pri_perceptron.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>

using namespace std;
using std::cout;
using std::endl;

void
Pri_perceptron::getAnswer(){
  cout << "w: ";
  int size = sizeof(w) / sizeof(w[0]);
  for(int i = 0; i <= size; i++){
    cout << *(w+i) <<" ";
  }
  cout << endl;

  cout << "b: " << b << endl;
}

bool
Pri_perceptron::adjust(double *x, int y){
  double sum = 0.0;
  int size = sizeof(x)/sizeof(x[0]);
  for(int i = 0; i <= size; i++){
    sum += w[i] * x[i];
  }
  sum += b;
  sum *= y;
  /*cout << "x:" << x[0] << " " << x[1] << endl;
  cout << "y:" << y << endl;
  cout << "b:" << b << endl;
  cout << "sum" << sum << endl;*/
  if(sum <= 0){
    for(int i = 0; i <= size; i++){
      w[i] = w[i] + learningRate * y * x[i];
    }
    b += learningRate * y;
    return true;
  }
  else{ 
    return false;
  }
}
int main(){
  int num = 80;
  double w[2] = {0.0, 0.0};
  Pri_perceptron perceptron = Pri_perceptron(1.0, w, 0.0);
  
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
    y[i] = (atof(ytemp2.data()) ? 1.0 : -1.0);
    i++;
  }

  bool judge = false;
  while(1){
    for(int i = 0; i < num; i++){
      if(perceptron.adjust(x[i], y[i]) == true){
         judge = true;
         perceptron.getAnswer();
         cout << "The adjusted num: " << i << endl;
    }
    }
    if(judge == true){judge = false; continue;}
    else break;
  }
  perceptron.getAnswer();
  return 0;
}
