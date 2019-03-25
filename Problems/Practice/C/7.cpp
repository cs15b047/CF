#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

vector<pair<ll,ll>> guests ;

bool compa(ll x,ll y){	
	pair<ll,ll> a = guests[x],b=guests[y];
	if(a.second > b.second)return true;
	else if(a.second == b.second){
		if(a.first < b.first)return true;
		return false;
	}
	return false ;
}

int main()
{
	int n;cin>>n;	
	vector<ll> guests_idx(n);
	for(int i=0;i<n;i++)guests_idx[i] = (ll)i ;
	for(int i=0;i<n;i++){
		ll x,y;cin>>x>>y;
		guests.push_back(make_pair(x,y));
	}
	int k;cin>>k;
	vector<ll>t(k);
	for(int i=0;i<k;i++)cin>>t[i];

	sort(guests_idx.begin(),guests_idx.end(),compa);

	map<ll,vector<ll>> table_cnt; for(int i=0;i<k;i++)table_cnt[t[i]].push_back(i);

	ll ans = 0,count=0 ;
	vector<pair<ll,ll>> alloc;
	for (int i = 0; i < n; ++i)
	{
		ll index = guests_idx[i] ;
		ll size = guests[index].first ;
		if (table_cnt.find(size) != table_cnt.end())
		{
			ll idx = table_cnt[size].back();
			table_cnt[size].pop_back();
			if(table_cnt[size].size()== 0)table_cnt.erase(size);
			ans += guests[index].second ;
			count++;
			alloc.push_back(make_pair(index+1, idx+1)) ;
		}
		else{
			auto it = table_cnt.upper_bound(size);
			if(it != table_cnt.end()){
				ll idx = it->second.back();
				it->second.pop_back();
				if(it->second.size() == 0)table_cnt.erase(it) ;
				ans += guests[index].second ;
				count++;
				alloc.push_back(make_pair(index+1, idx+1)) ;
			}
		}
	}
	cout << count << " " << ans << endl ;
	for (int i = 0; i < alloc.size(); ++i)	
		cout << alloc[i].first << " " << alloc[i].second <<endl ;	

	return 0;
}