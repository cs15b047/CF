#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

vector<pair<int, int>> stations;

map<ll, vector<pair<int, int>>> dist_point_map;

void get_points_dist(int rows, int cols){
	vector<vector<int>> visited(rows, vector<int>(cols, 0)),dist(rows, vector<int>(cols, 1e9));
	queue<pair<int,int>> q;
	for(auto stn: stations){
		q.push(stn);
		visited[stn.first][stn.second] = 1;
		dist[stn.first][stn.second] = 0;
		dist_point_map[0].push_back(stn);
	}
	while(!q.empty()){
		pair<int, int> top = q.front(); q.pop();
		ll curr_dist = dist[top.first][top.second] + 1;
		if(top.first >= 1 && visited[top.first - 1][top.second] == 0){
			visited[top.first - 1][top.second] = 1;
			dist[top.first - 1][top.second] = curr_dist;
			q.push(make_pair(top.first - 1, top.second));
			dist_point_map[curr_dist].push_back(make_pair(top.first - 1, top.second));
		}
		if(top.first + 1 < rows && visited[top.first + 1][top.second] == 0){
			visited[top.first + 1][top.second] = 1;
			dist[top.first + 1][top.second] = curr_dist;
			q.push(make_pair(top.first + 1, top.second));
			dist_point_map[curr_dist].push_back(make_pair(top.first + 1, top.second));
		}
		if(top.second - 1 >= 0 && visited[top.first][top.second - 1] == 0){
			visited[top.first][top.second - 1] = 1;
			dist[top.first][top.second - 1] = curr_dist;
			q.push(make_pair(top.first, top.second - 1));
			dist_point_map[curr_dist].push_back(make_pair(top.first, top.second - 1));
		}
		if(top.second + 1 < cols && visited[top.first][top.second + 1] == 0){
			visited[top.first][top.second + 1] = 1;
			dist[top.first][top.second + 1] = curr_dist;
			q.push(make_pair(top.first, top.second + 1));
			dist_point_map[curr_dist].push_back(make_pair(top.first, top.second + 1));
		}
	}
}

vector<pair<int, int>> get_points_outside_boundary(ll boundary_dist){
	auto it_start = dist_point_map.upper_bound(boundary_dist);
	vector<pair<int, int>> answer;answer.clear();
	while(it_start != dist_point_map.end()){
		answer.insert(answer.end(), it_start->second.begin(), it_start->second.end());
		it_start++;
	}
	return answer;
}

bool validate_max_dist(vector<pair<int, int>> points, ll distance){
	if(points.empty())return true;
	map<ll, vector<pair<int, int>>> sum_x_y_pts, diff_x_y_pts;
	for(auto pt: points){
		sum_x_y_pts[pt.first + pt.second].push_back(pt);
		diff_x_y_pts[pt.first - pt.second].push_back(pt);
	}
	ll sum_mnm = sum_x_y_pts.begin()->first, sum_mxm = sum_x_y_pts.rbegin()->first;
	ll diff_mnm = diff_x_y_pts.begin()->first, diff_mxm = diff_x_y_pts.rbegin()->first;
	
	for(auto pt: points){
		ll tmp_dist1 = max(sum_mxm - (pt.first + pt.second), (pt.first + pt.second) - sum_mnm);
		ll tmp_dist2 = max(diff_mxm - (pt.first - pt.second), (pt.first - pt.second) - diff_mnm);
		if(max(tmp_dist1, tmp_dist2) <= distance){
			return true;
		}
	}

	return false;
}


int main(){
	ll t; scanf("%lld",&t);
	for(int q = 0;q < t;q++){
		dist_point_map.clear();
		stations.clear();
		
		// ip
		ll rows, cols; scanf("%lld%lld",&rows, &cols);
		vector<string> grid(rows);for(int i = 0;i < rows;i++) cin >> grid[i];
		// stns
		for(int i = 0;i < rows;i++){
			for(int j = 0;j < cols;j++){
				if(grid[i][j] == '1')
					stations.push_back(make_pair(i, j));
			}
		}
		// calc all pt dists
		ll lower_dist = 0, high_dist = rows + cols, mid;
		get_points_dist(rows, cols);

		// bin search on answer and validate by checking whether it fits in a diamond of diagonal 2 x dist.
		while(lower_dist < high_dist){
			mid = (lower_dist + high_dist) / 2;
			vector<pair<int, int>> outside_points = get_points_outside_boundary(mid);
			bool possible = validate_max_dist(outside_points, mid);
			
			if(possible){
				high_dist = mid;
			} else{
				lower_dist = mid + 1;
			}
		}
		printf("Case #%d: %lld\n", q + 1, lower_dist);
	}
}
