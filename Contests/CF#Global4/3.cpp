#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll mod= 998244353 ;

ll pwr(ll idx){
    if(idx == 0)return 1;
    ll tmp = pwr(idx/ 2);
    if(idx % 2 == 0)return (tmp * tmp) % mod;
    return (2*((tmp * tmp) % mod)) % mod;
}

int main(){
    ll w,h; cin >> w >> h ;
    cout << pwr(w + h) << endl;
}