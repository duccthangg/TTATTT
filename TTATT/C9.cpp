//Count prime number
#include <bits/stdc++.h>
#include "funsion_math.h"
using namespace std;

int main(){
    int n; cin>> n;
    int count = 0;
    Eratosthenes_Prime();
    for(int i = 2; i <= n; i++)
    {
       if(prime[i])  count++;;
    }
    cout << count;
    return 0;
}