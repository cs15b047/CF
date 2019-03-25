#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

int main(int argc, char const *argv[])
{
	ll n ;cin >>n ;vector<ll>v(n);for (ll i = 0; i < n; ++i)cin>>v[i];
	map<ll,ll> cnt,cnt2 ;
	for(ll i=0;i<n;i++)cnt[v[i]]++ ;
	ll first = -1 ;

	if(n == 1){cout<<0<<endl;exit(0);}

	for(auto it = cnt.rbegin();it != cnt.rend();it++)
	{
		if(it->second % 2 == 1){
			if(cnt.find(it->first - 1) != cnt.end()){
				cnt[it->first]--;
				cnt[it->first-1]++;
			}
			else{
				cnt[it->first]--;				
			}
		}
	}
	cnt2 = cnt ;
	for(auto it: cnt){
		if(it.second == 0)cnt2.erase(it.first) ;
	}
	cnt = cnt2 ;
	vector<ll> s;
	for(auto it: cnt){
		for(int i=0;i<it.second/2;i++)s.push_back(it.first);
	}
	// cout << s.size()<<endl;
	ll ans=0;
	for(ll i=0;i<s.size()-1;i+=2){
		ans += s[s.size()-1-i]*s[s.size()-1-i-1];
	}
	cout <<ans<<endl;

	return 0;
}