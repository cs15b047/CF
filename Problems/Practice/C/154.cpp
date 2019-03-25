#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll n, m, k; scanf("%lld%lld%lld",&n,&m,&k);
	vector<string> grid(n);
	for(int i=0;i < n;i++){
		char s[1002]; scanf("%s",s);string str(s);grid[i] = str;
	}
	vector<set<pair<ll,ll>>> components, pictures;
	vector<ll> pict_cnt;
	map<pair<ll,ll>, ll> pt_to_pict;

	vector<vector<bool>> visited(n, vector<bool>(m, false));

	for(int i=0;i < n;i++){
		for(int j=0;j<m;j++){
			if(grid[i][j] == '.' && !visited[i][j]){
				// cout << i << " " << j << endl;
				queue<pair<ll,ll>> q;
				pair<ll,ll> start = make_pair(i,j);
				q.push(start);
				visited[i][j] = true;

				set<pair<ll,ll>> comp, pict;
				ll cnt = 0;
				comp.insert(start);
				
				while(!q.empty()){
					pair<ll,ll> top = q.front();q.pop();
					if(top.first - 1 >= 0 && !visited[top.first - 1][top.second]){
						pair<ll,ll> nbh = make_pair(top.first - 1, top.second);
						if(grid[nbh.first][nbh.second] == '*'){
							pict.insert(nbh);
							cnt++;
						}
						else if(grid[nbh.first][nbh.second] == '.'){
							comp.insert(nbh);
							visited[nbh.first][nbh.second] = true;
							q.push(nbh);
						}
					}
					if(top.first + 1 < n && !visited[top.first + 1][top.second]){
						pair<ll,ll> nbh = make_pair(top.first + 1, top.second);
						if(grid[nbh.first][nbh.second] == '*'){
							pict.insert(nbh);
							cnt++;
						}
						else if(grid[nbh.first][nbh.second] == '.'){
							comp.insert(nbh);
							visited[nbh.first][nbh.second] = true;
							q.push(nbh);
						}
					}
					if(top.second - 1 >= 0 && !visited[top.first][top.second - 1]){
						pair<ll,ll> nbh = make_pair(top.first, top.second - 1);
						if(grid[nbh.first][nbh.second] == '*'){
							pict.insert(nbh);
							cnt++;
						}
						else if(grid[nbh.first][nbh.second] == '.'){
							comp.insert(nbh);
							visited[nbh.first][nbh.second] = true;
							q.push(nbh);
						}
					}
					if(top.second + 1 < m && !visited[top.first][top.second + 1]){
						pair<ll,ll> nbh = make_pair(top.first, top.second + 1);
						if(grid[nbh.first][nbh.second] == '*'){
							pict.insert(nbh);
							cnt++;
						}
						else if(grid[nbh.first][nbh.second] == '.'){
							comp.insert(nbh);
							visited[nbh.first][nbh.second] = true;
							q.push(nbh);
						}
					}
				}
				components.push_back(comp);
				pictures.push_back(pict);
				pict_cnt.push_back(cnt);
				// cout << "Pts:"<<endl;
				// for(auto it:comp)cout << it.first << " "<<it.second << endl;
				// cout << "Picts:"<<endl;
				// for(auto it:pict)cout << it.first << " "<<it.second << endl;
				for(auto it:comp)pt_to_pict[it] = components.size() - 1;
			}
		}
	}
	for(int i=0;i<k;i++){
		pair<ll,ll> pt; scanf("%lld%lld",&pt.first,&pt.second) ;pt.first--;pt.second--;
		printf("%lld\n",pict_cnt[pt_to_pict[pt]] );
	}
}