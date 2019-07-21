#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod = 1e9 + 7;

ll pwr(ll idx) {
    if(idx == 0)return 1;
    ll tmp = pwr(idx/2);
    if(idx % 2 == 0)return (tmp * tmp) % mod;
    return (((tmp * tmp) % mod) * 2) % mod;
}

int main(){
    string num;cin >> num;
    ll n = num.length(), ans = 0;
    for(int i=0;i< num.length();i++){
        if(num[i] == '1'){
            ans = (ans + pwr(2*(n - 1) - i)) % mod ;
        }
    }
    cout << ans << endl;
}