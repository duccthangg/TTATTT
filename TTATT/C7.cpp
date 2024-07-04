//Is number Emirp 
#include <bits/stdc++.h>
#include "funsion_math.h"
using namespace std;

int main(){
   long long n; cin >> n;
   Eratosthenes_Prime();
   for(long long i = 2; i < n; i++){
    if(prime[i]){
        long long reves = ReveseNumber(i);
         if(i >= 2 && i <= 11) cout << i << " ";
         else if(reves < n &&  isPrime(ReveseNumber(i),4)) cout << i << " ";
    };

   }
    return 0;
}