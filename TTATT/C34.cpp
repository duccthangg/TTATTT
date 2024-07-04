/*Cài đặt thuật toán kiểm tra số nguyên tố Fermat. 
Trong trường hợp số nào thì thuật toán cho kết quả kiểm tra sai.
*/
#include <bits/stdc++.h>
#include "funsion_math.h"
#include <cstdlib> // Thư viện cho hàm rand()
#include <time.h>
using namespace std;
long long NBPCL(long long a, long long b, long long mod)
{
    long long res = 1;
    while(b){
        if(b&1){
            res *= a;
            res %= mod;
        }
        a *= a;
        a %= mod;
        b >>= 1;
    }
    return res;
}
//Algorithm_Fermat
long long Random(long long l, long long h) {
    return l + rand() % (h - l + 1);
}
bool Fermat(long long n){
    if (n <= 1 || n == 4) return false;
    if (n <= 3) return true;
    for(int i = 1; i <= 100; i++){
         long long a = Random(2, n - 2);
        if(NBPCL(a,n-1,n)!= 1) 
            return false;
    }
    return true;
}
int main(){
    srand(time(0));
     long long n; cin >> n;
     if(Fermat(n)) cout << n << ": la so nguyen to\n";
     else cout << n << ": khong la so nguyen to\n";
    return 0;
}
