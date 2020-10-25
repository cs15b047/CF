#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll tests; cin >> tests;
	for(int t = 0;t < tests;t++){
		ll width, num_trains;
		cin >> width >> num_trains;
		vector<string> grid;
		string line;
		ll len = 3;
		for(int i =0;i < 3;i++){
			cin >> line;
			grid.push_back(line);
		}
		// for(int i = 0;i < len;i++)cout << grid[i] << endl;
		pair<ll,ll> pos;
		for(int i = 0;i < len;i++){
			if(grid[i][0] == 's'){
				pos = make_pair(i, 0);
				break;
			}
		}
		queue<pair<ll,ll>> q;
		vector<vector<bool>> visited(len, vector<bool>(width, 0));
		q.push(pos);
		visited[pos.first][pos.second] = true;
		bool done = false;
		while(!q.empty()){
			pair<ll,ll> top = q.front();
			q.pop();
			// cout << top.first << " " << top.second << endl;
			if(top.second == width - 1){
				done = true;
				break;
			}

			// get possible nbhs out of total 3
			vector<pair<ll,ll>> poss_nbhs;
			if((grid[top.first][top.second + 1] == '.') && (grid[top.first][top.second + 1] == '.') 
				&& (grid[top.first][min(top.second + 2, width - 1)] == '.')
				&& (grid[top.first][min(top.second + 3, width - 1)] == '.')){
				poss_nbhs.push_back(make_pair(top.first, min(top.second + 3, width - 1)));
			}
			if(top.first > 0){
				if((grid[top.first][top.second + 1] == '.') && (grid[top.first - 1][top.second + 1] == '.') 
				&& (grid[top.first - 1][min(top.second + 2, width - 1)] == '.')
				&& (grid[top.first - 1][min(top.second + 3, width - 1)] == '.')){
					poss_nbhs.push_back(make_pair(top.first - 1, min(top.second + 3, width - 1)));
				}
			}
			if(top.first < len - 1){
				if((grid[top.first][top.second + 1] == '.') && (grid[top.first + 1][top.second + 1] == '.' )
				&& (grid[top.first + 1][min(top.second + 2, width - 1)] == '.')
				&& (grid[top.first + 1][min(top.second + 3, width - 1)] == '.')){
					poss_nbhs.push_back(make_pair(top.first + 1, min(top.second + 3, width - 1)));
				}
			}
			for(auto it:poss_nbhs){
				if(!visited[it.first][it.second]){
					q.push(it);
					visited[it.first][it.second] = true;
				}
			}
		}
		if(done){
			cout << "YES" << endl;
		} else{
			cout << "NO" << endl;
		}
	}
}