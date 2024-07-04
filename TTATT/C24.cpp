/*Đặt S1, S2 là các mảng chứa giá trị bình phương của các số nguyên. 
Hãy viết chương trình in ra số lượng tất cả các số nguyên tố nằm trong khoảng [a,b] 
sao cho số này cũng là tổng của hai số x và y với x thuộc S1 và y thuộc S2. 
Trong đó, a,b là các số được nhập từ bàn phím
Ví dụ: với a=10, b =15, in ra giá trị là 1 
vì trong khoảng [10,15] chỉ có 2 số nguyên tố 11 và 13, nhưng chỉ có 13 = 2^2 + 3^2=4+9 */
// Tong 2 so Cp la 1 so nt
#include <bits/stdc++.h>
#include "funsion_math.h"
using namespace std;

int main(){
    int A, B;
    cin >> A >> B;
    int S1[1001], S2[1001];
    int index = 0;
    int count = 0;
    for(int i = 2; i <= sqrt(B); i++){
        S1[index] = i*i;
        S2[index] = i*i;
        index++;
    }
    cout << index <<"\n";
    for(int i = A; i <= B; i++){
        for(int j = 0; j < index - 1; j++){
            if(isPrime(i,5) && i == S1[j] +S2[j+1]) {
                cout << i << " = " << S1[j] << " + "<< S2[j+1] << endl;
                count++;
            };
        }
    }
    cout << count;
    return 0;
}
