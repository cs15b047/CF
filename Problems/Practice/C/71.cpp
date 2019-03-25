#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;
ll high = 1e18;
int main(){
	ll n,m,k;cin>>n>>m>>k;
	vector<ll> c(n+1);
	for(int i=1;i<=n;i++)cin >> c[i];
	vector<vector<ll>>cost(n+1);
	for(int i=1;i<=n;i++){
		cost[i].resize(m+1);
		for(int j=1;j<=m;j++)cin>>cost[i][j];
	}
	ll dp[101][101][101];
	for(int i=1;i<=n;i++)for(int j=i+1;j<=k;j++)for(int l=1;l<=m;l++)dp[i][j][l] = high;

	for(int j=1;j<=k;j++)for(int l=1;l<=m;l++)dp[0][j][l] = high;
	for(int j=1;j<=n;j++)for(int l=1;l<=m;l++)dp[j][0][l] = high;
	for(int l=1;l<=m;l++)dp[0][0][l] = 0;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=min((ll)i,k);j++){
			map<ll,int> prev;prev.clear();
			for(int l=1;l<=m;l++)prev[dp[i-1][j-1][l]]++;
			// cout << "Map:"<<endl;
			// for(auto it: prev)cout << it.first <<" " << it.second <<endl;
			for(int l=1;l<=m;l++){
				ll p1=high,p2=high;
				if(c[i] != 0 && c[i] != l)dp[i][j][l] = high;
				else{
					p1 = dp[i-1][j][l];
					ll smallest = prev.begin()->first;
					if(smallest != dp[i-1][j-1][l])p2 = smallest ;
					else if(prev[smallest] != 1)p2 = smallest;
					else if(prev.size() > 1)p2 = (++prev.begin())->first ;

					dp[i][j][l] = min(p1,p2);
					if(c[i]==0)dp[i][j][l] += cost[i][l] ;
					if(i==1 && c[i]==0)dp[i][j][l] = cost[i][l];
					else if(i==1 && c[i] == l)dp[i][j][l] = 0 ;
				}
				// cout << i << " " << j << " " << l << " " << p1 << " " << p2 << " "<<  dp[i][j][l] << endl ;
			}
		}
	}
	ll ans=high;
	for(int l=1;l<=m;l++)ans = min(ans,dp[n][k][l]);
	if(ans == high)cout<<-1<<endl;
	else cout << ans << endl ;
}