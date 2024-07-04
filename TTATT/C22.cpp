/*Với một số nguyên dương N thoả mãn 0<N<10000, đặt:
F(N) = N nếu N là một số nguyên tố
F(N) = 0 nếu là hợp số 
Cho  L và R nhập vào từ bàn phím, với mọi cặp i , j trong khoảng [ L , R ] 
hãy viết chương trình in ra màn hình giá trị tổng của F(i) * F(j) với  j > i.*/
#include <bits/stdc++.h>
#include "funsion_math.h"
using namespace std;

int main(){
   int L, R;
   cin >> L >> R;
   Eratosthenes_Prime();
   long long SumF = 0;
   for(int i = L; i < R; i++){
        if(prime[i]){
            for(int j = i + 1; j <= R; j++)
            {
                if(prime[j]){ SumF += i * j; cout << i << "*" << j << " = " << i * j << "\n"; cout << SumF << endl;}
            } 
        }
   }
   cout << SumF;
    return 0;
}
