#include <bits/stdc++.h>

using namespace std;

const int INF=INT_MAX/4;
const int MOD=1'000'000'007;
const double EPS=1e-14;
const bool DEBUG=true;

template<class T>
void debug(T head){
    cerr<<head<<endl;
}

template <class Head, class... Body>
void debug(Head head, Body... body){
    if(DEBUG){
        cerr<<head<<" ";
        debug(body...);
    }
}


vector<long> vertex;

long root(long x) {
    // ボスを返す
    if(vertex[x]<0){
        return x;
    }
    return vertex[x] = root(vertex[x]);
}

void unite(long x, long y) {
    // グループをくっつける
    x = root(x);
    y = root(y);

    if (x == y){
        return;
    }
    if(-vertex[x] < -vertex[y]){ // x をサイズの大きい方にする
        swap(x, y);
    }
    vertex[x] -= -vertex[y]; // x のサイズを増やす
    vertex[y] = x; // y のボスを x にする
}

bool same(long x, long y) {
    // 同じグループか?
    return root(x) == root(y);
}
long size(long x) {
    // グループのサイズ
    return -vertex[root(x)];
}


int main(){
    long N; // vertex
    cin>>N;
    long M;
    cin>>M;

    vertex.resize(N+1, 0); // 1-indexed
    for(int i=1; i<=N; ++i){
        // グループのボスならグループのサイズ * -1
        // ボスでないならボスのindex
        vertex[i] = -1;
    }


    /*
    vector<long> ans(M, 0);
    ans[M-1] = N*(N-1)/2;

    vector<long> A(M), B(M);
    for(int i=0; i<M; ++i){
        cin>>A[i]>>B[i];
    }


    for(int i=M-1; i>0; --i){
        if(same(A[i], B[i])){
            ans[i-1] = ans[i];
        }else{
            ans[i-1] = ans[i] - size(A[i]) * size(B[i]);
            unite(A[i], B[i]);
        }
    }

    for(int i=0; i<M; ++i){
        cout<<ans[i]<<endl;
    }
    */

    return 0;
}
