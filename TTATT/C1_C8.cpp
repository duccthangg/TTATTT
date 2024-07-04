//Q_Prime
#include <bits/stdc++.h>
bool prime[1000001];
void Eratosthenes_Prime(){
    for(int i = 2; i < 1000001; i++){
        prime[i] = true;
    }
    prime[0] = prime[1] = false;
    for(int i = 2; i <= sqrt(1000001); i++)
    {
        if(prime[i]){
            for(int j = i * i; j < 1000001; j+= i){
                prime[j] = false;
            }
        }
    }
}

int main(){
    int n;
    std::cout  << "Fill number n: ";
    std::cin>>n;
    Eratosthenes_Prime();
    std::cout << "Q_Prime: ";
    for(int i = 1; i <= sqrt(n); i++)
    {
        for(int j = i + 1; j < 1000001; j++)
        {
            if(prime[i] && prime[j] && i * j <= n ) std::cout << i * j << " ";
        }
            if(prime[i]) if(i*i*i <=n ) std::cout << i*i*i <<" ";
        
    }
    std::cout << "\n";
    std::cout << "T_Prime: ";
     for(int i = 1; i <= sqrt(n); i++)
    {
        if(prime[i]) std::cout << i*i << " ";
    }

    return 0;
}