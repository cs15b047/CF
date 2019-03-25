#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int symbol[300001]={};
ll dp[300001][26]={};
vector<set<ll>> adj;

ll calc_ans(ll node, ll letter){
	if(dp[node][letter] != -1)return dp[node][letter];

	dp[node][letter] = (symbol[node] == letter);
	ll max_nbh = 0;
	for(auto nbh:adj[node]){
		dp[nbh][letter] = calc_ans(nbh, letter);
		max_nbh = max(max_nbh, dp[nbh][letter]);
	}
	dp[node][letter] += max_nbh ;
	return dp[node][letter] ;
}

int main(){
	int done = 0;
	ll  n, m; scanf("%lld%lld",&n,&m);
	char str[300001];scanf("%s",str);
	set<ll> present;
	for(ll i=1;i<=strlen(str);i++){
		symbol[i] = (ll)(str[i-1] - 'a') ;
		present.insert(symbol[i]);
	}
	adj.resize(n+1);
	ll indegree[300001]={},visited[300001]={};
	for(ll i=0;i<m;i++){
		ll s,d; scanf("%lld%lld",&s,&d);
		if(s == d)done = 1;
		if(adj[s].find(d) == adj[s].end()){
			indegree[d]++;
			adj[s].insert(d);
		}
	}

	if(done == 1)printf("-1\n");
	else{

		queue<ll> q;
		ll cnt = 0;
		for(ll i=1;i<=n;i++){
			if(indegree[i] == 0){
				q.push(i);
				visited[i] = 1;
				cnt++;
			}
		}

		while(!q.empty()){
			ll top = q.front();q.pop();
			for(auto nbh: adj[top]){
				indegree[nbh]--;
				if(indegree[nbh] == 0){
					q.push(nbh);
					// visited[nbh] = 1;
					cnt++;
				}
			}
		}

		if(cnt < n)printf("-1\n");
		else{
			for(ll i=1;i<=n;i++){
				for(ll j=0;j<26;j++){
					if(present.find(j) != present.end())dp[i][j] = -1;
				}
			}
			ll answer = 0;
			for(ll j=0;j<26;j++){
				if(present.find(j) != present.end()){
					for(ll i=1;i<=n;i++){
						if(dp[i][j] == -1)dp[i][j] = calc_ans(i,j);
						answer = max(dp[i][j], answer);
					}
				}
			}
			printf("%lld\n",answer);
		}
	}
}