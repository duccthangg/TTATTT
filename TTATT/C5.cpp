//Sum prime number in the range [a, b]
//Count prime number in the range [a,b]
#include <bits/stdc++.h>
#include "funsion_math.h"
using namespace std;

int main(){
   int a, b;
   cout << "Input a, b: ";
   cin >> a >> b;
   int SumPrimeNumber = 0;
   Eratosthenes_Prime();
   for(int i = a; i <= b; i++)
   {
    if(prime[i]) SumPrimeNumber += i;
   }
   cout << SumPrimeNumber;
    return 0;
}