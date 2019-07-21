#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ll n; cin >> n;
    vector<ll> num(n);for(int i=0;i<n;i++)cin >> num[i];
    vector<vector<ll>> lists;
    vector<ll> ends;
    ends.push_back(-num[0]);
    vector<ll> tmp; tmp.push_back(num[0]);
    lists.push_back(tmp);tmp.clear();
    for(int i=1;i<n;i++){
        if(num[i] < -ends.back()){
            ends.push_back(-num[i]);
            tmp.push_back(num[i]);
            lists.push_back(tmp);
            tmp.clear();
        } else {
            ll idx = upper_bound(ends.begin(), ends.end(), -num[i]) - ends.begin();
            ends[idx] = -num[i];
            lists[idx].push_back(num[i]);
        }
    }
    for(auto vec: lists){
        for(auto it: vec)cout << it << " ";cout << endl;
    }
}