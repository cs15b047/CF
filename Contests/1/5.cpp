#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n,m ;
	cin>>n>>m ;
	vector<string> grid ;grid.resize(n) ;
	for (int i = 0; i < n; ++i)
	{
		cin >> grid[i] ;
	}
	vector<pair<int,int>> cnt ;vector<int> size ;
	for(int i=0;i<n;i++)
	{
		for (int j = 0; j < m; ++j)
		{
			if (grid[i][j] == '*')
			{
				if ((i-1>=0 && i + 1 < n && j - 1 >= 0 && j + 1 < m ) && (grid[i][j-1] == '*' && grid[i][j+1] == '*' && grid[i-1][j] == '*' && grid[i+1][j] == '*'))
				{
					cnt.push_back(make_pair(i,j)) ;
					for(int k = 1;k < min(m,n);k++)
					{
						if ((i-k>=0 && i + k < n && j - k >= 0 && j + k < m) &&
							(grid[i][j-k] == '*' && grid[i][j+k] == '*' && grid[i-k][j] == '*' && grid[i+k][j] == '*'))continue;
						else{
							size.push_back(k-1);break ;
						}						
					}
				}
			}
		}
	}

	vector<string> new_grid ;
	new_grid.resize(n);
	for (int i = 0; i < n; ++i)
	{
		new_grid[i].resize(m);
		for (int j = 0; j < m; ++j)
		{
			new_grid[i][j] = '.' ;
		}
	}

	for (int i = 0; i < cnt.size(); ++i)
	{
		int x =cnt[i].first,y= cnt[i].second; 
		new_grid[x][y] = '*' ;
		for (int k = 1; k <= size[i]; ++k)
		{
			new_grid[x][y-k] = '*' ;
			new_grid[x][y+k] = '*' ;
			new_grid[x-k][y] = '*' ;
			new_grid[x+k][y] = '*' ;
		}
	}

	for (int i = 0; i < n; ++i)
	{		
		for (int j = 0; j < m; ++j)
		{
			if (grid[i][j] != new_grid[i][j])
			{
				cout << -1 << endl ;
				return 0 ;
			}
			// cout << new_grid[i][j];
		}
		// cout <<endl ;
	}

	cout << cnt.size()<<endl;
	for (int i = 0; i < cnt.size(); ++i)
	{
		cout << cnt[i].first + 1 << " " << cnt[i].second + 1 << " " << size[i] << endl ;
	}


    
    return 0;
}
