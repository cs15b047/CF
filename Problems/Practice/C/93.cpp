// B. Mike and Shortcuts - #361 - 2
// just add another edge in bfs 
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll n;cin>>n;
	vector<ll>a(n+1);for(int i=1;i<=n;i++)scanf("%lld",&a[i]);

	vector<ll> dist(n+1);
	dist[1] = 0;

	vector<bool> visited(n+1);for(int i=1;i<=n;i++)visited[i] = 0;
	visited[1] = 1;

	set<ll> curr;
	curr.insert(1);
	for(ll distance = 1;distance <= n - 1; distance++){
		set<ll> new_curr;new_curr.clear();
		for(auto it: curr){
			if(it > 1 &&  !visited[it-1]){new_curr.insert(it-1);visited[it-1]=1;}
			if(it < n &&  !visited[it+1]){new_curr.insert(it+1);visited[it+1]=1;}
			if(!visited[a[it]]){new_curr.insert(a[it]);visited[a[it]]=1;}
		}
		curr = new_curr;
		for(auto it: curr)dist[it] = distance;
	}
	for(int i=1;i<=n;i++)cout << dist[i]<< " ";	

	return 0;
}