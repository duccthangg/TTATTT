//Viết chương trình in ra các cặp số (A,B) nằm trong khoảng (M,N) 
//sao cho ước số chung lớn nhất của A và B có giá trị là một số D cho trước.
// Với M,N,D nhập vào từ bàn phím. (0<M,N, D < 1000).
#include <bits/stdc++.h>
#include "funsion_math.h"
using namespace std;

int main(){
    int M, N, D;
    cin >> M >> N >> D;
    if(M > 0 && D < N){
        for(int i = M + 1; i < N; i++){
            for(int j = M + 1; j < N; j++){
                if(GCD(i, j) == D) cout << "(A,B) = " << "(" << i << "," << j<<")" << "\n";
            }
        }
    }
    return 0;
}