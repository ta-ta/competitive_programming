#include<bits/stdc++.h>

using namespace std;

tuple<long long, long long, long long> gcd(long long x, long long y) {
    // C = GCD(X, Y)
    // C = A*X + B*Y
    // return (C, A, B)
    long long a = x, b = y;
    long long r, q;
    long long u_2 = 1, u_1 = 0, v_2 = 0, v_1 = 1, u, v;

    r = a % b;
    q = a / b;
    u = u_2 - q * u_1;
    v = v_2 - q * v_1;
    while(r != 0){
        a = b;
        b = r;
        r = a % b;

        q = a / b;
        u_2 = u_1;
        u_1 = u;
        v_2 = v_1;
        v_1 = v;

        u = u_2 - q * u_1;
        v = v_2 - q * v_1;
    }
    return forward_as_tuple(b, u_1, v_1);
}

/*
int main(int argc, char* argv[]){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout.precision(10);

    long A = 112, B = 123;
    long long a, b, c;
    tie(c, a, b) = gcd(A, B);
    cout<<c<<endl;
    cout<<a<<endl;
    cout<<b<<endl;
    return 0;
}
*/