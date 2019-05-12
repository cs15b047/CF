#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll t; scanf("%lld",&t);
	for(int z = 0; z < t; z++){
		ll n; scanf("%lld",&n);
		vector<string> grid(n);char s[102];for(int i=0;i<n;i++){scanf("%s",s);string str(s);grid[i] = str;}

		vector<vector<ll>> vis(n, vector<ll>(n, 0)), indegree(n, vector<ll>(n, 0));
		vector<vector<set<pair<ll,ll>>>> adj(n);
		queue<pair<ll,ll>> q;

		for(int i=0;i<n;i++){
			adj[i].resize(n);
			for(int j=0;j<n;j++){
				if(i < n - 1 && grid[i][j] == 'O'){
					adj[i][j].clear();
					if(j >= 1 && grid[i + 1][j - 1] == 'O'){
						indegree[i + 1][j - 1]++;
						adj[i][j].insert(make_pair(i + 1, j - 1));
					}
					if(j < n - 1 && grid[i + 1][j + 1] == 'O'){
						indegree[i + 1][j + 1]++;
						adj[i][j].insert(make_pair(i + 1, j + 1));
					}
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(indegree[i][j] == 0 && grid[i][j] == 'O'){
					q.push(make_pair(i, j));
					vis[i][j] = 1;
					// cout << i << " " << j << endl;
				}
			}
		}

		ll moves = 0;
		vector<pair<ll,ll>> coord;
		vector<string> dir;
		while(!q.empty()){
			pair<ll,ll> top = q.front();q.pop();
			
			for(auto it: adj[top.first][top.second]){

				if(!vis[it.first][it.second]){

					vis[it.first][it.second] = 1;

					coord.push_back(it);
					if(top.second == it.second + 1)dir.push_back("R");
					else dir.push_back("L");
					moves++;
					
					// top sort nxt step
					for(auto it2 : adj[it.first][it.second]){
						indegree[it2.first][it2.second]--;
						if(indegree[it2.first][it2.second] == 0){
							q.push(make_pair(it2.first,it2.second));
							vis[it2.first][it2.second] = 1;
						}
					}
				}
			}
		}
		printf("%lld\n",moves);
		for(int i=0;i<moves;i++)cout << coord[i].first + 1 <<" " << coord[i].second + 1 << " " << dir[i] << endl;
	}
}