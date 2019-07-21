#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<ll> prof;
bool cmp(ll a, ll b){
    return prof[a - 1] < prof[b - 1];
}
int main() {
    ll n,k; cin >> n >> k;
    prof.resize(n);for(int i=0;i<n;i++)cin >> prof[i];
    ll q, q_actual; cin >> q;q_actual = q;
    set<ll> tot;for(int i = 1;i <= n;i++)tot.insert(i);
    map<vector<ll>, double> val;
    for (int i = 0; i < q; i++){
        vector<ll> card_set(n/k);for(int j=0;j<n/k;j++)cin >> card_set[j];
        sort(card_set.begin(), card_set.end());
        double avg = 0.0;
        for(auto it:card_set){
            avg += (double)(prof[it - 1]);
            tot.erase(it);
        }
        avg = avg / (double)(n/k);
        if(val.find(card_set) != val.end())q_actual--;
        else val[card_set] = avg;
    }
    vector<ll> vec;for(auto it:tot)vec.push_back(it);
    
    double mnm = 101, mxm = -100;
    if(q_actual < k){
        sort(vec.begin(), vec.end(), cmp);
        mnm = 0.0;mxm = 0.0;
        for(int i=0;i < n/k;i++){
            mnm += prof[vec[i] - 1];
            mxm += prof[vec[vec.size() - 1 - i] - 1];
        }
        mnm = mnm / (double)(n/k);
        mxm = mxm / (double)(n/k);
    }
    // cout << mnm << " " << mxm << endl;
    for(auto it: val) mnm = min(mnm, it.second);
    for(auto it: val) mxm = max(mxm, it.second);
    
    printf("%.10f %.10f\n", mnm, mxm);
}