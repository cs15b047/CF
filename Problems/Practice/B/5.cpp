#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

int main(int argc, char const *argv[])
{
	int n,m;cin>>n>>m;
	vector<string> grid(n);
	for(int i=0;i<n;i++)cin >> grid[i] ;
	vector<vector<int>> vis(n) ;
	for(int i=0;i<n;i++){
		vis[i].resize(m);
		for(int j=0;j<m;j++)vis[i][j] = 0 ;
	}
	int flag = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(vis[i][j] == 0){
				vis[i][j] = 1 ;
				queue<pair<ll,ll>> q ;
				map<pair<ll,ll>,pair<ll,ll>> prev ;
				q.push(make_pair(i,j));
				prev[make_pair(i,j)] = make_pair(-1,-1) ;
				ll color = grid[i][j] ;

				while(!q.empty()){
					pair<ll,ll> t = q.front();q.pop();
					// cout << t.first <<" "<<t.second <<endl ;
					if(t.first != 0 && color == grid[t.first-1][t.second]){
						if(vis[t.first-1][t.second] != 0 && prev[t] != make_pair(t.first-1,t.second)){flag = 1;break;}
						else if(vis[t.first-1][t.second] == 0) {q.push(make_pair(t.first-1,t.second)) ;vis[t.first-1][t.second] = 1;}
						prev[make_pair(t.first-1,t.second)] = t;
					}
					if(t.first != n-1 && color == grid[t.first+1][t.second]){
						if(vis[t.first+1][t.second] != 0 && prev[t] != make_pair(t.first+1,t.second)){flag = 1;break;}
						else if(vis[t.first+1][t.second] == 0) {q.push(make_pair(t.first+1,t.second)) ;vis[t.first+1][t.second] = 1;}
						prev[make_pair(t.first+1,t.second)] = t;
					}
					if(t.second != 0 && color == grid[t.first][t.second-1]){
						if(vis[t.first][t.second-1] != 0 && prev[t] != make_pair(t.first,t.second-1)){flag = 1;break;}
						else if((vis[t.first][t.second-1] == 0)) {q.push(make_pair(t.first,t.second-1)) ;vis[t.first][t.second-1] = 1;}
						prev[make_pair(t.first,t.second-1)] = t;
					}
					if(t.second != m-1 && color == grid[t.first][t.second+1]){
						if(vis[t.first][t.second+1] != 0 && prev[t] != make_pair(t.first,t.second+1)){flag = 1;break;}
						else if(vis[t.first][t.second+1] == 0) {q.push(make_pair(t.first,t.second+1)) ;vis[t.first][t.second+1] = 1;}
						prev[make_pair(t.first,t.second+1)] = t;
					}
				}
				if(flag == 1)cout << "Yes" <<endl;
			}
			if(flag == 1)break ;
		}
		if(flag == 1)break ;
	}
	if(flag ==0)cout << "No"<<endl;	

	return 0;
}