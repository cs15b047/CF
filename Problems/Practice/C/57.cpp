#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

int main(){
	ll n;cin>>n;
	vector<ll>degree(n),s(n);
	for(int i=0;i<n;i++)scanf("%lld%lld",&degree[i],&s[i]);
	ll m = 0;
	
	queue<ll>deg1;
	for(int i=0;i<n;i++){
		m += degree[i];
		if(degree[i] == 1)
			deg1.push(i);
	}
	m = m/2;
	cout << m << endl ;

	while(!deg1.empty()){
		//avoid repetitions
		while(!deg1.empty() && degree[deg1.front()] != 1)deg1.pop();
		if(deg1.empty())break ;

		ll top = deg1.front();deg1.pop();
		cout << top << " "<< s[top] << endl ;
		if(s[top] >= n){cout << "Problem" << top << endl ;exit(0);}
		ll v2 = s[top]; s[v2] = s[v2] ^ top ; degree[v2]--;
		if(degree[v2] == 1)deg1.push(v2);
	}
}