///// dependency
/////

#include "gcd.c++"

void answer(){
    long A = 112, B = 123;
    long long a, b, c;
    tie(c, a, b) = gcd(A, B);
    cout<<c<<endl;
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<a * A + b * B<<endl;

    return;
}
