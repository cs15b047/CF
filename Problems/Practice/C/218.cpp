#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll n, m;
vector<vector<ll>> dist;
vector<string> grid;
vector<ll> visited_row, visited_col;

ll calc_dist(){
	queue<pair<ll,ll>> q;
	bool possible = false;
	for(int i = 0;i < m;i++){
		if(grid[0][i] == '#'){
			possible = true;
			dist[0][i] = 1;
			q.push(make_pair(0, i));
			visited_row[0] = 1;
		}
	}
	if(!possible)return -1;
	while(!q.empty()){
		pair<ll,ll> top = q.front();q.pop();
		// cout << top.first << " " << top.second << endl;
		if(visited_col[top.second] == 0){
			visited_col[top.second] = 1;
			for(int i = 0;i < n;i++){
				if(grid[i][top.second] == '#' && i != top.first){
					dist[i][top.second] = dist[top.first][top.second] + 1;
					q.push(make_pair(i, top.second));
				}
			}
		}
		if(visited_row[top.first] == 0){
			visited_row[top.first] = 1;
			for(int i = 0;i < m;i++){
				if(grid[top.first][i] == '#' && i != top.second){
					dist[top.first][i] = dist[top.first][top.second] + 1;
					q.push(make_pair(top.first, i));
				}
			}
		}
	}
	ll answer = 1e18;
	for(int i = 0; i < m;i++){
		answer = min(dist[n-1][i], answer);
	}
	
	if(answer >= 1e18)return -1;

	return answer;




}

int main(){
	cin >> n >> m;
	grid.resize(n);for(int i = 0;i < n;i++)cin >> grid[i];
	visited_row.resize(n, 0);
	visited_col.resize(m, 0);
	dist.resize(n, vector<ll>(m, 1e18));

	ll answer = calc_dist();
	cout << answer << endl;
}