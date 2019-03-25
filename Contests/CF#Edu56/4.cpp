#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll mod = 998244353 ;

ll pwr(ll x){
	if(x == 0)return (ll)1;
	ll tmp = pwr(x/2);
	tmp = (tmp * tmp) % mod ;
	if(x % 2 == 1)return (tmp * 2) % mod ;
	else return tmp ;
}

int main(){
	ll t; scanf("%lld",&t);
	for(int i=0;i<t;i++){
		ll n,m; scanf("%lld%lld",&n,&m);
		vector<set<ll>> adj(n+1);
		for(int i=1;i<=n;i++){
			set<ll> e;e.clear();
			adj[i] = e;
		}
		for(int i=0;i<m;i++){
			ll s,d; scanf("%lld%lld",&s,&d);
			adj[s].insert(d);adj[d].insert(s);
		}
		ll odd_cnt = 0, even_cnt = 0;
		int zero_flag = 0;
		vector<ll>visited(n+1), color(n+1);
		for(int i=1;i<=n;i++)visited[i] = 0;
		ll answer = 1;
		queue<ll> q;
		for(int i=1;i<=n;i++){
			if(visited[i] == 1)continue;

			q.push(i);color[i] = 0;even_cnt++;visited[i] = 1;
			while(!q.empty()){
				ll top = q.front();q.pop();
				for(auto it: adj[top]){
					if(!visited[it]){
						color[it] = 1 - color[top];
						if(color[it] == 0)even_cnt++;
						else odd_cnt++;
						
						visited[it] = 1;
						q.push(it);
					}
					else{
						if(color[it] != 1 - color[top]){
							zero_flag = 1;
							break;
						}
					}
				}
				if(zero_flag == 1)break;
			}
			if(zero_flag == 1)break;
			else{
				ll ans = (pwr(even_cnt) + pwr(odd_cnt)) % mod ;
				answer = (answer * ans) % mod ;
				even_cnt = 0;odd_cnt = 0;
			}
		}
		if(zero_flag == 1){
			printf("0\n");
		}
		else{
			printf("%lld\n", answer);
		}
	}	
}