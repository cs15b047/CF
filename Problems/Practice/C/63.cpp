#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;
int main(){
	ll n;cin>>n;
	vector<ll>v(n),d(n),p(n);
	for(int i=0;i<n;i++)scanf("%lld%lld%lld",&v[i],&d[i],&p[i]);
	vector<ll>init(n);for(int i=0;i<n;i++)init[i] = i;
	ll ans = 0 ;vector<ll>answer;
	while(!init.empty()){
		vector<ll>tmp;tmp.clear();
		for(int i=0;i<init.size();i++){
			if(p[init[i]] < 0){
				for(int j=i+1;j<init.size();j++){
					p[init[j]] -= d[init[i]] ;
				}
			}
		}
		for(auto it: init){
			if(p[it] >= 0)tmp.push_back(it);
		}
		if(tmp.empty())break;
		ans++;
		ll first = tmp[0];
		answer.push_back(first+1);
		tmp.erase(tmp.begin());
		for(int i=0;i<min(v[first], (ll)tmp.size());i++){
			p[tmp[i]] -= (v[first] - i);
		}
		init = tmp ;
	}
	cout << ans << endl ;
	for(auto it: answer)cout << it << " " ;


}