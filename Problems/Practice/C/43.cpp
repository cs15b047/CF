#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

int main()
{
	ll n,q,c;scanf("%lld%lld%lld",&n,&q,&c);
	map<pair<ll,ll>,ll> cnt;
	map<pair<ll,ll>,vector<ll>> bright1,bright;
	for(int i=0;i<n;i++){
		ll x,y,s;scanf("%lld%lld%lld",&x,&y,&s);
		bright1[make_pair(x,y)].push_back(s);
		cnt[make_pair(x,y)]++;
	}
	for(auto it:bright1){		
		vector<ll> v(c+1);
		for(int j=0;j<=c;j++){
			ll tmp = 0;
			for(auto it2 : it.second){
				tmp += ((it2 + j) % (c+1));
			}
			v[j] = tmp ;
		}
		bright[it.first] = v ;
	}

	vector<vector<vector<ll>>> dp(c+1);
	for(int i=0;i<dp.size();i++){
		dp[i].resize(101);
		for(int j=0;j<=100;j++)dp[i][j].resize(101);
	}

	for(int i=0;i<=c;i++){
		dp[i][0][0] = 0;
		for(int j=1;j<=100;j++)dp[i][j][0] = 0 ;
		for(int j=1;j<=100;j++)dp[i][0][j] = 0 ;
		for(int j=1;j<=100;j++){
			for(int k=1;k<=100;k++){
				dp[i][j][k] = dp[i][j][k-1] + dp[i][j-1][k] - dp[i][j-1][k-1];
				if(bright.find(make_pair(j,k)) != bright.end()){
					dp[i][j][k] += bright[make_pair(j,k)][i];
				}
			}
		}
	}

	for(int i=0;i<q;i++){
		ll t,x1,x2,y1,y2;scanf("%lld%lld%lld%lld%lld",&t,&x1,&y1,&x2,&y2);
		t = t % (c+1);
		ll ans = dp[t][x2][y2] - dp[t][x2][y1-1] - dp[t][x1-1][y2] + dp[t][x1-1][y1-1] ;
		cout <<  ans << endl ;
	}







}