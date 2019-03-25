#include<bits/stdc++.h>
using namespace std ;

int main(int argc, char const *argv[])
{
	int n;cin>>n ;
	vector<int> a(n+1),c(n+1);
	for(int i=1;i<=n;i++)scanf("%d",&c[i]) ;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]) ;

	int curr =1,strt=1 ;
	vector<int>vis(n+1);

	map<int,int> ans ;
	map<int,int> comp ;
	int com = 0 ;
	comp[1] = 0 ;
	while(ans.size() < n){
		while(ans.find(strt) != ans.end())strt++ ;	

		curr = strt ;

		map<int,int> path ;path.clear();
		vector<int> pth;pth.clear();
		int j=0 ;
		while(path.find(curr) == path.end() && vis[curr] == 0){
			path[curr] = j;j++;
			pth.push_back(curr) ;
			curr = a[curr];
		}
		//Already exist
		if (vis[curr] == 1)
		{			
			for (int i = 0; i < pth.size(); ++i)
			{
				ans[pth[i]] = ans[curr] ;
				vis[pth[i]] = 1 ;
				comp[pth[i]] = comp[curr] ;
			}
		}

		//cyc
		else{			
			int index = path[curr] ;
			int answer = c[curr] ;
			for (int i = index; i < pth.size(); ++i)
			{
				answer = min(answer, c[pth[i]]) ;
			}
			for (int i = 0; i < pth.size(); ++i){
				ans[pth[i]] = answer ;
				vis[pth[i]] = 1; 
				comp[pth[i]] = com ;
			}
			com++ ;
		}
	}
	int op = 0 ;
	int cm = 0 ;
	map<int,int> f ;
	for(auto it : comp)
	{
		if (f.find(it.second) == f.end())
		{
			f[it.second] = 1;
			op += ans[it.first] ;
		}
	}
	cout << op <<endl ;



}