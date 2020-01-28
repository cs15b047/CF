#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;
vector<ll> arr;

bool check(ll idx, ll n, ll m, ll k){
    ll curr_box = 0;
    ll curr_cap = k;
    ll obj_idx = idx;

    while(curr_box < m && obj_idx < n){
        // cout << curr_box << " " << curr_cap << " " << obj_idx << endl;
        if(curr_cap >= arr[obj_idx]){
            curr_cap -= arr[obj_idx];
            obj_idx++;
        } else{
            curr_box++;
            curr_cap = k;
        }
    }
    bool ans;
    if(obj_idx == n){
        ans = true;
    } else if(curr_box == m){
        ans = false;
    }
    // cout << ans << endl;
    return ans;
}


int main(){
	ll n, m, k; cin >> n >> m >> k;
    arr.resize(n);for(int i = 0;i < n;i++)scanf("%lld",&arr[i]);

    ll left = 0, right = n - 1, mid = (left + right) / 2;

    while(left < right){
        mid = (left + right)/2;
        // cout << mid << endl;
        bool possible = check(mid, n, m, k);
        if(!possible){
            left = mid + 1;
        } else{
            right = mid;
        }
    }
    cout << n - left << endl;
}