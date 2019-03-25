#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n,m,k;cin >> n >>m >> k;
	vector<ll> power(n + 1), school(n + 1);for(int i=1;i<=n;i++)cin >> power[i];
	for(int i=1;i<=n;i++)cin >> school[i];
	set<ll> chosen;
	for(int i=1;i<=k;i++){
		ll s;cin >> s;
		chosen.insert(s);
	}

	vector<ll> strongest(m +1, 0);
	for(int i=1;i<=n;i++){
		if(power[i] > power[strongest[school[i]]])strongest[school[i]] = i;
	}
	ll ans = 0;
	for(int i=1;i<=m;i++){
		if(chosen.find(strongest[i]) != chosen.end())chosen.erase(strongest[i]);
	}
	cout << chosen.size() << endl;
}