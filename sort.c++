#include<bits/stdc++.h>

using namespace std;

const int INF=INT_MAX/4;
const int MOD=1'000'000'007;
const double EPS=1e-14;
const bool DEBUG=true;

void debug(){
    cerr<<endl;
}

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


class Pair_Sort{
public:
    long x, y;

    Pair_Sort(){
    }
    Pair_Sort(long xx, long yy){
        x = xx;
        y = yy;
    }

    bool operator<(const Pair_Sort &ps) const{
        // x昇順、y昇順
        if(x < ps.x){
            return true;
        }else if(x > ps.x){
            return false;
        }else if(y < ps.y){
            return true;
        }
        return false;
    }

    bool operator==(const Pair_Sort &ps) const{
        if(x == ps.x && y == ps.y){
            return true;
        }
        return false;
    }

    inline bool operator!=(const Pair_Sort& ps) const{
        return !(*this == ps);
    }
};

bool cmp_xmax_ymin(const Pair_Sort &ps1, const Pair_Sort &ps2){
    // x降順、y昇順
    if(ps1.x > ps2.x){
        return true;
    }else if(ps1.x < ps2.x){
        return false;
    }else if(ps1.y < ps2.y){
        return true;
    }
    return false;
}

bool cmp_ymin_xmax(const Pair_Sort &ps1, const Pair_Sort &ps2){
    // y降順、x昇順
    if(ps1.y > ps2.y){
        return true;
    }else if(ps1.y < ps2.y){
        return false;
    }else if(ps1.x < ps2.x){
        return true;
    }
    return false;
}


int main(int argc, char* argv[]){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout.precision(10);

    int n=10;
    vector<Pair_Sort> vec(n);
    long x, y;
    for(int i=0; i<n; ++i){
        cin>>x>>y;
        vec[i].x = x;
        vec[i].y = y;
    }

    debug();
    sort(vec.begin(), vec.end());
    for(int i=0; i<vec.size(); ++i){
        debug(vec[i].x, vec[i].y);
    }
    debug();
    sort(vec.begin(), vec.end(), cmp_xmax_ymin);
    for(int i=0; i<vec.size(); ++i){
        debug(vec[i].x, vec[i].y);
    }


    return 0;
}
