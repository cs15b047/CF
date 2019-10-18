#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ll n, m, k, x, y; cin >> n >> m >> k >> x >> y;
    ll ans1, ans2, ans3;
    if(n > 1){
        ll round_tot = 2*(n - 1)*m;
        ll num_rounds = k / round_tot;
        ans1 = (n > 2) ? (2*num_rounds) : num_rounds;
        ans2 = num_rounds;
        ans3 = ((x > 1) && (x < n)) ? (2*num_rounds) : num_rounds;
        ll remn = k % round_tot;
        if(remn != 0){
            if(remn <= m){
                ans1 = max(ans1, num_rounds + 1);
                ans3 += ((x == 1) && (y <= remn));
            } else if(remn <= n*m){
                ans1 += 1;
                ans2 += (remn == n*m);
                ans3 += (remn >= ((x-1)*m + y));
            } else { // only in case of n > 2
                ans1 += 2;
                ans2 += 1;
                ans3 += (1 + ( ((x < n) && (x > 1)) && ( (remn - n*m) >= ((n - 1- x)*m + y) ) ) );
            }
        }
    } else {
        ans1 = k / m + ((k % m) != 0);
        ans2 = k / m;
        ans3 = k / m + ((k % m) >= y) ;
    }
    cout << ans1 << " " << ans2 << " " << ans3 << endl;
}