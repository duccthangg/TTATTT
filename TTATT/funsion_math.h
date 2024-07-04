#ifndef funsion_Math
#define funsion_Math

#include <iostream>
#include <math.h>
#include <time.h>

void Swap(int &a, int &b);
// Sang Eratosthenes
bool prime[100000001];
void Eratosthenes_Prime(){
    for(long long i = 2; i < 100000001; i++){
        prime[i] = true;
    }
    prime[0] = prime[1] = false;
    for(long long i = 2; i <= sqrt(100000001); i++)
    {
        if(prime[i]){
            for(int j = i * i; j < 100000001; j+= i){
                prime[j] = false;
            }
        }
    }
}
//Dem uoc
int CoutNumber_Divisor(int n){
    int dem = 0;
    for(int i = 1; i <= sqrt(n); i++)
    {
        if(n % i == 0){
            dem++;
            if(i != n / i) dem++;
        }
    }
    return dem;
}
//Tong uoc
int SumNumber_Divisor(int n){
    int sum = 0;
    for(int i = 1; i <= sqrt(n); i++)
    {
        if(n % i == 0){
            sum += i;
            if(i != n / i) sum += n / i;
        }
    }
    return sum;
}
//Dao nguoc so
long long ReveseNumber(long long n){
    long long reverse = 0;
    while(n)
    {
        reverse = reverse * 10 + n % 10;
        n /= 10;
    }
   return reverse;
}
//Kiem tra snt
bool CheckPrimeNumber(int n){
    for(int i = 2; i <= sqrt(n); i++)
    {
        if(!(n % i)) return false;
    }
    return n > 1;
}
//GCD UCLN
int GCD(int a, int b){
    if(b == 0) return a;
    return GCD(b, a % b);
}
//Algorithm_MultiIndia
long long powIndia(long long a, long long b, long long mod)
{
    long long res = 1;
    while(b){
        if(b&1){/*b%2 = 1*/
            res *= a;
            res %= mod;
        }
        a *= a;
        a %= mod;
        b >>= 1; //b = b / 2;
    }
    return res;
}

long long Rand(long long l, long long h) {
    return l + rand() % (h - l + 1);
}
//Algorithm_Fermat
bool CheckPrimeFermat(long long n){
    srand(time(0));
    if(n == 1) return false;
    if(n == 2) return true;
    for(int i = 1; i <= 100; i++){
         long long x = Rand(2, n - 1);
         long long result = powIndia(x,n-1,n);
        if(result != 1) 
            return false;
    }
    return true;
}
bool miillerTest(int d, int n)
{
    srand(time(0));
    // Pick a random number in [2..n-2]
    // Corner cases make sure that n > 4
    int a = 2 + rand() % (n - 4);
 
    // Compute a^d % n
    int x = powIndia(a, d, n);
 
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
bool isPrime(int n, int k)
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
         if (!miillerTest(d, n))
              return false;
 
    return true;
}
//Reverse Array
void ReverseArray(int n, int Arr[]){
    int lef = 0, rig = n - 1;
    while(lef <= rig){
        Swap(Arr[lef],Arr[rig]);
        lef++;
        rig--;
    }
}
//Swap
void Swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
#endif