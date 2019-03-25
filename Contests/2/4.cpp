#include<bits/stdc++.h>
using namespace std;

int calc(vector<char> v)
{
	// a1 an b1 bn
	if (v[2]==v[3])
	{
		if (v[0] != v[1])
		{
			return 1 ;
		}
		return 0 ;
	}
	else{
		if (v[0] != v[2] && v[0] != v[3] && v[1] != v[2] && v[1] != v[3])
		{
			return 2 ;
		}
		else if ((v[0] == v[2] && v[1] == v[3]) || (v[0] == v[3] && v[1] == v[2]))
		{
			return 0 ;
		}
		return 1 ;
	}
}

int main()
{
	int n;cin>>n;
	string a,b ;
	cin >>a>>b ;

	int sum = 0 ;

	for (int i = 0; i < n/2; ++i)
	{
		vector<char> c;
		c.push_back(a[i]);
		c.push_back(a[n-1-i]);
		c.push_back(b[i]);
		c.push_back(b[n-1-i]) ;
		sum += calc(c) ;
	}
	if (n % 2 == 1)
	{
		sum += (a[n/2] != b[n/2]) ;
	}
	cout << sum ;

	return  0 ;
}