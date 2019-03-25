//C. Mail Stamps -->#29 -- dv 2
// straight path
#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n; cin >> n ;
	map<ll,ll> degree;
	map<ll,set<ll>> nbhs;
	for(ll i=0;i<n;i++){
		ll s,d;scanf("%lld%lld",&s,&d);
		degree[s]++;degree[d]++;
		nbhs[s].insert(d);nbhs[d].insert(s);
	}
	ll start;
	for(auto it:degree){
		if(it.second == 1){
			start = it.first;break;
		}
	}
	cout << start << " ";
	for(int i=0;i<n;i++){
		ll node = *nbhs[start].begin();
		nbhs[node].erase(start);
		nbhs[start].erase(node);
		start = node ;
		cout << start << " ";
	}

}