// combination

///// dependency
// #include "modint.c++"
/////

template< long long mod >
class Combination {
public:
    // nC0 ~ nCn
    long n;
    vector<ModInt<mod>> factorial;
    vector<ModInt<mod>> inverse_factorial;

    Combination(long nn){
        n = nn;
        factorial.resize(n+1);
        inverse_factorial.resize(n+1);
    }

    void calc_factorial(){
        factorial[0] = ModInt<mod>(1);
        inverse_factorial[0] = ModInt<mod>(1);
        for(int i=1; i<n+1; ++i){
            factorial[i] = factorial[i-1] * ModInt<mod>(i);
            inverse_factorial[i] = inverse_factorial[i-1] / ModInt<mod>(i);
        }
    }

    ModInt<mod> calc_combination(long n, long k){
        if(n < 0 || k < 0 || n < k){
            return ModInt<mod>(0);
        }
        return factorial[n] * (inverse_factorial[k] * inverse_factorial[n-k]);
    }
};
