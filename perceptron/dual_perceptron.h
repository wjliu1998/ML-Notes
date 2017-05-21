#ifndef DUAL_PERCEPTRON_H
#define DUAL_PERCEPTRON_H


double *w0;

class Dual_perceptron{
  public:
    Dual_perceptron(): learningRate(0.0),w(w0),b(0.0){}
    Dual_perceptron(double learningRate, double* w, double b):
      learningRate(learningRate), w(w), b(b){}

  public:
    void getAnswer();
    bool adjust(double (*x)[2], int* y, int index);
  private:
    double learningRate;
    double* w;
    double b;
};
#endif
