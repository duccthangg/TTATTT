//Viết chương trình in ra màn hình YES trong trường hợp tổng của các số nguyên tố trong khoảng [A, B] 
//là cũng là một số nguyên tố và NO nếu ngược lại. Với A,B là hai số được nhập vào từ bàn phím. 
#include <bits/stdc++.h>
#include "funsion_math.h"
using namespace std;

int main(){
    int A, B;
    cin >> A >> B;
    Eratosthenes_Prime();
    int SumP = 0;
    for(int i = A; i <= B; i++){
        if(prime[i]){
            SumP += i;
        }
   }
   if(isPrime(SumP,5)) cout << "YES";
   else cout << "NO";
    return 0;
}