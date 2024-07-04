/*
Cho các số nguyên dương a,k,n, nhập từ bàn phím (0<a,k<n<1000), 
Viết chương trình xác định xem a^k mod n có phải là một số nguyên tố hay không 
(sử dụng thuật toán bình phương và nhân có lặp)?*/
#include <bits/stdc++.h>
#include "funsion_math.h"
using namespace std;
long long NBPCL(long long a, long long b, long long mod)
{
    long long res = 1;
    while(b){
        if(b&1){
            res *= a;
            res %= mod;
        }
        a *= a;
        a %= mod;
        b >>= 1;
    }
    return res;
}
int main(){
    int a, k ,n;
    cout <<"Nhap a , k , n: ";
    cin >> a >> k >> n;
    if(a > 0 && a < 1000){
        if(isPrime(NBPCL(a,k,n),5)) cout<< NBPCL(a,k,n) <<": La so nguyen to\n";
        else cout <<"NONE";
    }
    return 0;
}