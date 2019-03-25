//A. Maze #222 - 1
// get dfs tree and keep deleting leaves
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll n,m,k;
map<pair<ll,ll>,bool> visited;
vector<string> grid;
map<pair<ll,ll>, set<pair<ll,ll>>> adj;

bool sane(pair<ll,ll> ptl){
	return (ptl.first >= 0 && ptl.second >= 0 && ptl.first < n && ptl.second < m && visited.find(ptl) == visited.end() && grid[ptl.first][ptl.second] != '#') ;
}

void dfs(pair<ll,ll> point){
	visited[point] = true;
	pair<ll,ll> ptu = make_pair(point.first - 1, point.second),ptd = make_pair(point.first + 1, point.second);
	pair<ll,ll> ptl = make_pair(point.first , point.second - 1),ptr = make_pair(point.first, point.second + 1);
	bool s1,s2,s3,s4;s1 = sane(ptl);s2 = sane(ptr);s3 = sane(ptu);s4 = sane(ptd);
	if(s1){adj[point].insert(ptl);adj[ptl].insert(point);visited[ptl] = true;}
	if(s2){adj[point].insert(ptr);adj[ptr].insert(point);visited[ptr] = true;}
	if(s3){adj[point].insert(ptu);adj[ptu].insert(point);visited[ptu] = true;}
	if(s4){adj[point].insert(ptd);adj[ptd].insert(point);visited[ptd] = true;}
	if(s1)dfs(ptl);
	if(s2)dfs(ptr);
	if(s3)dfs(ptu);
	if(s4)dfs(ptd);
}

int main(){
	cin>>n>>m>>k;
	grid.resize(n);for(int i=0;i<n;i++)cin >> grid[i] ;

	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			if(grid[i][j] == '.'){
				dfs(make_pair(i,j));
				break;
			}
		}
	}
	queue<pair<ll,ll>> q;
	visited.clear();
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			pair<ll,ll> pt = make_pair(i,j);
			if(adj.find(pt) != adj.end() && adj[pt].size() == 1)q.push(pt);
		}
	}

	ll pt_counter = 0;
	while(pt_counter < k){
		pair<ll,ll> top = q.front();q.pop();
		grid[top.first][top.second] = 'X';
		pt_counter++;
		pair<ll,ll> nbh = *(adj[top].begin());
		adj[nbh].erase(top);adj[top].erase(nbh);
		if(adj[nbh].size() == 1)q.push(nbh);
	}
	for (int i = 0; i < n; ++i)cout << grid[i] << endl;
}