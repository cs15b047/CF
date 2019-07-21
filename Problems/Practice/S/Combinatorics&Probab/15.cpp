#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod = 998244353;

ll pwr(ll idx) {
    if(idx == 0)return 1;
    ll tmp = pwr(idx/2);
    if(idx % 2 == 0)return (tmp * tmp) % mod;
    return (((tmp * tmp) % mod) * 10) % mod;
}

ll get_len(ll num){
    ll ans = 0;
    while(num != 0){
        num = num / 10;
        ans++;
    }
    return ans;
}

ll get_val(ll num, ll other_len, ll strt_idx){
    ll idx = strt_idx;
    ll len = get_len(num);
    ll ans = 0;
    if(len <= other_len){
        while(num != 0){
            ans = (ans + (pwr(idx) * (num % 10)) % mod) % mod;
            num = num / 10;
            idx += 2;
        }
    } else {
        ll cnter = 0;
        while (cnter < other_len){
            ans = (ans + (pwr(idx) * (num % 10)) % mod) % mod;
            num = num / 10;
            idx += 2;
            cnter++;
        }
        idx = 2*other_len;
        while(num != 0){
            ans = (ans + (pwr(idx) * (num % 10)) % mod) % mod;
            num = num / 10;
            idx += 1;
        }
    }
    return ans;
}

int main(){
    ll n; scanf("%lld",&n);
    vector<ll> arr(n);for(int i=0;i<n;i++)scanf("%lld",&arr[i]);
    map<ll,vector<ll>> lengths;for(int i=0;i<n;i++)lengths[get_len(arr[i])].push_back(arr[i]);
    vector<ll> len_list;for(auto it:lengths)len_list.push_back(it.first);
    ll ans = 0;
    for(auto len_it : lengths){
        for(auto it:len_it.second){
            for(auto len : len_list){
                ll val0 = get_val(it, len, 0), val1 = get_val(it, len, 1);
                ans = (ans + ((val0 + val1) * lengths[len].size()) % mod) % mod;
            }
        }
    }
    printf("%lld\n", ans);

}