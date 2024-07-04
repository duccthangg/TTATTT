/*Viết chương trình tìm bốn số nguyên tố liên tiếp, 
sao cho tổng của chúng là số nguyên tố nhỏ hơn hoặc bằng N (với N được nhập vào từ bàn phím).*/
#include <bits/stdc++.h>
#include "funsion_math.h"
using namespace std;

int main(){
   long long n; cin >> n;
   Eratosthenes_Prime();
   int Rel = 0;
   for(long long i = 2; i <= n; i++){
    long long count = 0, sum = 0;
    if(prime[i]){
        for(long long j = i; j <= n; j++)
        {
        if(prime[j]){
            sum += j;
            count++;
            if(count == 4){
                if(isPrime(sum,4) && sum <= n){
                    int count2 = 0;
                        Rel = i;
                    for(int i = Rel; i < 1000001; i++){
                        if(prime[i]){
                            cout << i <<" ";
                            count2++;
                        }
                        if(count2 == 4) break;
                    }
                    cout << "\n";
                }
                break;
                }
            }

        }
    }
   }
    return 0;
}