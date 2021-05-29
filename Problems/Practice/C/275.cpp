#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll num_vtx, queries;
vector<vector<ll>> adj_list;
vector<vector<ll>> query_point_lists;

vector<ll> parent;
ll endpt;
set<ll> path_pts;
map<ll, ll> level;

ll dfs_time;
vector<ll> in_time, out_time;

void print(vector<ll>& pth){
	for(auto it: pth)cout << it << " ";
	cout << endl;
}

void take_input(){
	scanf("%lld%lld", &num_vtx, &queries);
	adj_list.resize(num_vtx + 1);
	for(int i = 0; i < num_vtx - 1; i++){
		ll src, dest;scanf("%lld%lld", &src, &dest);
		adj_list[src].push_back(dest);
		adj_list[dest].push_back(src);
	}
	query_point_lists.resize(queries);
	for(int i = 0; i < queries; i++){
		ll sz; scanf("%lld", &sz);
		query_point_lists[i].resize(sz);
		for(int j = 0;j < sz;j++)scanf("%lld", &query_point_lists[i][j]);
	}
	// cout << "Adj list" << endl;
	// for(int i =1;i <= num_vtx;i++)print(adj_list[i]);
}

void assign_parents(){
	queue<ll> q;
	q.push(1);
	vector<bool> visited(num_vtx + 1, false);
	visited[1] = true;
	while(!q.empty()){
		ll top = q.front(); q.pop();
		for(auto it: adj_list[top]){
			if(!visited[it]){
				parent[it] = top;
				level[it] = level[top] + 1;
				q.push(it);
				visited[it] = true;
			}
		}
	}
}

void dfs(ll node){
	in_time[node] = dfs_time++;
	for(auto it: adj_list[node]){
		if(it != parent[node]){
			dfs(it);
		}
	}
	out_time[node] = dfs_time++;
}

void setup_onetime(){
	// assign parents
	level.clear();
	level[1] = 0;
	parent.resize(num_vtx + 1);
	parent[1] = 1;
	assign_parents();

	in_time.resize(num_vtx + 1);
	out_time.resize(num_vtx + 1);
	dfs_time = 0;
	dfs(1);
	// print(in_time);
	// print(out_time);
	
	// cout<< "Parents: " << endl;
	// print(parent);
}

void setup(){
	// init path
	path_pts.clear();path_pts.insert(1);
	endpt = 1;
}

void initialize(){
	take_input();
	setup_onetime();
}

bool cmp(ll pt1, ll pt2){
	return level[pt1] > level[pt2];
}

bool find_path_if_exists(vector<ll>& query_points){
	setup();
	// cout << "Query pts: " << endl;
	// print(query_points);
	sort(query_points.begin(), query_points.end(), cmp);
	ll farthest_pt = query_points[0];
	// cout << "Farthest point: "<< farthest_pt << endl;
	for(auto point: query_points){
		// point or its parent in pth
		// if(path_pts.find(point) != path_pts.end() || path_pts.find(parent[point]) != path_pts.end()){
		// 	// cout << "Point " << point << " found in path or as child of someone in path" << endl;
		// 	continue;
		// }
		//method-2 for above thing
		if(in_time[parent[point]] <= in_time[farthest_pt] && out_time[parent[point]] >= out_time[farthest_pt]){
			continue;
		} else return false;



		// //update path
		// vector<ll> path_ext;path_ext.clear();
		// ll curr = parent[point];
		// while(curr != -1 && curr != endpt && level[curr] > level[endpt]){
		// 	path_ext.push_back(curr);
		// 	curr = parent[curr];
		// }
		
		// cout << "Path extension: " << endl;
		// print(path_ext);

		// point found in an extension of existing path
		// if(curr == endpt){
		// 	endpt = parent[point];
		// 	path_pts.insert(path_ext.begin(), path_ext.end());
		// 	path_ext.clear();
		// } else{ // path doesn't exist
		// 	return false;
		// }
		// cout << "Path: " << endl;
		// print(path);
	}

	return true;
}


int main(){
	initialize();
	for(int i = 0;i < queries; i++){
		bool possible = find_path_if_exists(query_point_lists[i]);
		if(possible)printf("YES\n");
		else printf("NO\n");
	}
}