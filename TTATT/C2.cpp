//Đếm chữ số nguyên tố
#include <bits/stdc++.h>
using namespace std;
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

int Cout_Number(int n){
    int dem = 0;
    if(n >= 0 && n < 10 ) return 1;
    while(n){
       n /= 10;
        dem++;
    }
    return dem;
}

int main(){
    int n;
    cin >> n;
    if(!(n < 2 && n > 10)){
        long long min =  pow(10, n - 1);
        long long max = pow(10,n) - 1;
        Eratosthenes_Prime();
        for(long long i = min; i <= max; i++)
        {
            if(prime[i]) cout << i << " ";
        }
    }
    // if(!(n < 2 && n > 10)){
    //     Eratosthenes_Prime();
    //     for(long long i = 2; i <= 100000001; i++)
    //     {
    //         if(prime[i]) if(Cout_Number(i) == n) cout << i << " ";
    //     }
    // }
    return 0;
}
