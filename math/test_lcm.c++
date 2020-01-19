///// dependency
#include "gcd.c++"
/////

#include "lcm.c++"

void answer(){
    long A = 11209, B = 123765;
    long LCM = lcm(A, B);
    cout<<LCM<<endl;
    cout<<LCM % A<<endl;
    cout<<LCM % B<<endl;

    return;
}
