/*
 * @author: Ali Murtaza Sharif
 */

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// Adjust the level of decimal places the Mach value has to be correct to
// Warning: setting this value to low may cause the program to never terminate
double ACCURACY = 0.0001;

// This the critical area ratio equation, g(x)
double findCritArea(double M)
{
  return (1/M)*pow((2/2.4)*(1 + 0.2*M*M), 3);
}

// f(x) = g(x) - ratio
// Solving for the roots of f(x) is equivalent to solving g(x) = ratio
double f(double M, double ratio)
{
  return findCritArea(M) - ratio;
}

// Derivative of f with respect to M
double df(double M)
{
  return 0.694444*(0.2*M*M+1)*(0.2*M*M+1)-(0.578704*pow((0.2*M*M+1),3))/(M*M);
}

// abs() doesn't work on doubles, only ints
double absolute(double x)
{
  if(x > 0) return x;
  else return -x;
}

// Calculate any root using an initial guess, and a constant value
// 'userInputArea' is the 'ratio' variable in f(x) = g(x) - ratio
double root(double userInputArea, double initialGuess)
{
  double machGuess = initialGuess;
  double result = f(machGuess, userInputArea);
  double slope = df(machGuess);
  do
  {
    // This method uses the Newton method for root finding
    machGuess = machGuess - result/slope;
    slope = df(machGuess);
    result = f(machGuess, userInputArea);
  } while(absolute(result) > ACCURACY);
  // Print only to 3 decimal places
  return machGuess;
}

void roots(double userInputArea)
{
  double rootValue = 0.0;
  rootValue = root(userInputArea, 1);
  printf("Msupersonic= %.3f\n", rootValue);
  rootValue = root(userInputArea, 1e-54);
  printf("Msubsonic= %.3f\n", rootValue);
}

int main()
{
  double area = 0.0;
  printf("Please enter critical area ratio: ");
  scanf("%lf", &area);
  printf("A/A*= %f\n", area);
  roots(area);
  return 0;
}
