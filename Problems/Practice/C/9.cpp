#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;
ll mod = 1e9+7;
int main(int argc, char const *argv[])
{
	int n,m;cin>>n>>m;
	vector<string> str(n) ;
	for(int i=0;i<n;i++)cin>>str[i] ;
	set<ll> cnt ;
	ll ans = 1 ;
	for(int i=0;i<m;i++){
		cnt.clear();
		for(int j=0;j<n;j++)cnt.insert(str[j][i]) ;
		ans = (ans * cnt.size()) % mod ;
	}
	cout << ans << endl ;

	return 0;
}