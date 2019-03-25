#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll r,c; scanf("%lld%lld",&r,&c);
	vector<string> grid(r);
	pair<ll,ll> start, end;
	for(int i=0;i<r;i++){
		char s[1002]; scanf("%s",s);string str(s);
		grid[i] = str;
		for(int  j=0;j<c;j++){
			if(grid[i][j] == 'S')start = make_pair(i,j);
			else if(grid[i][j] == 'E')end = make_pair(i,j);
		}
	}

	vector<vector<ll>> distance(r, vector<ll>(c, 1e18));
	vector<vector<bool>> visited(r, vector<bool>(c, 0));

	distance[end.first][end.second] = 0;

	queue<pair<ll,ll>> q;
	q.push(end);
	visited[end.first][end.second] = 1;
	while(!q.empty()){
		pair<ll,ll> top = q.front();q.pop();
		if(top.first - 1 >=0 && !visited[top.first - 1][top.second] && grid[top.first - 1][top.second] != 'T'){
			visited[top.first - 1][top.second] = 1;
			distance[top.first - 1][top.second] = distance[top.first][top.second] + 1;
			pair<ll,ll> nbh = make_pair(top.first - 1, top.second);
			q.push(nbh);
		}
		if(top.first + 1 < r && !visited[top.first + 1][top.second] && grid[top.first + 1][top.second] != 'T'){
			visited[top.first + 1][top.second] = 1;
			distance[top.first + 1][top.second] = distance[top.first][top.second] + 1;
			pair<ll,ll> nbh = make_pair(top.first + 1, top.second);
			q.push(nbh);
		}
		if(top.second - 1 >= 0 && !visited[top.first][top.second - 1] && grid[top.first][top.second - 1] != 'T'){
			visited[top.first][top.second - 1] = 1;
			distance[top.first][top.second - 1] = distance[top.first][top.second] + 1;
			pair<ll,ll> nbh = make_pair(top.first, top.second - 1);
			q.push(nbh);
		}
		if(top.second + 1 < c && !visited[top.first][top.second + 1] && grid[top.first][top.second + 1] != 'T'){
			visited[top.first][top.second + 1] = 1;
			distance[top.first][top.second + 1] = distance[top.first][top.second] + 1;
			pair<ll,ll> nbh = make_pair(top.first, top.second + 1);
			q.push(nbh);
		}
	}
	ll start_dist = distance[start.first][start.second];
	ll answer = 0;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(grid[i][j] != 'T' && grid[i][j] != 'S' && grid[i][j] != 'E' && distance[i][j] <= start_dist){
				answer += (grid[i][j] - '0') ;
			}
		}
	}
	printf("%lld\n",answer );
}