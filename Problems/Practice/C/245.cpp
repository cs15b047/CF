#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<string> grid;
vector<vector<ll>> dist;
ll ht, width;

set<pair<ll,ll>> BFS(pair<ll,ll> start, int strt){
	set<pair<ll,ll>> pts_set;
	queue<pair<ll,ll>> q;
	vector<vector<bool>> visited;
	visited.resize(ht, vector<bool>(width, false));dist.resize(ht, vector<ll>(width, -1));

	visited[start.first][start.second] = true;
	q.push(start);
	dist[start.first][start.second] = 0;

	while(!q.empty()){
		pair<ll,ll> top = q.front();q.pop();
		pts_set.insert(top);

		if(strt == 1){
			if(top.first + 1 < ht && !visited[top.first + 1][top.second] && grid[top.first + 1][top.second] == '.'){
				q.push(make_pair(top.first + 1, top.second));
				visited[top.first + 1][top.second] = true;
				dist[top.first + 1][top.second] = dist[top.first][top.second] + 1;
			}
			if(top.second + 1 < width && !visited[top.first][top.second + 1] && grid[top.first][top.second + 1] == '.'){
				q.push(make_pair(top.first, top.second + 1));
				visited[top.first][top.second + 1] = true;
				dist[top.first][top.second + 1] = dist[top.first][top.second] + 1;
			}
		} else if(strt == 2){
			if(top.first - 1 >= 0 && !visited[top.first - 1][top.second] && grid[top.first - 1][top.second] == '.'){
				q.push(make_pair(top.first - 1, top.second));
				visited[top.first - 1][top.second] = true;
				dist[top.first - 1][top.second] = dist[top.first][top.second] + 1;
			}
			if(top.second - 1 >= 0 && !visited[top.first][top.second - 1] && grid[top.first][top.second - 1] == '.'){
				q.push(make_pair(top.first, top.second - 1));
				visited[top.first][top.second - 1] = true;
				dist[top.first][top.second - 1] = dist[top.first][top.second] + 1;
			}
		}
	}
	return pts_set;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	// scanf("%lld%lld",&ht, &width);
	cin >> ht >> width;
	grid.resize(ht);
	for(int i = 0;i < ht;i++){
		// char str[1002]; scanf("%s",str);
		// string s(str);
		// grid[i] = s;
		cin >> grid[i];
	}
	// BFS
	ll answer = 2;

	pair<ll,ll> start = make_pair(0, 0), end = make_pair(ht - 1, width - 1);
	set<pair<ll,ll>> set1 = BFS(start, 1);
	set<pair<ll,ll>> set2 = BFS(end, 2);
	vector<pair<ll,ll>> common(set1.size());
	auto itt = set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), common.begin());
	common.resize(itt - common.begin());
	if(common.empty()){
		answer = 0;
	} else{
		map<ll, ll> reduced;
		for(auto pt: common){
			reduced[dist[pt.first][pt.second]]++;
		}
		for(auto it:reduced){
			if(it.first != 0 && it.first != ht + width - 2 && it.second == 1){
				answer = 1;
				break;
			}
		}
	}	
	printf("%lld\n", answer);
}