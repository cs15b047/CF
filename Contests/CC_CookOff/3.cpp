#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll t; cin >> t;
	for(int q=0;q<t;q++){
		ll n,a,b,x,y,z;cin >> n >> a >> b >> x >> y >> z;
		vector<ll> contr(n);for(int i=0;i<n;i++)cin >> contr[i];
		ll sm = 0;
		map<ll,ll> counts;for(int i=0;i<n;i++)counts[contr[i]]++;
		ll t1,t2;
		t1 = (ll)ceil((float)(z - a)/(float)x);t2 = (ll)ceil((float)(z - b)/(float)y);
		ll reqd = max((ll)0, z - a - x * (t2 - 1));
		ll cnt=0;
		while(!counts.empty() && sm < reqd){
			auto it = counts.rbegin();
			if(it->first /2 != 0)counts[it->first/2]++;
			sm+= it->first;it->second--;if(it->second == 0)counts.erase(it->first);cnt++;
		}
		if(counts.empty() && sm < reqd)cout << "RIP" << endl;
		else{
			cout << cnt << endl;
		}
	}	
}