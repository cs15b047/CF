#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

ll gcd(ll a, ll b){
	if(b == 0)return a;
	return gcd(b, a % b);
}

pair<ll,ll> explore(ll a, ll b){
	ll start = 0, curr = 0, cnt = 1;
	ll g = gcd(a, b);
	ll mxm = 0;
	while(curr != g){
		curr += a;cnt++;
		mxm = max(mxm, curr);
		while(curr != g && curr >= b){
			curr -= b;cnt++;
		}
	}
	return make_pair(mxm, cnt);
}

int main(){
	ll m, a, b; cin >> m >> a >> b;
	ll g = gcd(a,b);

	pair<ll,ll> info = explore(a, b);

	ll mxm = info.first,cnt = info.second;
	ll answer = 1;
	ll step_answer = 1;
	vector<ll> vis(mxm + 1);vis[0] = 1;
	for(ll i = 1;i <= min(m, mxm);i++){
		if(vis[i - a] == 1){
			vis[i] = 1;step_answer++;
			queue<ll> q;q.push(i);
			while(!q.empty()){
				ll top = q.front();q.pop();
				if(top >= b && vis[top - b] == 0){q.push(top - b);step_answer++;vis[top-b]=1;}
				if(top + a <= i && vis[top + a] == 0){q.push(top + a);step_answer++;vis[top+a]=1;}
			}
			answer += step_answer;
		}
	}
	if(m <= mxm)cout << answer << endl;
	else{
		ll nearest = m - mxm;
		ll periods = (nearest - mxm) / g;
		answer = (periods + 1)*cnt + (periods * (periods + 1))/2 ;
	}


}