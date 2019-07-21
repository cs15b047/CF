#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<ll> convert(ll num){
    vector<ll> repr;
    if(num == 0){repr.push_back(0);}
    while(num != 0){
        repr.push_back(num % 7);
        num = num / 7;
    }
    return repr;
}

int main(){
    ll n, m; cin >> n >> m;
    vector<ll> repr1 = convert(n - 1);
    vector<ll> repr2 = convert(m - 1);
    ll sz1 = repr1.size(), sz2 = repr2.size();
    ll ans = 0;
    // cout << sz1 << " " << sz2  << endl;
    if(sz1+sz2 > 7){
        ans = 0;
    } else {
        for(int i=0;i<n;i++){
            vector<ll> reprh = convert(i);ll szh = reprh.size();for(int k=szh;k<sz1;k++)reprh.push_back(0);
            for(int j=0;j<m;j++){
                vector<ll> reprm = convert(j);ll szm = reprm.size();for(int k=szm;k<sz2;k++)reprm.push_back(0);
                set<ll> comb;
                bool pres = true;
                for(auto it:reprh){
                    if(comb.find(it) != comb.end()){
                        pres = false;break;
                    }
                    comb.insert(it);
                }
                for(auto it:reprm){
                    if(comb.find(it) != comb.end()){
                        pres = false;break;
                    }
                    comb.insert(it);
                }
                ans += pres;
            }
        }
    }
    cout << ans << endl;
}