#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

int main(int argc, char const *argv[])
{
	int n;cin>>n ;
	vector<ll> p(n+1),indegree(n+1);
	for (int i = 1; i <= n; ++i)indegree[i] = 0 ;
	for(int i=1;i<=n;i++){
		cin>>p[i];
		if(p[i] != -1)
			indegree[p[i]]++ ;
	}

	queue<ll> q,q2;
	for(int i=1;i<=n;i++)
		if(indegree[i] == 0)
			q2.push(i) ;
	ll ans=0;
	while(!q2.empty()){
		ans++ ;
		q = q2 ;
		while(!q2.empty())q2.pop();
		while(!q.empty()){
			ll t = q.front() ;q.pop();
			// cout << t<<" ";
			if(p[t] != -1 && indegree[p[t]] == 1){
				q2.push(p[t]) ;indegree[p[t]] = 0 ;
			}
			else if(p[t] != -1)indegree[p[t]]--;
		}
		// cout <<endl ;
	}
	cout << ans << endl ;
	return 0;
}