/*chương trình giải bài toán mô phỏng cách mã và giải mã của hệ mật RSA như sau:
-	Tìm số nguyên số p, q (trong đó 100 < p, q < 500)
-	Tính n = p.q; (n) = (p – 1) (q – 1) 
-	Chọn e là số nguyên tố cùng nhau với (n) (gcd(e, (n)) = 1) và tính d = e^(-1) mod (n)
-	Tính bản mã c của thông điệp m, với m = SBD + 123, c = m^e mod n
-	Giải mã thông điệp, tính m = c^d mod n 
*/
#include <bits/stdc++.h>
#include "funsion_math.h"
#include <time.h>
using namespace std;
int ArrayPrime[600];
int RanDomPrime(){
    int index = 0;
    for(int i = 100; i<500; i++){
        if(prime[i]){
            ArrayPrime[index] = i;
            index++;
        }
    }
    return ArrayPrime[rand()%index];
}
int x, y, d;
void extended_euclide(int a, int b){
    if(b == 0){
        x = 1;
        y = 0;
        d = a;
    }
    else{
        extended_euclide(b,a%b);
        int temp = x;
        x = y;
        y = temp - a/b *y;
    }
}
int find_divE(int e, int phi){
    extended_euclide(e,phi);
    return (x % phi + phi) % phi;
}
int main(){
    Eratosthenes_Prime();
    srand(time(0));
    int q = RanDomPrime();
    int p = RanDomPrime();
    long long n = p * q;
    long long phi_n = (p-1) * (q-1);
    int e = 2;
    while(e < phi_n){
        if(GCD(e,phi_n) == 1) break;
        else e++;
    }
    long long Divmodul = find_divE(e,phi_n);
    long long dPrivateKey = Divmodul % phi_n;
    int SBD; cout <<"Nhap noi dung can gui: "; cin >> SBD;
    int m = SBD;
    long long c = powIndia(m,e,n);
    long long giaima = powIndia(c,dPrivateKey,n);
    cout << "Ma hoa noi dung can gui m sang c: " << c << "\n";
    cout << "Gia ma c de nhin thay noi dung m: "<< giaima;
    return 0;
}
