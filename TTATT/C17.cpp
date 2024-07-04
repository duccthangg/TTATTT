//Viết chương trình tìm số nguyên dương x nhỏ nhất sao cho giá trị của biểu thức Ax^2+Bx+C là một số nguyên tố
// với A,B,C là các số nguyên nhập vào từ bàn phím
#include <bits/stdc++.h>
#include "funsion_math.h"
using namespace std;

int main(){
    long long A, B, C;
    cin >> A >> B >> C;
    int x = 1;
    while(1){
        long long value = A * x * x + B * x + C;
        if(isPrime(value,4)){
            cout << "x = " << x <<", Ax^2+Bx+C = " << value;
            break;
        }
        x++;
    }
    return 0;
}
