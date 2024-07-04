//chương trình tính giá trị của: N+p+s-q-k với N cho trước nhập từ bàn phím
#include <bits/stdc++.h>
#include "funsion_math.h"
using namespace std;

int main(){
    int n; cout <<"Nhap bat ki n: ";cin >> n;
    int kNumberPrime = 0;
    int qSumNumberPrimeDivisor = 0;
    int pSumNumberDivisor = 0;
    int sNumberDivisor = 0;
    Eratosthenes_Prime();
    for(int i = 2; i <= sqrt(n); i++)
    {
        if(prime[i]) if(!(n % i)){
            kNumberPrime++;
            qSumNumberPrimeDivisor += i;
        }
    }
    pSumNumberDivisor = SumNumber_Divisor(n);
    sNumberDivisor = CoutNumber_Divisor(n);
    cout<< "Ket qua la: " << n + pSumNumberDivisor + sNumberDivisor - qSumNumberPrimeDivisor - kNumberPrime;
    return 0;
}