#ifndef PRI_PERCEPTRON_H
#define PRI_PERCEPTRON_H

double w0[2] = {0.0,0.0};
class Pri_perceptron{
  public:
    Pri_perceptron(): learningRate(0.0),w(w0),b(0.0) {}
    Pri_perceptron(double learningRate, double* w, double b):
      learningRate(learningRate), w(w), b(b){}
  
  public:
      void getAnswer();
      bool adjust(double* x, int y);
  private:
      double learningRate;
      double* w;
      double b;
};

#endif
