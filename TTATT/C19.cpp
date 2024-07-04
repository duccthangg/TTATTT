//Viết chương trình in ra các số nguyên dương x nằm trong khoảng [m,l] sao cho giá trị của biểu thức Ax^2+Bx+C là một số nguyên tố.
// Với A,B,C, m,l là các số nguyên nhập từ bàn phím (m<l).
#include <bits/stdc++.h>
#include "funsion_math.h"
using namespace std;

int main(){
    long long A, B, C, m, l;
    cin >> A >> B >> C >> m >> l;
    if(m >= 1 && m < l){ // vi x nguyên dương mà x lại thuộc khoảng [m,l]
        for(int i = m; i <= l; i++){
            long long value = A * i * i + B * i + C;
            if(isPrime(value,4)) cout<< "x = " << i <<", Ax^2+Bx+C = " << value << "\n";
        }
    }
    return 0;
}