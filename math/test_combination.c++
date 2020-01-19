///// dependency
#include "modint.c++"
/////

#include "combination.c++"

void answer(){
    long N = 10;
    Combination<MOD> C(N); // 0C0 ~ NCN まで計算可能
    C.calc_factorial();
    for(int i=0; i<N+1; ++i){
        for(int j=0; j<N+1; ++j){
            cout<<C.calc_combination(i, j)<<" ";
        }
        cout<<endl;
    }

    return;
}
