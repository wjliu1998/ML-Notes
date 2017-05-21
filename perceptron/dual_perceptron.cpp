#include "dual_perceptron.h"
#include <iostream>

using namespace std;

void
Dual_perceptron::getAnswer(){
  cout << "w: ";
  int size = sizeof(w) / sizeof(w[0]);
  /*for(int i = 0; i <= size; i++){
    cout << *(w+i) <<" ";
  }*/
  cout << w[0] << w[1] << w[2];
  cout << endl;

  cout << "b: " << b << endl;
}

bool
Dual_perceptron::adjust(double (*x)[2], int* y, int index){
  double sum[2] = {0.0,0.0};
  int size = 3;

  for(int i = 0; i <= 3; i++){
    for(int j = 0; j <= 2; j++){
      sum[j] += w[i] * y[i] * x[i][j];
    } 
  }
  int out = y[index] * (sum[0]*x[index][0] + sum[1]*x[index][1] + b);

  if(out <= 0){
    w[index] = w[index] + learningRate;
    b = b + y[index] * learningRate;
    return true;
  }
  else return false;
}

int main(){
  int num = 3;
  double x[][2] = {{3,3},{4,3},{1,1}};
  int  y[3] = {1,1,-1};
  double w[3] = {0,0,0};
  Dual_perceptron perceptron = Dual_perceptron(1.0, w, 0.0);
  bool judge = false;

  while(1){
    for(int i = 0; i < num; i++){
      if(perceptron.adjust(x, y, i) == true){
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
