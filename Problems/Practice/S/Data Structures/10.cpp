#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod = 998244353;

ll pwr(ll idx){
    if(idx == 0)return 1;
    ll tmp = pwr(idx/2);ll ans = (tmp * tmp) % mod ;
    if(idx % 2 == 0)return ans;
    return (ans * 2) % mod;
}

int main() {
    ll n, m; cin >> n >> m;
    string num1, num2; cin >> num1 >> num2;
    vector<ll> value(m, 0);
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    value[0] = (num1[0] == '1');
    for(int i = 1;i < m; i++){
        if(i < n){
            value[i] = value[i - 1] + ((num1[i] == '1') ? pwr(i) : 0) ;
        } else{
            value[i] = value[n - 1];
        }
    }
    ll ans = 0;
    for(int i=0;i<m;i++){
        ans = (ans + value[i] * (num2[i] == '1')) % mod ;
    }
    cout << ans << endl;
}