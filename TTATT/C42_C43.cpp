/*Viết chương trình sinh ra 2 số nguyên tố 0<p,q<1000 
và kiểm tra với với số 0<a<100 thì những số nào thoả mãn: a^p mod q là số nguyên tố.*/
#include <bits/stdc++.h>
#include "funsion_math.h"
using namespace std;
int ArrayPrime[1001];
int RanDomPrime(){
    int index = 0;
    for(int i = 0; i<1000; i++){
        if(prime[i]){
            ArrayPrime[index] = i;
            index++;
        }
    }
    return ArrayPrime[rand()%index];
}
void cau41(){
    int q = RanDomPrime();
    int p = RanDomPrime();
    cout <<"q = " << q << "\n" << "p = " << p << "\n";
    cout <<"Nhung so a thoa man:\n";
    for(int a = 0; a < 100; a++)
    {
        if(isPrime(powIndia(a,p,q),5)) cout << a << ", a^p mod q = " << powIndia(a,p,q) << "\n";
    }
}
void cau42(){
    int p = RanDomPrime();
    int n; cout << "nhap n: "; cin >> n;
    if(n > 0 && n < 1000)
    {
        cout << "p = " << p << "\n";
        cout <<"Nhung so a thoa man:\n";
        for(int a = 0; a < n; a++)
        {
            if(isPrime(powIndia(a,p,n),5)) cout << a << ", a^p mod n = " << powIndia(a,p,n) << "\n";
        }
    }
    
}
int main(){
    Eratosthenes_Prime();
    srand(time(0));
    cau42();
    return 0;
}