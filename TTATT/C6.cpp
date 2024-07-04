//Is number friend
#include <bits/stdc++.h>
#include "funsion_math.h"
using namespace std;

int main(){
   int n; cin >> n;
   for (int i = 1; i < n; i++) {
        int b = SumNumber_Divisor(i)-i;
        if (b > i && b < n) {
            if (SumNumber_Divisor(b) - b == i) {
                cout << "(" << i << ", " << b << ")" << endl;
            }
        }
    }
    return 0;
}