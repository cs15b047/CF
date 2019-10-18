#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


set<set<ll>> pwr_set(set<ll> s){
	set<set<ll>> temp;
	if(s.empty()){
		set<ll> ss;temp.insert(ss);
		return temp;
	} else{
		ll ele = *s.rbegin();
		set<ll> s2 = s; s2.erase(ele);
		set<set<ll>> tmp1 = pwr_set(s2); temp = tmp1;
		for(auto it: tmp1){
			set<ll> xx = it;
			xx.insert(ele);
			temp.insert(xx);
		}
		return temp;
	}
}


int main(){
	ll t; scanf("%lld",&t);
	for(int q = 0;q < t;q++){
		ll n, s;scanf("%lld%lld",&n, &s);
		map<set<ll>, ll> skill_cnt;
		for(int i = 0;i < n;i++){
			ll c;scanf("%lld",&c);
			set<ll> skills;skills.clear();
			for(int j = 0;j < c;j++){
				ll sk;
				scanf("%lld",&sk);
				skills.insert(sk);
			}
			skill_cnt[skills]++;
		}
		// 0s
		ll zeros = 0, ones = 0, twos = 0;
		ll aa = 0;
		for(auto it:skill_cnt){
			aa++;
			zeros += (it.second * (it.second - 1)) / 2 ;
			set<set<ll>> pwr = pwr_set(it.first);
			pwr.erase(it.first);
			ll cnt = 0;
			for(auto it2: pwr){
				if(skill_cnt.find(it2) != skill_cnt.end())cnt += skill_cnt[it2];
			}
			ones += it.second * cnt;
		}
		twos = (n*(n - 1))/2 - (zeros + ones);
		ll ans = 2* twos + ones;
		printf("Case #%d: %lld\n",q + 1, ans );
	}
}