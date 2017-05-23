#include<iostream>
using namespace std;
#ifndef PRI_PERCEPTRON_H
#define PRI_PERCEPTRON_H

double w0[2] = {0.0,0.0};
class Pri_perceptron{
  public:
    Pri_perceptron(): learningRate(0.0),w(w0),b(0.0),size(2) {}
    Pri_perceptron(double learningRate, double* w, double b, int size):
      learningRate(learningRate), w(w), b(b),size(size), W(w), B(b), runw(0),runW(0),numokw(0),numokW(0){}
  
  public:
      //get parameter of perceptron
      void getAnswer();
      //adjust parameter
      bool adjust(double* x, int y);
      //implement poekct algorithm
      double pocketAl(double (*x)[3], int *y,int iter, int setSize);
      //predict with w(primary form)
      bool predict(double* x, int y);
      //predict throughout dataset
      int predictAll(double (*x)[3], int *y, int size);
      //predict with W(pocket algorithm)
      bool predictW(double *x, int y);
  private:
      double learningRate;
      double* w;
      double b;
      double* W;
      double B;
      int runw;
      int runW;
      int numokw;
      int numokW;
      int size;
};

#endif
