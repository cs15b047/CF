#include <bits/stdc++.h>
using namespace std ;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n ;
	vector<int> v(n) ;
	for(int i=0;i<n;i++)cin >> v[i] ;

	if (n == 1)
	{
		cout << 1 << endl << 1 ;
		return 0 ;
	}

	vector<int> a ;
	int cnt = 1 ;
	int curr = 1; 
	for (int i = 1; i < n; ++i)
	{		
		if (v[i] == 1)
		{
			a.push_back(curr) ;
			cnt++;
			curr = 1 ;
			if (i == n-1)
			{
				a.push_back(curr) ;
			}
		}
		else {
			curr = v[i] ;
			if (i == n-1)
			{
				a.push_back(curr) ;
			}
		}
	}
	cout << cnt <<endl ;
	for (int i = 0; i < a.size(); ++i)
	{
		cout << a[i] <<" " ;
	}


	return 0;
}