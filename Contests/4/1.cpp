#include<bits/stdc++.h>
using namespace std ;

int main(int argc, char const *argv[])
{
	int t;
	cin>>t ;
	for (int i = 0; i < t; ++i)
	{
		int n;cin>>n;
		string str;cin>>str;
		int flag = 1;
		for (int j = 0; j < n/2; ++j)
		{
			if (abs(str[j] - str[n-1-j]) == 2 || str[j] == str[n-1-j])
			{
				continue;
			}
			else{
				flag=0;break ;
			}
		}
		if (flag)cout<<"YES"<<endl;
		else cout <<"NO"<<endl ;		
	}	
	return 0;
}