//Viết chương trình in ra các cặp số (a,b) thoả mãn điều kiện 0<a,b<1000,
// sao cho ước chung lớn nhất của 2 số đó là một số nguyên tố.
#include <bits/stdc++.h>
#include "funsion_math.h"
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    if(a > 0 && b > 0 && a < 1000 && b < 1000){
        for(int i = a; i < b; i++){
        for(int j = i + 1; j < b; j++){
            if((isPrime(GCD(i,j),5))) cout << "(" << i << "," << j << ")\n";
        }
    }
    }
    return 0;
}