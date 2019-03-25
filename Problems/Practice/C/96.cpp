// C. Kuro and Walking Route - #482 - 2
// Ans = Subtree size(node 1) * Subtree size(node 2)
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<set<ll>> adj;
vector<ll> pth;
void dfs(ll curr, ll parent, ll dest){
	pth.push_back(curr);
	if(curr == dest)return;
	for(auto it: adj[curr]){
		if(it != parent){
			dfs(it,curr, dest);
			if(pth.back() == dest)return;
		}
	}
	pth.pop_back();
}

int main(){
	ll n,x,y;cin >> n >> x >> y ;
	adj.clear();adj.resize(n+1);
	for(int i=0;i<n-1;i++){
		ll src,dest;
		scanf("%lld%lld",&src,&dest);
		adj[src].insert(dest);
		adj[dest].insert(src);
	}
	pth.clear();
	dfs(x, -1, y);

	// for(auto it:pth)cout << it << " ";

	adj[x].erase(pth[1]);
	adj[y].erase(pth[pth.size()-2]);

	ll count1=1,count2 =1;
	bool visited[300001]={};
	queue<ll> q;
	q.push(x);visited[x]=1;
	while(!q.empty()){
		ll top=q.front();q.pop();
		for(auto it:adj[top]){
			if(!visited[it]){
				visited[it] = 1;
				count1++;
				q.push(it);
			}
		}
	}
	q.push(y);visited[y]=1;
	while(!q.empty()){
		ll top=q.front();q.pop();
		for(auto it:adj[top]){
			if(!visited[it]){
				visited[it] = 1;
				count2++;
				q.push(it);
			}
		}
	}

	ll answer = n*(n-1) - (count1 * count2) ;
	cout << answer << endl;

}