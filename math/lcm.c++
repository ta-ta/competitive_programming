#include<bits/stdc++.h>

using namespace std;

// 必要なもの
// gcd

long long lcm(long long x, long long y){
    long long a, b, c;
    tie(c, a, b) = gcd(x, y);
    return x / c * y;
}

/*
int main(int argc, char* argv[]){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout.precision(10);

    long A = 11209, B = 123765;
    cout<<lcm(A, B)<<endl;
    return 0;
}
*/