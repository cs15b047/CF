#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

bool comp(pair<ll,ll> a, pair<ll,ll> b){
	if((abs(a.first) < abs(b.first)) || (abs(a.first) == abs(b.first) && abs(a.second) < abs(b.second)))return true;
	return false;
}

string fn(string x){
	if(x == "L")return "R";
	if(x == "R")return "L";
	if(x == "D")return "U";
	if(x == "U")return "D";
}

int main(){
	ll n;cin>>n;
	vector<pair<ll,ll>> pts(n);
	for(int i=0;i<n;i++)scanf("%lld%lld",&pts[i].first,&pts[i].second);
	sort(pts.begin(),pts.end(),comp);

	ll ans= 0;
	vector<vector<pair<int,string>>>answer;
	for(int i=0;i<n;i++){
		vector<pair<int,string>> pth;
		if(pts[i].first > 0)pth.push_back(make_pair(abs(pts[i].first),"R"));
		else if(pts[i].first < 0)pth.push_back(make_pair(abs(pts[i].first),"L"));
		if(pts[i].second > 0)pth.push_back(make_pair(abs(pts[i].second),"U"));
		else if(pts[i].second < 0)pth.push_back(make_pair(abs(pts[i].second),"D"));
		pth.push_back(make_pair(2,"N"));
		for(int i = pth.size()-2;i>=0;i--){
			pth.push_back(make_pair(pth[i].first, fn(pth[i].second))) ;
		}
		pth.push_back(make_pair(3,"N"));
		answer.push_back(pth);
		ans += pth.size();
	}
	printf("%lld\n",ans );
	for(auto it1:answer){
		for(auto it:it1){
			if(it.second == "N")printf("%d\n",it.first );
			else{
				printf("1 %d %s\n",it.first, it.second.c_str() );
			}
		}
	}

}