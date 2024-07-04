//Viết chương trình tìm hai số nguyên tố nhỏ hơn hoặc bằng N với N nhập vào từ bàn phím
//, sao cho tổng và hiệu của chúng đều là số nguyên tố
#include <bits/stdc++.h>
#include "funsion_math.h"
using namespace std;

int main(){
   long long n; cin >> n;
   long long Array_a[1000];
   int index = 0;
   Eratosthenes_Prime();
   for(long long i = 2; i <= n; i++){
    if(prime[i]) Array_a[index++] = i;
   }
    for(int i = 0; i <= index-1; i++){
       for(int j = i + 1; j < index; j++){
         long long sum = Array_a[i] + Array_a[j];
        long long Differences = Array_a[j] - Array_a[i];
        if(isPrime(sum,4) && isPrime(Differences,4)) cout << Array_a[i] << " " << Array_a[j] << "\n";
       }
    }
    return 0;
}
