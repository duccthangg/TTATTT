/*Cho mảng A gồm các số nguyên thuộc F_p nhập vào từ bàn phím, 
hãy viết chương trình in ra mảng B có các phần tử là nghịch đảo của các phần tử tương ứng trong A. */
#include <bits/stdc++.h>
#include "funsion_math.h"
#include "time.h"
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
int x, y, d;
void extended_euclide(int a, int b){
    if(b == 0){
        x = 1;
        y = 0;
        d = a;
    }
    else{
        extended_euclide(b,a%b);
        int temp = x;
        x = y;
        y = temp - a/b * y;
    }
}
int find_divE(int a, int phi){
    extended_euclide(a,phi);
    if(GCD(a,phi) == 1){
        return (x % phi + phi) % phi;
    }
    else return 0;
}
int main(){
    Eratosthenes_Prime();
    srand(time(0));
    int p = RanDomPrime();
    cout << "p = " << p << endl;
    int A[1001], B[1001];
    for(int i = 0; i < 10; i++){
        A[i] = rand() % p - 1;
    }
    cout <<"Cac phan tu mang A[]: ";
    for(int i = 0; i < 10; i++){
        cout << A[i] <<" ";
    }
    cout << endl;
    for(int i = 0; i < 10; i++){
        B[i] = find_divE(A[i],p);
    }
    for(int i = 0; i < 10; i++){
        cout <<"Phan tu nghich dao cua " << A[i] <<" trong truong Fp la: "<<B[i]<<"\n";
        cout <<"A[" <<i <<"]*B["<<i<<"] mod p = " <<A[i]<<"*" <<B[i]<<" mod "<<p <<" = " << (A[i]*B[i]) % p <<"\n";
    }
    return 0;
}