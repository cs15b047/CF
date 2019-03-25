// C. The Labyrinth --> Educational round 5
// Do BFS and assign components to empty cells
// For each obstacle cell, take all component # beside it and add component sizes
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll n,m; cin >> n >> m ;
	vector<string> grid(n);for(int i=0;i<n;i++){char str[1001];scanf("%s",str);string s(str);grid[i] = s;}

	bool visited[1001][1001]={};
	map<pair<ll,ll>, ll> comp_mapping;
	map<ll,ll> comp_size;
	ll curr = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(!visited[i][j] && grid[i][j] != '*'){
				curr++;
				queue<pair<ll,ll>> q;
				q.push(make_pair(i,j));
				visited[i][j] = 1;
				comp_mapping[make_pair(i,j)] = curr;
				comp_size[curr]++;

				while(!q.empty()){
					pair<ll,ll> top = q.front();q.pop();
					if(top.first >=1 && !visited[top.first-1][top.second] && grid[top.first-1][top.second] != '*'){
						q.push(make_pair(top.first-1,top.second));
						visited[top.first-1][top.second] = 1;
						comp_mapping[make_pair(top.first-1,top.second)] = curr;
						comp_size[curr]++;
					}
					if(top.first < n-1 && !visited[top.first+1][top.second] && grid[top.first+1][top.second] != '*'){
						q.push(make_pair(top.first+1,top.second));
						visited[top.first+1][top.second] = 1;
						comp_mapping[make_pair(top.first+1,top.second)] = curr;
						comp_size[curr]++;
					}
					if(top.second >=1 && !visited[top.first][top.second-1] && grid[top.first][top.second-1] != '*'){
						q.push(make_pair(top.first,top.second-1));
						visited[top.first][top.second-1] = 1;
						comp_mapping[make_pair(top.first,top.second-1)] = curr;
						comp_size[curr]++;
					}
					if(top.second < m - 1 && !visited[top.first][top.second+1] && grid[top.first][top.second+1] != '*'){
						q.push(make_pair(top.first,top.second+1));
						visited[top.first][top.second+1] = 1;
						comp_mapping[make_pair(top.first,top.second+1)] = curr;
						comp_size[curr]++;
					}
				}
			}
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(grid[i][j] == '*'){
				map<ll,ll> exist;exist.clear();
				if(i>=1 && grid[i-1][j] == '.')exist[comp_mapping[make_pair(i-1,j)]] = 1;
				if(j>=1 && grid[i][j-1] == '.')exist[comp_mapping[make_pair(i,j-1)]] = 1;
				if(i<n-1 && grid[i+1][j] == '.')exist[comp_mapping[make_pair(i+1,j)]] = 1;
				if(j<m-1 && grid[i][j+1] == '.')exist[comp_mapping[make_pair(i,j+1)]] = 1;
				ll ans = 0;
				for(auto it:exist){
					if(exist[it.first] == 1)ans += comp_size[it.first];
				}
				ans = (ans+1) % 10;
				grid[i][j] = ('0' + ans);
			}
		}
	}

	for(int i=0;i<n;i++)
		printf("%s\n", grid[i].c_str());





}