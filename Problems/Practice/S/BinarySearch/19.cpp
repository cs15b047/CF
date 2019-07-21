#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<ll> stairs, elevators;

ll closest_stair(ll y1, ll y2){
    if(stairs.empty())return 1e18;
    ll nxt = upper_bound(stairs.begin(), stairs.end(), y1) - stairs.begin();
    ll prev = nxt - 1;
    ll dp=1e18, dn=1e18;
    if(prev >= 0){
        ll sp = stairs[prev];
        dp = llabs(sp - y1) + llabs(sp - y2);
    }
    if(nxt != stairs.size()){
        ll sn = stairs[nxt];
        dn = llabs(sn - y1) + llabs(sn - y2);
    }
    return min(dp, dn);
}

ll closest_lift(ll y1, ll y2){
    if(elevators.empty())return 1e18;
    ll nxt = upper_bound(elevators.begin(), elevators.end(), y1) - elevators.begin();
    ll prev = nxt - 1;
    ll dp=1e18, dn=1e18;
    if(prev >= 0){
        ll sp = elevators[prev];
        dp = llabs(sp - y1) + llabs(sp - y2);
    }
    if(nxt != elevators.size()){
        ll sn = elevators[nxt];
        dn = llabs(sn - y1) + llabs(sn - y2);
    }
    return min(dp, dn);
}

int main(){
    ll n, m, cl, ce, v; cin >> n >> m >> cl >> ce >> v ;
    stairs.resize(cl);elevators.resize(ce); for(int i=0;i<cl;i++)cin >> stairs[i];for(int i=0;i<ce;i++)cin >> elevators[i];
    ll q; cin >> q;
    for(int i=0;i < q; i++){
        ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2 ;
        ll d1 = closest_stair(y1, y2) + llabs(x1 - x2);
        ll d2 = closest_lift(y1, y2) + llabs(x1 - x2)/v + (llabs(x1 - x2) % v != 0);
        ll ans = min(d1, d2);
        if(x1 == x2)ans = llabs(y1 - y2);
        cout << ans << endl;
    }
}