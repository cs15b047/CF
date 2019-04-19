#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll k,a,b; cin >> k >> a >> b;
	ll A[4][4]={},B[4][4]={};
	for(int i=1;i<=3;i++)for(int j=1;j<=3;j++)cin>>A[i][j];for(int i=1;i<=3;i++)for(int j=1;j<=3;j++)cin>>B[i][j];
	ll curr_x = a, curr_y = b;
	vector<pair<ll,ll>> pth;pth.clear();
	map<pair<ll,ll>, ll> states_pos;states_pos.clear();
	pth.push_back(make_pair(a,b));states_pos[make_pair(a,b)]=0;
	ll strt_loop, end_loop;
	while(true){
		// cout << curr_x << " " << curr_y << endl;
		ll nxt_x = A[curr_x][curr_y],nxt_y = B[curr_x][curr_y];
		pair<ll,ll> nxt = make_pair(A[curr_x][curr_y], B[curr_x][curr_y]);
		if(states_pos.find(nxt) != states_pos.end()){
			end_loop = pth.size() - 1;
			strt_loop = states_pos[nxt];
			break;
		}
		else{
			pth.push_back(nxt);
			states_pos[nxt] = pth.size() - 1;
		}
		curr_x = nxt_x;curr_y = nxt_y;
	}
	// cout << strt_loop << " " << end_loop << endl;
	ll alice=0,bob=0,draw=0;
	// cout << k << endl;
	for(int i=0;i < min(k, strt_loop);i++){
		if((pth[i].first == 3 && pth[i].second == 2) || (pth[i].first == 2 && pth[i].second == 1) || (pth[i].first == 1 && pth[i].second == 3))alice++;
		else if(pth[i].first == pth[i].second)draw++;
		else bob++;
	}
	k = k - min(k, strt_loop);
	// cout << alice << " " << bob << " " << draw << endl;
	ll loop_a=0,loop_b=0,loop_d=0;
	for(int i=strt_loop;i <= end_loop;i++){
		if((pth[i].first == 3 && pth[i].second == 2) || (pth[i].first == 2 && pth[i].second == 1) || (pth[i].first == 1 && pth[i].second == 3))loop_a++;
		else if(pth[i].first == pth[i].second)loop_d++;
		else loop_b++;
	}
	// cout  << loop_a << " " << loop_b << " " << loop_d << endl;
	ll len = (end_loop - strt_loop + 1);
	ll iters = (k / (end_loop - strt_loop + 1));
	// cout << len << " " << iters << endl;
	loop_a = iters * loop_a;loop_b = iters * loop_b;loop_d = iters * loop_d;
	for(ll i=strt_loop;i < (k % len) + strt_loop;i++){
		if((pth[i].first == 3 && pth[i].second == 2) || (pth[i].first == 2 && pth[i].second == 1) || (pth[i].first == 1 && pth[i].second == 3))loop_a++;
		else if(pth[i].first == pth[i].second)loop_d++;
		else loop_b++;
	}
	loop_a += alice;loop_b += bob;loop_d += draw;
	cout << loop_a << " " << loop_b << endl;
}