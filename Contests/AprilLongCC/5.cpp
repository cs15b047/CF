#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll calc_gcd(ll a, ll b){
	if(b == 0)return a;
	return calc_gcd(b, a % b);
}

int main(){
	ll t; scanf("%lld",&t);
	for(int q=0;q<t;q++){
		ll n;scanf("%lld",&n);
		vector<vector<ll>>adj(n + 1);
		for(int i=0;i<n-1;i++){ll s,d;scanf("%lld%lld",&s,&d);adj[s].push_back(d);adj[d].push_back(s);}
		vector<ll> v(n + 1), m(n + 1), gcd(n + 1), visited(n + 1, 0), indegree(n + 1, 0);
		for(int i=1;i<=n;i++)scanf("%lld",&v[i]);for(int i=1;i<=n;i++)scanf("%lld",&m[i]);
		queue<ll> Q;Q.push(1);visited[1] = 1;
		gcd[1] = v[1];
		while(!Q.empty()){
			ll top = Q.front();Q.pop();
			for(auto it:adj[top]){
				if(!visited[it]){
					indegree[top]++;
					visited[it] = 1;
					Q.push(it);
					gcd[it] = calc_gcd(gcd[top], v[it]);
				}
			}
		}
		vector<ll> leaves;
		for(int i=1;i<=n;i++){
			if(indegree[i] == 0)leaves.push_back(i);
		}
		sort(leaves.begin(),leaves.end());
		for(auto it: leaves){
			ll answer;
			ll final_g = calc_gcd(gcd[it], m[it]);
			if(final_g == 1)answer = m[it] - 1;
			else answer = m[it] - final_g ;
			printf("%lld ",answer );
		}
		printf("\n");
	}
}