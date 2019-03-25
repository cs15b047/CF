#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

vector<ll> get_path(ll s, ll d){
	vector<ll> v1,v2;
	v1.push_back(s);
	while(s!=1){
		if(s % 2 == 1){v1.push_back((s-1)/2);s = (s-1)/2;}
		else {v1.push_back(s/2);s=s/2;}
	}
	v2.push_back(d);
	while(d!=1){
		if(d % 2 == 1){v2.push_back((d-1)/2);d = (d-1)/2;}
		else {v2.push_back(d/2);d=d/2;}

	}
	int i,j;
	ll cmn=1;
	for(i=v1.size()-1,j=v2.size()-1;i>=0&& j>=0;i--,j--){
		if(v1[i] == v2[j])cmn = v1[i];
		else break ;
	}
	// cout << cmn << endl;
	int idx = 0;
	vector<ll> ret;
	for(auto it: v1){
		if(it != cmn)ret.push_back(it);
		else{
			ret.push_back(it);
			break;
		}
	}
	reverse(v2.begin(),v2.end());
	while(v2[idx] != cmn)idx++;
	idx++;
	while(idx < v2.size()){
		ret.push_back(v2[idx]);idx++;
	}

	// for(auto it: ret)cout << it << " ";
	// cout << endl ;


	return ret ;
}

int main(){
	ll q;cin>>q;
	map<pair<ll,ll>,ll> costs;
	for(int i=0;i<q;i++){
		int type;cin>> type;
		if(type == 1){
			ll s,d,c;cin>>s>>d>>c;
			vector<ll> pth = get_path(s,d);
			for(int j=0;j<pth.size()-1;j++){
				costs[make_pair(pth[j],pth[j+1])] += c;
				costs[make_pair(pth[j+1],pth[j])] += c;
			}
		}
		else if(type == 2){
			ll s,d;cin>>s>>d;
			vector<ll> pth = get_path(s,d);
			ll ans = 0;
			for(int j=0;j<pth.size()-1;j++){
				if(costs.find(make_pair(pth[j],pth[j+1])) != costs.end())
					ans += costs[make_pair(pth[j],pth[j+1])] ;
			}
			cout << ans << endl ;
		}
	}
}