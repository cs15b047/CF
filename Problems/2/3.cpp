#include<bits/stdc++.h>
using namespace std ;

int main(int argc, char const *argv[])
{
	int n;cin>>n ;
	vector<int> v(n) ;
	for(int i=0;i<n;i++)v[i] = i+1;
	
	int fct = 1 ,curr=1;

	while(curr*curr <= n){
		curr++;
	}
	curr--;

	vector<int> ans ;
	for (int i = n-curr,j=0; i >=0 ; i-=curr,j+=curr)
	{
		for(int k=0;k<curr;k++)ans.push_back(v[i+k]) ;
	}
	for(int i=0;i<n-curr*curr;i++)ans.push_back(v[i]) ;
	for (int i = 0; i < n; ++i)
	{
		cout<< ans[i] <<" ";
	}

	return 0;
}