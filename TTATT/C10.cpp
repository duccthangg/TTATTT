//Viết chương trình đếm số ước và số ước nguyên tố của một số N nhập vào từ bàn phím.
#include <bits/stdc++.h>
#include "funsion_math.h"
using namespace std;

int main(){
   int n, CountOfDivisor = 0, CountPrimeOfDivisor = 0;
   cin >> n;
   Eratosthenes_Prime();
   CountOfDivisor = CoutNumber_Divisor(n);
   for(int i = 2; i <= sqrt(n); i++){
    if(prime[i]) if(n % i == 0) CountPrimeOfDivisor++;
   }
   cout <<"So uoc: " << CountOfDivisor << " So uoc nguyen to: " << CountPrimeOfDivisor;
    return 0;
}