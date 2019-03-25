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
	
	for(ll i=1;i<=strlen(str);i++){
		symbol[i] = (int)(str[i-1] - 'a') ;
	}
	adj.resize(n+1);
	ll indegree[300001]={},visited[300001]={};
	ll s,d;
	for(ll i=0;i<m;i++){
		scanf("%lld%lld",&s,&d);
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
				dp[i][symbol[i]] = 1;
			}
		}
		ll answer = 0;
		while(!q.empty()){
			ll top = q.front();q.pop();
			for(auto nbh: adj[top]){
				if(!visited[nbh]){
					for(int letter =0;letter<26;letter++)
						dp[nbh][letter] = max(dp[nbh][letter], dp[top][letter] + (symbol[nbh] == letter));
					indegree[nbh]--;
					if(indegree[nbh] == 0){
						q.push(nbh);
						visited[nbh] = 1;
						cnt++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<26;j++){
				answer = max(answer, dp[i][j]);
			}
		}
		if(cnt < n)printf("-1\n");
		else printf("%lld\n",answer );
	}
}