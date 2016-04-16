/*
 * @author: Ali Murtaza Sharif
 */

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

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

bool isPrime(int n)
{
  int i;
  for(i = 2;i < n;++i) if(n%i == 0) return false;
  return true;
}

int getFrugality(int n)
{
  int counter = 0;
  int exponent = 0;
  int runLength = n;
  int i;
  for(i = 2;i <= runLength;++i)
  {
    exponent = 0;
    if(isPrime(i) && n%i == 0)
    {
      while(n%i == 0)
      {
        n /= i;
        exponent++;
      }
      if(exponent > 1) counter += getLength(exponent);
      counter += getLength(i);
    }
  }
  return counter;
}

bool isFrugal(int n)
{
  return getLength(n) > getFrugality(n);
}

int main()
{
  int n = 0;
  scanf("%i", &n);
  int i;
  for(i = 2;i < n;++i) if(isFrugal(i)) printf("%d ", i);
  return 0;
}
