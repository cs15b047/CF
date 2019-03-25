#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	ll n; scanf("%lld",&n);
	pair<ll,ll> start,dest;
	cin >> start.first >> start.second >> dest.first >> dest.second ;
	start.first--;start.second--;dest.first--;dest.second--;
	
	vector<string> grid(n);
	for(int i=0;i<n;i++)cin >> grid[i];

	set<pair<ll,ll>> pts1, pts2;
	queue<pair<ll,ll>> q;
	q.push(start);
	pts1.insert(start);

	map<pair<ll,ll>, bool> vis;
	vis[start] = 1;
	int flag = 0;

	while(!q.empty()){
		pair<ll,ll> top = q.front();q.pop();
		// cout << top.first << " " << top.second << endl;
		if(top == dest){flag = 1;break;}
		if(top.first - 1 >= 0 && grid[top.first - 1][top.second] == '0' && vis.find(make_pair(top.first - 1, top.second)) == vis.end()){
			pair<ll,ll> pt = make_pair(top.first - 1, top.second);
			q.push(pt);
			pts1.insert(pt);
			vis[pt] = 1;
		}
		if(top.first + 1 < n && grid[top.first + 1][top.second] == '0' && vis.find(make_pair(top.first + 1, top.second)) == vis.end()){
			pair<ll,ll> pt = make_pair(top.first + 1, top.second);
			q.push(pt);
			pts1.insert(pt);
			vis[pt] = 1;
		}
		if(top.second + 1 < n && grid[top.first][top.second + 1] == '0' && vis.find(make_pair(top.first, top.second + 1)) == vis.end()){
			pair<ll,ll> pt = make_pair(top.first, top.second + 1);
			q.push(pt);
			pts1.insert(pt);
			vis[pt] = 1;
		}
		if(top.second - 1 >= 0 && grid[top.first][top.second - 1] == '0' && vis.find(make_pair(top.first, top.second - 1)) == vis.end()){
			pair<ll,ll> pt = make_pair(top.first, top.second - 1);
			q.push(pt);
			pts1.insert(pt);
			vis[pt] = 1;
		}
	}
	vis.clear();
	ll answer = 1e18;
	if(flag == 0){
		vis[dest] = 1;
		q.push(dest);
		pts2.insert(dest);
		while(!q.empty()){
			pair<ll,ll> top = q.front();q.pop();
			// cout << top.first << " " << top.second << endl;
			if(top.first - 1 >= 0 && grid[top.first - 1][top.second] == '0' && vis.find(make_pair(top.first - 1, top.second)) == vis.end()){
				pair<ll,ll> pt = make_pair(top.first - 1, top.second);
				q.push(pt);
				pts2.insert(pt);
				vis[pt] = 1;
			}
			if(top.first + 1 < n && grid[top.first + 1][top.second] == '0' && vis.find(make_pair(top.first + 1, top.second)) == vis.end()){
				pair<ll,ll> pt = make_pair(top.first + 1, top.second);
				q.push(pt);
				pts2.insert(pt);
				vis[pt] = 1;
			}
			if(top.second + 1 < n && grid[top.first][top.second + 1] == '0' && vis.find(make_pair(top.first, top.second + 1)) == vis.end()){
				pair<ll,ll> pt = make_pair(top.first, top.second + 1);
				q.push(pt);
				pts2.insert(pt);
				vis[pt] = 1;
			}
			if(top.second - 1 >= 0 && grid[top.first][top.second - 1] == '0' && vis.find(make_pair(top.first, top.second - 1)) == vis.end()){
				pair<ll,ll> pt = make_pair(top.first, top.second - 1);
				q.push(pt);
				pts2.insert(pt);
				vis[pt] = 1;
			}
		}
		for(auto pt1:pts1){
			for(auto pt2:pts2){
				answer = min((pt1.first - pt2.first)*(pt1.first - pt2.first) + (pt1.second - pt2.second)*(pt1.second - pt2.second), answer) ;
			}
		}
	}
	else answer = 0;
	printf("%lld\n",answer );
}