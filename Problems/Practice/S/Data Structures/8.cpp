#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    ll n; cin >> n;
    vector<ll>a(n),b(n),c(n);for(int i=0;i<n;i++)cin >> a[i];for(int i=0;i<n;i++)cin >> b[i];
    map<ll,ll> cnt;for(int i=0;i<n;i++)cnt[b[i]]++;
    for(int i=0;i<n;i++){
        if(a[i] == 0){
            ll ele = cnt.begin()->first;
            cnt[ele]--;
            if(cnt[ele] == 0)cnt.erase(ele);
            c[i] = ele;
        } else{
            auto it1 = cnt.lower_bound(n - a[i]);
            ll ele2 = cnt.begin()->first;
            if(it1 == cnt.end()){
                c[i] = (a[i] + ele2) % n;
                cnt[ele2]--;
                if(cnt[ele2] == 0)cnt.erase(ele2);
            } else {
                ll num1 = (a[i] + ele2) % n, num2 = (a[i] + it1->first)% n;
                c[i] = min(num1, num2);
                if(num1 < num2){
                    cnt[ele2]--;
                    if(cnt[ele2] == 0)cnt.erase(ele2);
                } else {
                    it1->second--;
                    if(it1->second == 0)cnt.erase(it1->first);
                }
            }
        }
    }
    for(auto it: c)cout << it << " ";cout << endl;
}