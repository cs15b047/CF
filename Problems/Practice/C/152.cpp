#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){	
	ll n, m; cin >> n >> m;
	vector<vector<ll>> g(n, vector<ll>(m));
	ll mnm = 1e18, x = 0,y = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> g[i][j];
			if(mnm > g[i][j]){
				mnm = g[i][j];x = i; y= j;
			}
		}
	}
	vector<pair<ll,ll>> steps;
	ll ans = mnm * min(m,n);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			g[i][j] -= mnm ;
		}
	}
	for(ll i=0;i<mnm;i++){
		for(int j=1;j <= min(m,n);j++){
			steps.push_back(make_pair((n < m) - (n >= m), j));
		}
	}

	int flag = 1;
	for(int i=0;i<n;i++){
		if(i != x){
			ll locl_mnm = g[i][0];
			for(int j = 0;j <m ;j++)locl_mnm = min(locl_mnm, g[i][j]);
			// printf("%d %d\n",i, locl_mnm );
			if(g[i][y] != locl_mnm){
				flag = 0;
				break;
			}
			else if(locl_mnm != 0){
				ans += locl_mnm ;
				for(int j = 0;j <m ;j++)g[i][j] -= locl_mnm;
				for(ll k=0;k < locl_mnm;k++){					
					steps.push_back(make_pair(1, i + 1));					
				}
			}
		}
	}
	for(int i=0;i<m;i++){
		if(i != y){
			ll locl_mnm = g[0][i];
			// printf("%d %d\n",i, locl_mnm );
			for(int j = 0;j <n ;j++)locl_mnm = min(locl_mnm, g[j][i]);
			if(g[x][i] != locl_mnm){
				flag = 0;
				break;
			}
			else if(locl_mnm != 0){
				ans += locl_mnm ;
				for(int j = 0;j <n ;j++)g[j][i] -= locl_mnm;
				for(ll k=0;k < locl_mnm;k++){
					steps.push_back(make_pair(-1, i + 1));
				}
			}
		}
	}
	if(!flag){
		cout << -1 << endl;
	}
	else{
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(g[i][j] != 0){flag = 0;break;}
			}
			if(flag == 0)break;
		}
		if(!flag)cout << - 1<< endl;
		else{
			printf("%lld\n",ans );
			for(auto it:steps){
				if(it.first == 1)printf("row %lld\n",it.second );
				else printf("col %lld\n",it.second );
			}
		}
	}
}