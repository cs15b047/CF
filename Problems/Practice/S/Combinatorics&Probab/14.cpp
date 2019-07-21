#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ll n; cin >> n;
    ll ans = 1;
    if(n == 5)ans = 120;
    else {
        ll tmp = (n * (n - 1) * (n - 2) * (n - 3) * (n - 4)) / 120 ;
        ans = tmp * tmp * 120;
    }
    cout << ans << endl;
}