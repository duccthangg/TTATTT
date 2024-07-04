/*Viết chương trình sinh một mảng số nguyên tố A gồm N phần tử (N nhập từ bàn phí
m) sử dụng kiểm tra Miller-Rabin. 
In ra mảng và tính khoảng cách nhỏ nhất giữa 2 số bất kỳ trong mảng. */
#include <bits/stdc++.h>
#include "funsion_math.h"
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
        b >>= 1; // b = b/2;
    }
    return res;
}
bool miiller(int d, int n)
{
    // Pick a random number in [2..n-2]
    // Corner cases make sure that n > 4
    int a = 2 + rand() % (n - 4);
 
    // Compute a^d % n
    int x = NBPCL(a, d, n);
 
    if (x == 1  || x == n-1)
       return true;
 
    // Keep squaring x while one of the following doesn't
    // happen
    // (i)   d does not reach n-1
    // (ii)  (x^2) % n is not 1
    // (iii) (x^2) % n is not n-1
    while (d != n-1)
    {
        x = (x * x) % n;
        d *= 2;
 
        if (x == 1)      return false;
        if (x == n-1)    return true;
    }
 
    // Return composite
    return false;
}
 
// It returns false if n is composite and returns true if n
// is probably prime.  k is an input parameter that determines
// accuracy level. Higher value of k indicates more accuracy.
bool Prime(int n, int k)
{
    // Corner cases
    if (n <= 1 || n == 4)  return false;
    if (n <= 3) return true;
 
    // Find r such that n = 2^d * r + 1 for some r >= 1
    int d = n - 1;
    while (d % 2 == 0)
        d /= 2;
 
    // Iterate given number of 'k' times
    for (int i = 0; i < k; i++)
         if (!miiller(d, n))
              return false;
 
    return true;
}
int ArrayPrime[1001];
int RanDomPrime(){
    int index = 0;
    for(int i = 0; i<1000; i++){
        if(Prime(i,5)){
            ArrayPrime[index] = i;
            index++;
        }
    }
    return ArrayPrime[rand()%index];
}
int main(){
    int n; cout <<"Nhap n: "; cin >> n;
    srand(time(0));
    int A[n];
    for(int i = 0; i < n; i++){
        A[i] = RanDomPrime();
    }
    cout << "Cac phan tu trong mang A[n] la: ";
    for(int a : A) cout << a << " ";
    int minn = abs(A[0] - A[1]);
    for(int i = 0; i <= n-1; i++){
       for(int j = i + 1; j < n; j++){
        if(abs(A[i] - A[j]) <= minn){
            minn = abs(A[i] - A[j]);
        }
        cout<<endl << A[i] <<" - " <<A[j] <<" = " << abs(A[i] - A[j]) << endl;
       }
    }
    cout << "\nKhoang cach nho nhat giua 2 phan tu bat ky trong mang A[n] la: " << minn <<"\n";
    return 0;
}