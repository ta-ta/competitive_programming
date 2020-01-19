template< unsigned long long mod >
class ModInt {
public:
    long long x;

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
        *this *= p.inverse();
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
        p = ModInt(t);
        return (is);
    }

    ModInt inverse() const {
        long long a = x, b = mod, u = 1, v = 0, t;
        while(b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return ModInt(u);
    }

    ModInt pow(long long n) const {
        bool negative = false;
        if(n < 0){
            negative = true;
            n = abs(n);
        }

        ModInt ret(1), mul(x);
        while(n > 0) {
            if(n & 1) ret *= mul;
            mul *= mul;
            n >>= 1;
        }

        if(negative == true){
            return ret.inverse();
        }
        return ret;
    }
};
