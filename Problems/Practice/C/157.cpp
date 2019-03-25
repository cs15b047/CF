#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n, m; cin >> n >> m;
	vector<string> grid(n);
	for(int i=0;i<n;i++)cin >> grid[i] ;
	pair<ll,ll> start,end;cin >> start.first >> start.second >> end.first >> end.second ;
	start.first--;start.second--;end.first--;end.second--;
	
	queue<pair<ll,ll>> q;
	vector<vector<ll>> vis(n, vector<ll>(m, 0));

	if(n == 1 && m == 1){
		cout << "NO" << endl;
	}
	else{
		vis[start.first][start.second]= 1;
		q.push(start);
		int flag =0;
		
		while(!q.empty()){
			pair<ll,ll> top = q.front(); q.pop();
			// cout << top.first << " " << top.second << endl;
			if(top == end){
				ll cnt_nbhs = 0;
				if(end.first - 1 >= 0 && (grid[end.first - 1][end.second] == '.' || vis[end.first - 1][end.second] == 1))cnt_nbhs++;
				if(end.first + 1 < n && (grid[end.first + 1][end.second] == '.' || vis[end.first + 1][end.second] == 1))cnt_nbhs++;
				if(end.second - 1 >= 0 && (grid[end.first][end.second - 1] == '.' || vis[end.first][end.second - 1] == 1))cnt_nbhs++;
				if(end.second + 1 < m && (grid[end.first ][end.second + 1] == '.' || vis[end.first][end.second + 1] == 1))cnt_nbhs++;
				// cout << cnt_nbhs <<endl;
				if( (grid[end.first][end.second] == 'X' && start != end) || (start == end && cnt_nbhs == 1) || cnt_nbhs >= 2){
					flag = 1;
					cout << "YES"<< endl;
					break;
				}
				else break;
			}
			else{
				if(top.first - 1 >= 0 && !vis[top.first - 1][top.second] && ( (grid[top.first - 1][top.second] == '.') || (make_pair(top.first - 1, top.second) == end)) ){
					pair<ll,ll> pt = make_pair(top.first - 1, top.second);
					q.push(pt);
					vis[pt.first][pt.second] = 1;
				}
				if(top.first + 1 < n && !vis[top.first + 1][top.second] && (grid[top.first + 1][top.second] == '.' || (make_pair(top.first + 1, top.second) == end))){
					pair<ll,ll> pt = make_pair(top.first + 1, top.second);
					q.push(pt);
					vis[pt.first][pt.second] = 1;
				}
				if(top.second - 1 >= 0 && !vis[top.first][top.second - 1] && (grid[top.first][top.second - 1] == '.'|| (make_pair(top.first, top.second - 1) == end))){
					pair<ll,ll> pt = make_pair(top.first, top.second - 1);
					q.push(pt);
					vis[pt.first][pt.second] = 1;
				}
				if(top.second + 1 < m && !vis[top.first][top.second + 1] && (grid[top.first][top.second + 1] == '.' || (make_pair(top.first, top.second + 1) == end))){
					pair<ll,ll> pt = make_pair(top.first, top.second + 1);
					q.push(pt);
					vis[pt.first][pt.second] = 1;
				}
			}
		}
		if(flag == 0)cout << "NO"<< endl;
	}
}