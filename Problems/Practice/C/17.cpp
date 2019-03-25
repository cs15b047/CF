#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

int main(int argc, char const *argv[])
{
	int n;cin>>n;
	vector<ll>x(n),y(n);
	for(int i=0;i<n;i++)cin >> x[i]>>y[i];

	map<ll,vector<ll>> x_c,y_c;
	map<pair<ll,ll>,vector<ll>> p_c ;
	for(int i=0;i<n;i++){
		x_c[x[i]].push_back(i) ;
		y_c[y[i]].push_back(i) ;
		p_c[make_pair(x[i],y[i])].push_back(i) ;
	}
	ll ans = 0;
	for(auto it:x_c){
		ll s = (ll)it.second.size();
		ans += (s*(s-1))/2 ;
	}
	for(auto it:y_c){
		ll s = (ll)it.second.size();
		ans += (s*(s-1))/2 ;
	}
	for(auto it:p_c){
		ll s = (ll)it.second.size();
		ans -= (s*(s-1))/2 ;
	}

	cout << ans <<endl ;


	return 0;
}