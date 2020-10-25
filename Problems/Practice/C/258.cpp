#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll mod = 998244353;

map<ll, ll> light_on_info, light_off_info;
set<ll> time_points;
vector<ll> facts;
ll n, k;

void init(){
    light_off_info.clear();
    light_on_info.clear();
    time_points.clear();
}

void take_input(){
    scanf("%lld%lld", &n, &k);
    for(ll i = 0;i < n;i++){
        ll start, end;
        scanf("%lld%lld", &start, &end);
        light_on_info[start]++;
        light_off_info[end]++;
        time_points.insert(start);
        time_points.insert(end);
    }
}

static inline ll pwr(ll base, ll idx){
    if(idx == 0)return 1;
    ll tmp = pwr(base, idx/2);
    tmp = (tmp * tmp) % mod;
    if(idx % 2 == 0)return tmp;
    return (tmp * base) % mod;
}

static inline ll mod_inv(ll n){
    if(n == 1)return 1;
    return pwr(n, mod - 2);
}

static inline ll nCr(ll n, ll r){
    if(n < r)return 0;
    if(n == r)return 1;
    if(n == 0) return 1;
    ll denom = (facts[n - r] * facts[r]) % mod;
    return (facts[n] * mod_inv(denom)) % mod;
}

ll count_answer(pair<ll,ll>& switch_info, ll threshold){
    // cout <<"Switch info" << endl;
    // cout << switch_info.first << " " << switch_info.second << endl;
    if(switch_info.first == threshold)return 1;

    ll x = switch_info.second, n = switch_info.first;
    ll answer = 0, max_iters = min(x, threshold);
    for(ll i = 1;i <= max_iters;i++){
        ll term1 = nCr(x, i);
        ll term2 = nCr(n - x, threshold - i);
        answer  = (answer + (term1 * term2) % mod) % mod;
    }
    return answer;
}

ll get_ans(ll threshold){
    vector<pair<ll,ll>> light_switch_info;
    ll available_lights = 0;
    ll answer = 0;
    
    for(auto point: time_points){
        pair<ll,ll> switch_info;
        ll on = light_on_info[point], off = light_off_info[point];
        available_lights += on;
        switch_info = make_pair(available_lights, off);
        available_lights -= off;
        if(switch_info.first >= threshold && switch_info.second > 0){
            // light_switch_info.push_back(switch_info);
            ll step_ans = count_answer(switch_info, k);
            cout << step_ans << endl;
            answer = (answer + step_ans) % mod;
        }
    }
    
    return answer;
}

int main(){
    init();
    take_input();

    facts.resize(n + 1); facts[0] = 1;
    for(ll i = 1;i <= n;i ++) facts[i] = (facts[i - 1] * i) % mod;

    ll answer = get_ans(k);
    cout << answer << endl;
	return 0;
}

