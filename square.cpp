#include <iostream>
#include <math.h>

const double accuracy = 0.00001;

double f(double x, double b, double c) {
  return x * x + b * x + c;
}

double df(double x, double b) {
  return 2 * x + b;
}

double Newton(double x, double b, double c) {
  double lambda;
  while(f(x, b, c) > accuracy) {
    lambda = f(x, b, c) / df(x, b);
    x = x - lambda;
  }
  return x;
}

double Gradient(double x, double b, double c, double learning_date) {
  double lambda;
  while(f(x, b, c) > accuracy) {
    x = x - learning_date * df(x, b);
  }
  return x;
}



void Solution(double left, double right, double b, double c, double learning_date) {
  int D = b * b - 4 * c;
  if (D < 0) {
    std::cout << "Нет корней";
  } else {
    double first = Gradient(left, b, c, learning_date);
    double second = Gradient(right, b, c, learning_date);
    std::cout << "Методом градиентного спуска, два корня: \n" << first << ", " << second << "\n";
    first = Newton(left, b, c);
    second = Newton(right, b, c);
    std::cout << "Методом Ньютона, два корня: \n" << first << ", " << second << "\n";

  }
}

int main() {
  double b, c, left, right, accuracy;
  std::cout << "Введите границы поиска, b , c и точность: \n";
  std::cin >> left >> right >> b >> c >> accuracy;
  Solution(left, right, b, c, accuracy);
  return 0;
}