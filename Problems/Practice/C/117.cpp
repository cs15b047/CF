// xenia and weights
// BFS with states as (x - y, offset, num_hops)
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	string str; cin >> str;
	set<ll> allowed;
	for(ll i = 1;i <= 10;i++){
		if(str[i - 1] == '1')allowed.insert(i);
	}
	ll mnm,mxm;
	if(!allowed.empty()){
		mnm = *(allowed.begin());mxm = *(allowed.rbegin());
	}
	// cout << mnm << " " << mxm << endl ;
	ll  m; cin >> m ;
	queue<vector<ll>> q;
	vector<ll> init = {0, 0, 0}, last;
	q.push(init);

	map<vector<ll>, vector<ll>> prev;prev.clear();
	map<vector<ll>, ll> prev_num;prev_num.clear();
	map<vector<ll>,bool> visited;visited.clear();
	prev[init] = init ;
	prev_num[init] = -1;

	int flag = 0;
	ll cnt = 0;
	while(!q.empty()){
		cnt++;
		vector<ll> top = q.front();q.pop();
		// for(auto it:top)cout << it << " ";cout << endl;
		if(top.back() == m){flag = 1;last = top; break;}

		for(auto offset: allowed){
			if(offset != prev_num[top]){
				vector<ll> nbh = top;
				nbh.back() += 1;
				int lcl_flag = 0;
				if(top.back() % 2 == 0){
					if((top[0] + offset > 0) && ((top[0] + offset < mxm) || (top[1] == m - 1))){
						nbh[0] = top[0] + offset ;lcl_flag =1;
						nbh[1] = offset;
					}
				}
				else{
					if((offset > top[0]) && ((offset < top[0] + mxm) || (top[1] == m - 1) )){
						nbh[0] = top[0] - offset ;
						nbh[1] = offset;
						lcl_flag = 1;
					}
				}
				if(visited.find(nbh) == visited.end() && lcl_flag == 1){
					prev[nbh] = top ;
					prev_num[nbh] = offset;
					visited[nbh] = 1;
					q.push(nbh);
				}
			}
		}
	}
	// cout << cnt << endl ;
	if(!flag)cout << "NO" << endl;
	else{
		vector<ll> temp = last;
		vector<ll> answer;
		while(prev[temp] != temp){
			answer.push_back(prev_num[temp]);
			temp = prev[temp];
		}
		cout << "YES" << endl;
		reverse(answer.begin(), answer.end());
		for(auto it:answer)cout << it << " ";cout << endl;
	}
}