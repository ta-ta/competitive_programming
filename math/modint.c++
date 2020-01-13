template< unsigned long long mod >
class ModInt {
public:
    unsigned long long x;

    ModInt(long long xx){
        if(xx < 0){
            x = (xx + mod) % mod;
        }else{
            x = xx;
        }
    }

    ModInt(){
        ModInt(0);
    }


    ModInt &operator+=(const ModInt &p) {
        if((x += p.x) >= mod) x -= mod;
        return *this;
    }

    ModInt &operator-=(const ModInt &p) {
        if((x += mod - p.x) >= mod) x -= mod;
        return *this;
    }

    ModInt &operator*=(const ModInt &p) {
        x = x * p.x % mod;
        return *this;
    }

    ModInt &operator/=(const ModInt &p) {
        ///
        unsigned long long b = mod, u = 1, v = 0;
        unsigned long long a = p.x;
        while (b) {
            long long t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        u %= mod;
        if (u < 0) u += mod;
        ///
        *this *= u;
        return *this;
    }

    ModInt operator-() const { return ModInt(-x); }

    ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }

    ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }

    ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }

    ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }

    bool operator==(const ModInt &p) const { return x == p.x; }

    inline bool operator!=(const ModInt& p) const{
        return !(*this == p);
    }

    friend ostream &operator<<(ostream &os, const ModInt &p) {
        return os << p.x;
    }

    friend istream &operator>>(istream &is, ModInt &p) {
        long long t;
        is >> t;
        p = ModInt< mod >(t);
        return (is);
    }
};

/*
void answer(){
    // ModInt<MOD> A = ModInt<MOD>(a);
    // ModInt<MOD> B = ModInt<MOD>(b);
    ModInt<MOD> A;
    ModInt<MOD> B;
    cin>>A>>B;

    cout<<A+B<<endl;
    cout<<A-B<<endl;
    cout<<A*B<<endl;
    cout<<A/B<<endl;

    return;
}
*/