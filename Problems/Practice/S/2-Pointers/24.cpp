#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ll n, m, k; cin >> n >> m >> k;
    vector<ll> seq(n);for(int i=0;i<n;i++)cin >> seq[i];
    map<ll, vector<ll>> cnts, gaps, starts;
    ll i = 0, strt = 0;
    while(i < n){
        strt = i;
        while(i < n && seq[i] == seq[strt])i++;
        cnts[seq[strt]].push_back(i - strt);
        starts[seq[strt]].push_back(strt);
    }
    ll ans = 1; 
    for(auto it : starts){
        ll num = it.first;
        vector<ll> counts = cnts[num], prefix_sum = counts;for(int i=1;i < counts.size();i++)prefix_sum[i] = prefix_sum[i - 1] + prefix_sum[i];
        ll sz = counts.size();
        for(int i=0;i < sz - 1; i++){
            gaps[num].push_back(it.second[i + 1] - (it.second[i] + counts[i]) );
        }
        vector<ll> gap = gaps[num], prefix_gap = gap;for(int i=1;i < gap.size();i++)prefix_gap[i] = prefix_gap[i - 1] + prefix_gap[i];
        ll temp = 1, num_ans = 1;
        // cout << " For : " << num << endl;
        // for(auto it2: counts)cout << it2 << " ";cout << endl;
        // for(auto it2: it.second)cout << it2 << " ";cout << endl;
        // for(auto it2: gap)cout << it2 << " ";cout << endl;
        // for(auto it2: prefix_gap)cout << it2 << " ";cout << endl;
        // for(auto it2: prefix_sum)cout << it2 << " ";cout << endl;
        for(ll beg = 0;beg < sz; beg++){
            if(sz == 1){
                temp = counts[beg];
            } else {
                ll reqd = k + ((beg > 0)? prefix_gap[beg - 1]:0) ;
                ll idx = lower_bound(prefix_gap.begin(), prefix_gap.end(), reqd) - prefix_gap.begin();
                // cout << idx << endl;
                if(prefix_gap[idx] > reqd)idx--;
                else if(idx == prefix_gap.size())idx--;
                // cout << idx << " " << reqd << endl;
                if(idx < beg){
                    temp = counts[beg];
                } else {
                    temp = prefix_sum[idx + 1] - ((beg > 0) ? prefix_sum[beg - 1] : 0);
                }
            }
            num_ans = max(num_ans, temp);
        }
        ans = max(ans, num_ans);
    }
    cout << ans << endl;
}