// lcm

///// dependency
// #include "gcd.c++"
/////

long long lcm(long long x, long long y){
    long long a, b, c;
    tie(c, a, b) = gcd(x, y);
    return x / c * y;
}
