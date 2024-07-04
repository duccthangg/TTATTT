//Viết chương trình tìm các số nguyên tố từ một mảng sinh ngẫu nhiên có kích thước N,
// với N nhập vào từ bàn phím.
#include <bits/stdc++.h>
#include "funsion_math.h"
#include <time.h>

using namespace std;
int main(){
   
   int n; cin >> n;
   int Array_a[n];
   srand(time(NULL));
    for(int i = 0; i < n; i++){
        Array_a[i] = rand() % 1000;
    }
    for(int i =0; i < n; i++){
        if(isPrime(Array_a[i],4)) cout << Array_a[i] << " ";
    }
    return 0;
}