#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

int main(int argc, char const *argv[])
{
	int n;cin >>n ;
	vector<string> str(n);
	vector<vector<ll>> adj(26) ;
	vector<ll> indegree(26);
	for(int i=0;i<26;i++)indegree[i] = 0;
	for(int i=0;i<n;i++)cin>>str[i] ;

	bool err = 0 ;
	for (int i = 0; i < n-1; ++i)
	{
		string str1=str[i],str2=str[i+1];
		int j=0;
		while(j < str1.length() && j < str2.length()){
			if (str1[j] != str2[j])
			{
				ll src = (ll)(str1[j] - 'a'),dest = (ll)(str2[j] - 'a') ;
				if(str1[j] > str2[j]){
					src = (ll)(str1[j] - 'a');
					dest = (ll)(str2[j] - 'a') ;
				}
				adj[src].push_back(dest) ;
				indegree[dest]++ ;
				break;
			}
			j++ ;
		}
		if(j == str2.length() && j < str1.length())err = true ;
	}

	if(!err){
		queue<ll> q ;
		map<ll,bool> vis;
		string ans_str="";
		for(int i=0;i<26;i++){
			if(indegree[i] == 0)q.push(i) ;
		}
		while(!q.empty()){
			ll t = q.front(); q.pop();
			ans_str += ('a' + t) ;
			vis[t] =true;
			for(auto it: adj[t]){
				if(vis.find(it) == vis.end()){
					indegree[it]--;
					if(indegree[it] == 0)q.push(it) ;
				}
			}
		}
		if(ans_str.length() == 26)
			cout << ans_str << endl ;
		else
			cout << "Impossible"<<endl ;
	}
	else cout << "Impossible"<<endl ;	
	return 0;
}