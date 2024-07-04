//Viết chương trình tìm số nguyên tố có ba chữ số
//, biết rằng nếu viết số đó theo thứ tự ngược lại thì ta được một số là lập phương của một số tự nhiên.
#include <bits/stdc++.h>
#include "funsion_math.h"
using namespace std;

int main(){
   Eratosthenes_Prime();
   for(int i = 100; i <= 999; i++){
    if(prime[i]){
        if(ReveseNumber(i) == 4 * 4 * 4 ||
           ReveseNumber(i) == 5 * 5 * 5 ||
           ReveseNumber(i) == 6 * 6 * 6 ||
           ReveseNumber(i) == 7 * 7 * 7 ||
           ReveseNumber(i) == 8 * 8 * 8 ||
           ReveseNumber(i) == 9 * 9 * 9 ){
            cout << i << " ";
           }
    }
   }
    return 0;
}