#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

int main()
{
	ll n,m;scanf("%lld%lld",&n,&m);
	vector<ll> l(m),r(m),x(m);

	for(int i=0;i<m;i++)scanf("%lld%lld%lld",&l[i],&r[i],&x[i]);
	map<ll,ll> m1,m2 ;	
	for(ll i=1;i<=n;i++)m1[i]=1;
	m2[x.back()] = 0;
	for(int i=0;i<m;i++)
	{
		auto it = m1.find(l[i]);
		if(it == m1.end())it = m1.upper_bound(l[i]);
		set<ll>tbr;
		while(it != m1.end() && it->first <= r[i]){
			if(it->first != x[i]){
				m2[it->first] = x[i] ;
				tbr.insert(it->first);
			}
			it++;
		}
		for(auto ele:tbr)m1.erase(ele);
	}

	for(auto itr:m2){
		cout << itr.second << " " ;
	}

}