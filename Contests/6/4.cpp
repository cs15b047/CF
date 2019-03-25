#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

int main()
{
	ll n,h;cin>>n>>h;
	vector<pair<ll,ll>>x(n);
	map<ll,ll> end2index,strt2index;
	for(int i=0;i<n;i++){
		ll a1,a2;
		scanf("%lld%lld",&a1,&a2);
		x[i] = make_pair(a1,a2);		
	}
	sort(x.begin(),x.end());
	for(int i=0;i<n;i++){
		end2index[x[i].second] = i;
		strt2index[x[i].first] = i;
	}
	vector<pair<ll,ll>> gaps;
	vector<ll> length;
	
	for(int i=0;i<n;i++){
		if(i!=n-1){
			gaps.push_back(make_pair(x[i].second,x[i+1].first));
			length.push_back(-x[i].second + x[i+1].first);
		}
		else{
			gaps.push_back(make_pair(x[i].second,(ll)1000000000000));
			length.push_back((ll)1000000000000-x[i].second);
		}
	}
	for (int i = 1; i < length.size(); ++i)	
		length[i]+=length[i-1];	

	ll ans = h ;
	for(int i=0;i<length.size();i++)
	{
		ll sub,tot;		
		if(i == 0)sub = 0;		
		else sub = length[i-1];
		ll start = x[end2index[gaps[i].first]].first;

		auto it = lower_bound(length.begin(),length.end(),sub+h);
		if(*it == sub + h){
			ll idx = it - length.begin();
			ll end = gaps[idx].second;
			ans = max(ans, end- start);
		}
		else{
			ll idx = it - length.begin();
			ll to_add = 0;
			if(idx == 0)to_add = h;
			else to_add = sub + h - length[idx - 1];
			ll end = gaps[idx].first + to_add;
			ans = max(ans, end - start) ;
		}
	}
	cout << ans << endl ;


}