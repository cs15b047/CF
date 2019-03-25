#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

int main()
{
	ll n,m;cin>>n>>m;
	vector<ll>a(n);for(int i=0;i<n;i++)cin>>a[i];
	map<ll,ll> counts_under_m;
	for(int i=0;i<n;i++){
		if(a[i] <= m){
			counts_under_m[a[i]]++;
		}
	}
	for(int i=1;i<=m;i++)
		if(counts_under_m.find(i) == counts_under_m.end())
			counts_under_m[i] = 0;	
	ll ans2=0;
	
	for(auto it: counts_under_m){
		if(it.second < n/m)ans2 += n/m - it.second ;
	}
	cout << (n/m) << " "<< ans2 << endl ;

	auto it = counts_under_m.begin(); int j=0;
	while(it != counts_under_m.end() && it->second >= n/m)it++;
	while(j< n && it != counts_under_m.end()){
		if(a[j] > m){
			it->second++;
			a[j] = it->first ;			
		}
		else{
			if(counts_under_m[a[j]] > n/m){
				counts_under_m[a[j]]--;
				a[j] = it->first;
				it->second++;				
			}
		}
		j++;
		while(it != counts_under_m.end() && it->second >= n/m)it++;
	}
	for(auto it2:a)cout << it2 << " ";
	cout << endl;

}