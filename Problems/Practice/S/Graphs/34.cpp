#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool vis[2][100001] = {};
ll dist[2][100001] = {};

int main(){
	ll n, k; cin >> n >> k;
	string str1, str2; vector<string> side(2); cin >> side[0] >> side[1];
	pair<ll,ll> start = make_pair(0, 0);
	queue<pair<ll,ll>> q; vis[0][0] = true;
	q.push(start);
	bool can = false;
	if(side[0][0] == '-'){
		dist[0][0] = 0;
		while(!q.empty()){
			pair<ll,ll> top = q.front();q.pop();
			// cout << top.first << " " << top.second << endl;
			if(top.second + k >= n){can = true;break;}

			if(top.second >= 1 && side[top.first][top.second - 1] == '-' && !vis[top.first][top.second - 1] && ((top.second - 1) >= dist[top.first][top.second] + 1) ){
				q.push(make_pair(top.first, top.second - 1));
				vis[top.first][top.second - 1] = true;
				dist[top.first][top.second - 1] = dist[top.first][top.second] + 1;

			}
			if(top.second + 1 < n && side[top.first][top.second + 1] == '-' && !vis[top.first][top.second + 1]){
				q.push(make_pair(top.first, top.second + 1));
				vis[top.first][top.second + 1] = true;
				vis[top.first][top.second + 1] = dist[top.first][top.second] + 1;
			}
			if(top.second + k < n && side[1 - top.first][top.second + k] == '-' && !vis[1 - top.first][top.second + k]){
				q.push(make_pair(1 - top.first, top.second + k));
				vis[1 - top.first][top.second + k] = true;
				dist[1 - top.first][top.second + k] = dist[top.first][top.second] + 1;
			}
		}
	}
	if(can)cout << "YES" << endl;
	else cout << "NO" << endl;
}