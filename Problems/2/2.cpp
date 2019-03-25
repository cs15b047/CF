#include<bits/stdc++.h>
using namespace std ;

int main(int argc, char const *argv[])
{
	int n;cin>>n;
	string a,b;cin>>a>>b ;

	long long int c1=0,c2=0,z=0,o=0 ;

	for (int i = 0; i < n; ++i)
	{
		if(a[i] == '0')z++;
		else o++ ;
		if (b[i] == '0')
		{
			if(a[i] == '0')c1++;
			else c2++ ;
		}
	}
	cout << (z*c2+o*c1-c1*c2) << endl ;
	
	return 0;
}