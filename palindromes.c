/*
 * @author: Ali Murtaza Sharif
 */

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// Returns the number of digits in 'x'
int getLength(int x)
{
  int length = 0;
  while(true)
  {
    x = x/10;
    ++length;
    if(x == 0) break;
  }
  return length;
}

// Select a digit at position n
// The positions are determined as follows
// n      = 3 2 1 0
// number = 6 8 7 5
int selectDigit(int number, int n)
{
  int i;
  for(i = 0;i < n;++i) number /= 10;
  return number%10;
}

// Seperates the digits in an integer and places them in the array 'result'
void splitDigits(int number, int* result)
{
  int length = getLength(number);
  int i;
  for(i = 0;i < length;++i) result[i] = selectDigit(number, i);
}

bool isPalidrome(int n)
{
  int length = getLength(n);
  int digits[length];
  splitDigits(n, digits);
  int i;
  for(i = 0;i < length;++i)
  {
    if(digits[i] != digits[length - 1 - i]) return false;
  }
  return true;
}

int main()
{
  int limit = 1;
  scanf("%i", &limit);
  double sum = 0.0;
  int counter = 0;
  int i;
  for(i = 1;i <= limit;++i)
  {
      if(isPalidrome(i))
      {
        ++counter;
        sum = sum + 1.0/(double)i;
      }
      if(i%(limit/10) == 0) printf("%d %d %f\n", i, counter, sum);
  }
  return 0;
}
