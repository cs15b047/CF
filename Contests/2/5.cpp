#include<bits/stdc++.h>
using namespace std;

// class node{
// public:
// 	int val ;
// 	vector<int> nbhs;
// 	node(int v){val = v ;}
// };

vector<vector<int>> g ;

vector<int> sizes;
vector<int> order ;

void dfs(int root)
{		
	int init = order.size() ;
	order.push_back(root) ;
	for (int i = 0; i < g[root].size(); ++i)
	{
		dfs(g[root][i]);
	}
	sizes[root] = order.size() - init ;
}

int main()
{
	int n,q ;
	cin>>n>>q ;
	g.clear();order.clear();
	g.resize(n+1) ;	
	for (int i = 2; i <= n; ++i)
	{
		int x;
		cin >> x ;
		g[x].push_back(i) ;
	}
	for (int i = 1; i < n+1; ++i)
	{
		sort(g[i].begin(),g[i].end()) ;
	}	
	sizes.resize(n+1) ;
	dfs(1) ;
	vector<int> pos ; pos.resize(n+1);
	for (int i = 0; i < n; ++i)
	{
		pos[order[i]] = i ;
	}

	// for (int i = 0; i < n; ++i)
	// 	cout << order[i] <<" " ;
	// cout << endl ;
	// for (int i = 1; i <= n; ++i)
	// 	cout << sizes[i]<<" ";
	// cout << endl ;
	for (int i = 0; i < q; ++i)
	{
		int u,k ;
		cin >> u >> k ;
		if (sizes[u] < k)
		{
			cout << -1 <<endl ;
		}
		else
		{
			cout << order[pos[u] + k-1] << endl ;
		}
	}	

	return  0 ;
}