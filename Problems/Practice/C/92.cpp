//D. Lakes in Berland
// #375 - 2
// calc all lakes and sort by size and keep largest k ones
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll n,m,k;
vector<string> grid;
vector<set<pair<ll,ll>>> lakes;
map<pair<ll,ll>, bool> visited;

set<pair<ll,ll>> curr;
bool lake_flag;

bool comp(set<pair<ll,ll>> s1, set<pair<ll,ll>> s2){
	return s1.size() < s2.size() ;
}

void dfs(ll i, ll j){
	visited[make_pair(i,j)] = true;
	curr.insert(make_pair(i,j));
	if(i == 0 || i == n-1 || j == 0 || j == m-1)lake_flag = false;
	
	if(i > 0 && visited.find(make_pair(i-1,j)) == visited.end() && grid[i-1][j] == '.')dfs(i-1,j);
	if(i < n-1 && visited.find(make_pair(i+1,j)) == visited.end() && grid[i+1][j] == '.')dfs(i+1,j);
	if(j > 0 && visited.find(make_pair(i,j-1)) == visited.end() && grid[i][j-1] == '.')dfs(i,j-1);
	if(j < m-1 && visited.find(make_pair(i,j+1)) == visited.end() && grid[i][j+1] == '.')dfs(i,j+1);
}


int main(){
	cin>>n>>m>>k;
	grid.resize(n);for(int i=0;i<n;i++)cin>> grid[i];

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(grid[i][j] == '.' && visited.find(make_pair(i,j)) == visited.end()){
				lake_flag = true;curr.clear();
				dfs(i,j);
				if(lake_flag){
					lakes.push_back(curr);
				}
				lake_flag = false;
				curr.clear();
			}
		}
	}

	sort(lakes.begin(),lakes.end(), comp);
	
	int cnter = 0;
	ll ans = 0;
	for(int i = 0;i < lakes.size() - k;i++){
		ans += lakes[i].size() ;
		for(auto it: lakes[i]){
			grid[it.first][it.second] = '*';
		}
	}
	cout << ans << endl;
	for(int i=0;i<n;i++)cout << grid[i] << endl ;
}