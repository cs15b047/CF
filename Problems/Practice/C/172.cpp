#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

ll matrix[3001][3001]={};
int main(){
	ll n, m; scanf("%lld%lld",&n,&m );
	vector<vector<ll>> adj(n + 1);
	for(int i=0;i<m;i++){
		ll s,d; scanf("%lld%lld",&s,&d );
		adj[s].push_back(d);
		matrix[s][d] = 1;
	}
	ll answer = 0;
	for(int i =1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(i != j){
				ll in_bw = 0;
				for(auto nbh: adj[i]){
					if(matrix[nbh][j] == 1)in_bw++;
				}
				answer += (in_bw * (in_bw - 1)) / 2 ;
			}
		}
	}
	printf("%lld\n",answer );


}