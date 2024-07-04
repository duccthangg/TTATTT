#include <bits/stdc++.h>
using namespace std;
bool Check_number(int n){
    int dem = 0;
    for(int i = 1; i <= sqrt(n); i++)
    {
        if(n % i == 0){
            dem++;
            if(i != n / i) dem++;
        }
    }
    return dem == 4;
}
int main(){
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++)
    {
        if(Check_number(i))
        {
            cout << i << " ";
        }
    }
    return 0;
}