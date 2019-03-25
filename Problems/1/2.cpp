#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	map<int,int> m ;
	int n;cin>>n ;
	vector<int>v(n+1);
	for(int i=1;i<=n;i++)cin>>v[i] ;

	int curr = 1;
	int tmp = curr ;
	set<int> cycle ;
	set<int>non_cycle ;
	map<int,int> ans ;
	while(m.size() < n){
		vector<int>path ;
		int init=curr;
		while(m.find(init) != m.end())init++ ;
		tmp = init ;
		while(m.find(tmp) == m.end()){
			m[tmp] = 1 ;
			path.push_back(tmp) ;
			tmp = v[tmp] ;
		}
		if((cycle.find(tmp) != cycle.end()) || (non_cycle.find(tmp) != non_cycle.end())){
			for(int i=0;i<path.size();i++){
				non_cycle.insert(path[i]) ;
				ans[path[i]] = ans[tmp] ;
			}
		}
		else{
			int flag = 0;
			for (int i = 0; i < path.size(); ++i)
			{
				if(path[i] == tmp)flag = 1;
				if(flag == 0){
					non_cycle.insert(path[i]) ;
					ans[path[i]] = tmp ;
				}
				else if(flag == 1){
					cycle.insert(path[i]);
					ans[path[i]] = path[i] ;
				}
			}
		}
	}

	for (int i = 1; i <=n; ++i)
	{
		cout << ans[i]<<" " ;
	}


	return 0;
}