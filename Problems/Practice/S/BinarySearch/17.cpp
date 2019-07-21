#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ll n,m, ta, tb, k; cin >> n >> m >> ta >> tb >> k;
    vector<ll> t1(n);for(int i=0;i<n;i++)cin >> t1[i];
    vector<ll> t2(m);for(int i=0;i<m;i++)cin >> t2[i];

    ll block1 = 0, block2 = k;
    ll ans;
    for(;block1 <= k && block2 >= 0;block1++,block2--){
        if(block1 >= n){
            ans = -1;
            break;
        }
        ll timeB = t1[block1] + ta;
        ll idx = lower_bound(t2.begin(), t2.end(), timeB) - t2.begin();
        if(block2 >= m - idx){
            ans = -1;
            break;
        } else{
            idx += block2;
            if(block1 == 0)ans = t2[idx] + tb;
            else ans = max(ans, t2[idx] + tb);
        }
    }
    cout << ans << endl;
}