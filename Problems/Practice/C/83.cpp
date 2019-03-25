#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

map<ll,vector<pair<ll,ll>>> valid_intervals;

void merge_intervals(){
	for(auto it=valid_intervals.begin();it!=valid_intervals.end();it++){
		
		sort(it->second.begin(),it->second.end());
		
		vector<pair<ll,ll>> merged;merged.clear();

		merged.push_back(it->second[0]);
		for(int j=1;j < it->second.size();j++){
			if(it->second[j].first <= merged.back().second){
				merged.back().second = max(merged.back().second, it->second[j].second) ;
			}
			else{
				merged.push_back(it->second[j]);
			}
		}
		// for(auto itr:it->second)cout << itr.first << " " << itr.second << endl;
		// for(auto itr:merged)cout << itr.first << " " << itr.second << endl;
		it->second = merged;
	}
}

int main(){
	ll x0,x1,y0,y1;cin>>x0>>y0>>x1>>y1;
	ll n;cin>>n;
	valid_intervals.clear();
	for(int i=0;i<n;i++){
		ll row,strt,end;scanf("%lld%lld%lld",&row,&strt,&end);
		valid_intervals[row].push_back(make_pair(strt, end));
	}
	merge_intervals();

	map<pair<ll,ll>,ll> valid_cells, visited, dist;
	for(auto it: valid_intervals){
		ll x = it.first;
		for(auto it2 : it.second){
			for(ll j=it2.first;j<=it2.second;j++)valid_cells[make_pair(x,j)] = 0;
		}
	}
	pair<ll,ll> start = make_pair(x0,y0),dest = make_pair(x1,y1);
	visited[start]=1;
	dist[start] = 0;

	queue<pair<ll,ll>> q;
	q.push(start);
	bool done = 0;
	while(!q.empty()){
		pair<ll,ll> top = q.front();q.pop();
		if(top == dest){
			done = 1;
			break;
		}
		for(ll i=-1;i<=1;i++){
			for(ll j=-1;j<=1;j++){
				if(top.first+i >= 1 && top.first <= 1e9 && top.second + j >= 1 && top.second <= 1e9 && !(i==0 && j==0)){
					pair<ll,ll> curr = make_pair(top.first+i,top.second+j);
					if(valid_cells.find(curr) != valid_cells.end() && visited.find(curr) == visited.end()){
						dist[curr] = dist[top] + 1;
						visited[curr] = 1;
						q.push(curr);
					}
				}
			}
		}
	}
	if(dist.find(dest) != dist.end())cout << dist[dest] << endl;
	else cout << -1 << endl;
}