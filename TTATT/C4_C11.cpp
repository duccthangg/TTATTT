//Count prime number in the range [a,b]
#include <bits/stdc++.h>
#include "funsion_math.h"
using namespace std;

int main(){
   int a, b;
   cout << "Input a, b: ";
   cin >> a >> b;
   Eratosthenes_Prime();
   cout << "Cau4: ";
   for(int i = a; i <= b; i++)
   {
    if(prime[i]) cout << i << " ";
   }
    cout << "\n";
    int n; cin >> n;
    int SumPrimeNumber = 0;
    for(int i = 2; i <= n; i++){
        if(prime[i]){
            SumPrimeNumber += i;
        }
    }
    cout <<"Cau11: "<< SumPrimeNumber;
    return 0;
}