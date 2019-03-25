#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;
ll prm = 100003,high=100003;
int main()
{
	ll n,m;cin>>n>>m;
	vector<vector<pair<ll,ll>>> adj(n+1);
	for(int i=1;i<n;i++){
		if(i != n-1)adj[i].push_back(make_pair(i+1,1));
		else adj[i].push_back(make_pair(i+1, prm-(n-2)));
	}
	ll curr = 1;
	for(int j=n;j<=m;){
		ll tmp = curr + 2;
		while(j <= m && tmp <= n){
			adj[curr].push_back(make_pair(tmp,high));
			tmp++;
			j++;
		}
		curr++;
	}
	cout << prm << " " <<  prm << endl;
	for(int i=1;i<=n;i++){
		for(auto nbh:adj[i]){
			cout << i << " "<< nbh.first << " "<< nbh.second << endl;
		}
	}
	return 0;
}