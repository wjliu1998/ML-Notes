#include "pri_perceptron.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>

using namespace std;
using std::cout;
using std::endl;
//get random number
int random(int floor, int ceiling){
  return (rand() % (ceiling - floor + 1)) + floor;
}

void
Pri_perceptron::getAnswer(){
  cout << "w: ";
  for(int i = 0; i < size; i++){
    cout << w[i] <<" ";
  }
  cout << endl;
  cout << "b: " << b << endl;
  cout << "W: ";
  for(int i = 0; i < size; i++){
    cout << W[i] <<" ";
  }
  cout << endl;
  cout << "B: " << B << endl;

}

bool
Pri_perceptron::adjust(double *x, int y){
  double sum = 0.0;
  for(int i = 0; i < size; i++){
    sum += w[i] * x[i];
  }
  sum += b;
  sum *= y;
  if(sum <= 0){
    for(int i = 0; i < size; i++){
      w[i] = w[i] + learningRate * y * x[i];
    }
    b += learningRate * y;
    return true;
  }
  else{ 
    return false;
  }
}

double
Pri_perceptron::pocketAl(double (*x)[3], int *y, int iter, int setSize){
  cout << iter << " " << setSize << endl;
  srand((unsigned)time(NULL));
  int iternum = 0;
  int randomNum;
  while(iternum++ < iter){
    randomNum = random(0, setSize);
    if(predict(x[randomNum], y[randomNum]) == true){
      runw += 1;
      if(runw > runW){
        numokw = predictAll(x, y, setSize);
        if(numokw > numokW){
          for(int i; i < size; i++) W[i] = w[i];
          B = b;
          runW = runw;
          numokW = numokw;
          if(numokW == 1) return 1;
        }
      }
    }
    else{
        for(int i = 0; i < size; i++){
          w[i] = w[i] + learningRate * y[randomNum] * x[randomNum][i];
        }
        b += learningRate * y[randomNum];
        runw = 0;
      }
    }
  return numokW;
}

bool
Pri_perceptron::predict(double* x, int y){
  int answer;
  double sum = 0;
  for(int i = 0; i < size; i++){
    sum += x[i] * w[i];
    //cout << sum << " ";
  }
  sum += b;
  if(sum > 0) answer = 1;
  else        answer = -1;

  if(answer == y) return true;
  else            return false;
}

bool
Pri_perceptron::predictW(double* x, int y){
  int answer;
  double sum = 0;
  for(int i = 0; i < size; i++){
    sum += x[i] * W[i];
  }
  sum += B;

  if(sum > 0) answer = 1;
  else        answer = -1;

  if(answer == y) return true;
  else            return false;
}

int
Pri_perceptron::predictAll(double (*x)[3], int *y, int setSize){
  int hit = 0;
  for(int i = 0; i < setSize; i++){
    if(predict(x[i], y[i]) == true) hit++;
  }
  return hit;
}

void
readFile(double (*x)[3], int* y, string filename, int size){
  ifstream fileStream;
  fileStream.open(filename, ios::in);
  string temp,temp2;
  int count = 0;
  int num = 0;
  cout << size << endl;
  while(num++ < size){
    getline(fileStream,temp);
    istringstream xBand(temp);
    for(int i = 0; i <= 3; i++){
      xBand >> temp2;
      if(i <= 2) x[count][i] = atof(temp2.data());
      else       y[count] = atof(temp2.data());
      if(y[count] == 1) y[count] = 1;
      else              y[count] = -1;
    }
    count++;
}
}
int main(){
  int num = 259;
  double w[3] = {0.0, 0.0, 0.0};

  Pri_perceptron perceptron = Pri_perceptron(1.0, w, 0.0,3); 
  Pri_perceptron perceptron2 = Pri_perceptron(1.0, w, 0.0, 3);

  double inputx[259][3];
  int inputy[259];
  double predictx[47][3];
  int predicty[47];
  readFile(predictx, predicty, "predict", 47);
  readFile(inputx, inputy, "dataset", num);

  int iter = 0;
  bool judge = false;
  while(iter++ < 1000000){
    for(int i = 0; i < num; i++){
      if(perceptron.adjust(inputx[i], inputy[i]) == true){
         judge = true;
      }
    }
    if(judge == true){judge = false; continue;}
    else break;
  }
  perceptron.getAnswer(); 

  int hit = 0;
  for(int j = 0; j < 47; j++){
    if(perceptron.predict(predictx[j], predicty[j])) hit++;
  }
  cout << (double)hit / 47 << endl;

  cout << perceptron2.pocketAl(inputx, inputy, 1000000, 259) << endl;
  perceptron2.getAnswer();
  hit = 0;
  for(int j = 0; j < 47; j++){
    if(perceptron.predictW(predictx[j], predicty[j])) hit++;
  }
  cout << (double)hit / 47 << endl;
  return 0;

}
