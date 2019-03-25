#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	int n, x; cin >> n >> x ;
	vector<set<int>> adj(n+1);
	for(int i=1;i<=n-1;i++){
		int s,d; cin >> s >> d ;
		adj[s].insert(d);
		adj[d].insert(s);
	}
	vector<int> distance(n + 1), parent(n + 1);
	vector<bool> visited(n + 1);
	queue<int> q;
	for(int i=1;i<=n;i++)visited[i] = 0;
	q.push(1);distance[1] = 0;visited[1] = 1;parent[1] = -1 ;
	while(!q.empty()){
		int top = q.front(); q.pop();
		for(auto nbh:adj[top]){
			if(!visited[nbh]){
				visited[nbh] = 1;
				distance[nbh] = distance[top] + 1;
				q.push(nbh);
				parent[nbh] = top;
			}
		}
	}
	vector<int>path;path.clear();
	int curr = x;
	while(curr != -1 && (distance[x] - distance[curr]  < distance[curr])){
		path.push_back(curr);
		curr = parent[curr] ;
	}

	int uppermost = path.back();
	for(int i=1;i<=n;i++)visited[i] =  0;
	
	int answer = distance[uppermost];
	visited[uppermost] = 1;q.push(uppermost);
	while(!q.empty()){
		int top = q.front();q.pop();
		for(auto nbh:adj[top]){
			if(!visited[nbh] && nbh != parent[top]){
				q.push(nbh);visited[nbh] = 1;
				answer = max(answer, distance[nbh]);
			}
		}
	}
	answer = 2 * answer ;
	cout << answer << endl ;
}