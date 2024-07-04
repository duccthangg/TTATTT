//Một số được gọi là số mạnh mẽ khi nó đồng thời vừa chia hết cho số nguyên tố và chia hết cho bình phương 
//của số nguyên tố đó. Tìm số mạnh mẽ nhỏ hơn số N cho trước (N < 10000).
#include <bits/stdc++.h>
#include "funsion_math.h"
using namespace std;

int main(){
    int n; cin >> n;
    Eratosthenes_Prime();
    cout << " Cac So Manh Me: ";
   for(int i = 2; i < n; i++)
   {
    for(int j = 2; j <= sqrt(n); j++){
        if(prime[j] && (i % j == 0) && (i % (j*j) == 0)) cout << i << " ";
    }
   }
    return 0;
}