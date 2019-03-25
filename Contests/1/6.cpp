#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n,m ;
	cin>>n>>m ;
	vector<string> grid ;grid.resize(n) ;
	for (int i = 0; i < n; ++i)cin >> grid[i] ;	
    vector<vector<int>> u,d,l,r;
    u.resize(n);d.resize(n);l.resize(n);r.resize(n);
    for(int i=0;i<n;i++)u[i].resize(m);
    for(int i=0;i<n;i++)d[i].resize(m);
    for(int i=0;i<n;i++)l[i].resize(m);
    for(int i=0;i<n;i++)r[i].resize(m);

    for (int i = 0; i < n; ++i)
    {
    	for (int j = 0; j < m; ++j)
    	{
    		if(i == 0)u[i][j] = 0 ;
    		if(j==0)l[i][j] = 0 ;
    		if (grid[i][j] == '.'){    			
    			u[i][j] = 0 ; l[i][j] = 0 ;
    		}
    		if(i != 0 && grid[i][j] != '.')u[i][j] = u[i-1][j] ;
    		if(j != 0 && grid[i][j] != '.')l[i][j] = l[i][j-1] ;
    	}
    }
    for (int i = n-1; i>=0; --i)
    {
    	for (int j = m-1; j >= 0; --j)
    	{
    		if(i == n-1)d[i][j] = 0 ;
    		if(j==m-1)r[i][j] = 0 ;
    		if (grid[i][j] == '.'){    			
    			d[i][j] = 0 ; r[i][j] = 0 ;
    		}
    		if(i != n-1 && grid[i][j] != '.')d[i][j] = d[i+1][j] ;
    		if(j != m-1 && grid[i][j] != '.')r[i][j] = l[i][j+1] ;
    	}
    }

    vector<vector<int>> stars ;
    vector<vector<int>> h,v ;
    h.resize(n);v.resize(n);
    for(int i=0;i<n;i++)h[i].resize(m);
    for(int i=0;i<n;i++)v[i].resize(m);

    for(int i=0;i<n;i++)
	{
		for (int j = 0; j < m; ++j)
		{
			if (grid[i][j] == '*')
			{
				if ((i-1>=0 && i + 1 < n && j - 1 >= 0 && j + 1 < m ) && (grid[i][j-1] == '*' && grid[i][j+1] == '*' && grid[i-1][j] == '*' && grid[i+1][j] == '*'))
				{
					vector<int> temp; temp.resize(3) ;
					temp[0] = i;temp[1] = j ;
					temp[2] = min(l[i][j],r[i][j]); temp[2] = min(temp[2],u[i][j]); temp[2] = min(temp[2],d[i][j]) - 1;

					v[temp[0] - temp[2]][temp[1]]++;					
					if(temp[0]+temp[2] + 1 < n)
						v[temp[0] + temp[2]][temp[1]]-- ;
					h[temp[0]][temp[1]-temp[2]]++ ;					
					if(temp[1]+temp[2] + 1 < m)
						h[temp[0]][temp[1]+temp[2]]-- ;					
				}
			}
		}
	}

	vector<string>new_grid(n,string(m,'.')) ;

	for (int i = 0; i < n; ++i)
    {
    	for (int j = 0; j < m; ++j)
    	{
    		if (i>0){
    			v[i][j] += v[i-1][j] ;
    		}
    		if (j > 0){
    			h[i][j] = h[i][j-1];
    		}
    		if (v[i][j] > 0  || h[i][j] > 0)
    		{
    			new_grid[i][j] = '*' ;
    		}
    	}
    }

    for (int i = 0; i < n; ++i)
    	cout << new_grid[i] << endl ;
    return 0;
}
