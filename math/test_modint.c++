// 依存先
#include "modint.c++"

void answer(){
    ModInt<MOD> A(897234);
    ModInt<MOD> B(3456);
    cin>>A>>B;

    cout<<A+B<<endl;
    cout<<A-B<<endl;
    cout<<A*B<<endl;
    cout<<A/B<<endl;

    cout<<B.inverse()<<endl;
    cout<<B.pow(0)<<endl;
    cout<<B.pow(-0)<<endl;

    return;
}
