#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ll n, c; cin >> n >> c;
    vector<ll> a(n), b(n);for(int i=0;i<n;i++)cin >> a[i] >> b[i];
    ll left = 0, right = 1e18, mid = (left + right) / 2;
    while(left < right){
        mid = (left + right) / 2;
        ll sum = 0; for(int i=0;i<n;i++) sum += (1 + (a[i] * mid)/ b[i]);
        if(sum > c){
            right = mid - 1;
        } else if(sum < c) {
            left = mid + 1;
        } else {
            break;
        }
    }
    ll sm = 0;for(int i=0;i<n;i++) sm += (1 + ((a[i] * mid)/ b[i]) );
    bool all_zero = true;
    for(int i=0;i<n;i++)all_zero = all_zero && (a[i] == 0);
    if(sm == c && !all_zero){
        left = 0;right = mid;
        ll mid2 = (left + right)/2;
        ll lb, rb;
        while(left < right){
            mid2 = (left + right)/2;
            ll sum = 0; for(int i=0;i<n;i++) sum += (1 + (a[i] * mid2)/ b[i]);
            if(sum == c){
                right = mid2;
            } else if(sum < c){
                left = mid2 + 1;
            }
        }
        lb = right;
        left = mid; right = 1e18;
        mid2 = (left + right)/2;
        if(left != right){
            while(left < right){
                mid2 = (left + right)/2;
                ll sum = 0; for(int i=0;i<n;i++) sum += (1 + (a[i] * mid2)/ b[i]);
                if(sum == c){
                    left = mid2 + 1;
                } else if(sum > c){
                    right = mid2;
                }
            }
            left--;
        }
        rb = left;
        cout << rb - lb + 1 << endl;
    } else if(sm == c  && all_zero){
        cout << -1 << endl;
    } else if(sm != c) {
        cout << 0 << endl;
    }
}