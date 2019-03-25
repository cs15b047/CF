#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

ll n, m, k, w;
vector<string> grids;
vector<ll> visited;

ll get_diff(string A, string B){
	ll l =  A.length();
	ll ans = 0;
	for(int i=0;i < l;i++){
		ans += (A[i] != B[i]);
	}
	return ans;
}
vector<ll> parents;

void union_by_rank(ll a, ll b){
	if(abs(parents[a]) < abs(parents[b])){
		parents[a] = b;
	}
	else if(abs(parents[a]) > abs(parents[b])){
		parents[b] = a;
	}
	else{
		parents[b] = a;
		parents[a]--;
	}
}
vector<vector<ll>> Edges;
ll find_pth_compr(ll node){
	if(parents[node] < 0)return node;
	ll anc = find_pth_compr(parents[node]);
	parents[node] = anc;
	return anc;
}

vector<set<ll>> adj;
void dfs(ll node){
	visited[node] = 1;
	for(auto it: adj[node]){
		if(!visited[it]){
			parents[it] = node;
			dfs(it);
		}
	}
}


int main(){
	scanf("%lld%lld%lld%lld",&n,&m,&k,&w);
	grids.resize(k + 1);
	for(ll i=1;i<=k;i++){
		grids[i] = "";
		for(ll j = 0;j < n;j++){
			char s[11];
			scanf("%s",s);
			string str(s); grids[i] += str;
		}
	}

	if(k == 1)printf("%lld\n1 0\n",n*m);
	else{
		for(ll i = 1;i <= k; i++){
			for(ll j = i + 1;j <= k; j++){
				ll diff = get_diff(grids[i], grids[j]);
				vector<ll> edge(3);
				edge[0] = diff*w; edge[1] = i; edge[2] = j;
				Edges.push_back(edge);
			}
		}
		sort(Edges.begin(), Edges.end());

		parents.resize(k + 1);
		visited.resize(k + 1);
		for(ll i = 1;i <= k;i++)parents[i] = -1;

		
		ll tot_edges = 0, tot_cost = m*n;
		vector<pair<ll,ll>> op;
		op.push_back(make_pair(Edges[0][1], 0));
		visited[Edges[0][1]] = 1;
		ll sz = Edges.size();

		set<ll> st;
		adj.resize(k + 1);
		for(ll i = 0;i < sz;i++){
			ll a1 = find_pth_compr(Edges[i][1]), a2 = find_pth_compr(Edges[i][2]);
			if(a1 == a2)continue;
			else union_by_rank(a1, a2);
			tot_cost += min(Edges[i][0], m*n);
			st.insert(i);
			adj[Edges[i][1]].insert(Edges[i][2]);
			adj[Edges[i][2]].insert(Edges[i][1]);
		}
		printf("%lld\n",tot_cost );

		for(ll i = 1;i <= k;i++)visited[i] = 0;
		for(ll i = 1;i <= k;i++)parents[i] = -1;
		printf("%lld 0\n",Edges[i][2]);
		dfs(Edges[i][2]);
		for(ll i = 1;i <= k;i++)visited[i] = 0;
		for(auto it: st){
			if(parents[Edges[it][1]] == Edges[it][2])
		}

	}
}