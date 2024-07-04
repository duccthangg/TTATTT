//Viết chương trình Hai số nguyên tố sinh đôi là hai số nguyên tố hơn kém nhau 2 đơn vị.
// Tìm hai số nguyên tố sinh đôi nhỏ hơn hoặc bằng N, với N được nhập vào từ bàn phím.
#include <bits/stdc++.h>
#include "funsion_math.h"
using namespace std;

int main(){
    int n; cin >> n;
   Eratosthenes_Prime();
   for(int i = 2; i <= n; i++){
    for(int j = i + 1; j<= n; j++){
        if(prime[i] && prime[j] && abs(i - j) == 2) cout << i << " " << j << "\n";
    }
    }
    return 0;
}