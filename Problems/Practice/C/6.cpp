#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

int main(int argc, char const *argv[])
{
	int n;cin >> n;
	vector<ll>x(n),y(n);
	for(int i=0;i<n;i++)cin>>x[i]>>y[i];
	map<ll,vector<ll>> xm,ym;
	for(int i=0;i<n;i++){
		xm[x[i]].push_back(i); ym[y[i]].push_back(i);
	}	
	set<ll> s ;

	int itr=0,ans=0;
	queue<ll> q;	
	while(itr < n){
		q.push(itr);
		s.insert(itr);
		while(!q.empty()){
			ll t = q.front();q.pop();			
			vector<ll> v1=xm[x[t]],v2=ym[y[t]];
			for(auto it:v1){
				if(s.find(it) == s.end()){q.push(it);s.insert(it);}
			}
			for(auto it:v2){
				if(s.find(it) == s.end()){q.push(it);s.insert(it);}
			}			
		}
		while(itr < n && s.find(itr) != s.end())itr++;		
		ans++ ;
	}
	cout << ans - 1 << endl ;
	return 0;
}