#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    ll n, t; cin >> n >> t;
    vector<ll> price(n);for(int i=0;i<n;i++)cin >> price[i];
    ll mnm = 1e18; for(int i=0;i<n;i++)mnm = min(mnm, price[i]);
    ll remn = t;
    ll ans = 0;
    while(remn >= mnm){
        ll cost = 0, num = 0;
        for(int i=0;i<n;i++){
            if (cost + price[i] <= remn){
                cost += price[i];
                num++;
            }
        }
        ll rounds = remn / cost;
        remn = remn % cost;
        ans += rounds * num;
    }
    cout << ans << endl;
}