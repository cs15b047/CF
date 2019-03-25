#include<bits/stdc++.h>
using namespace std ;

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t) ;
	for (int i = 0; i < t; ++i)
	{
		int n;
		scanf("%d",&n);
		vector<long long int> v1(n),v2;
		for (int j = 0; j < n; ++j)scanf("%lld",&v1[j]) ;
		map<long long int,int> m ;
		for(int j=0;j<n;j++)m[v1[j]]++ ;
		
		int flag = 0 ;
		for(auto it:m){
			if (it.second >= 4)
			{
				cout << it.first <<" "<< it.first <<" "<< it.first <<" "<< it.first <<endl ;
				flag = 1 ;break ;
			}
		}

		if (flag == 0)
		{
			for(auto it:m)
				if (it.second >= 2)v2.push_back(it.first) ;							
			
			double ans = 1000000000000,s1=-1,s2=-1 ;

			for (int j = 1; j < v2.size(); ++j)
			{
				double tmp = (double)(4*(v2[j]+v2[j-1])*(v2[j]+v2[j-1]))/(double)(v2[j]*v2[j-1]) ;
				// cout << v2[j] << " "<<v2[j-1]<<" "<<tmp<<endl ;
				if (tmp < ans)
				{
					s1 = v2[j];s2= v2[j-1] ;
					ans = tmp ;
				}
			}
			cout << s1 << " "<<s1<<" "<<s2<<" "<<s2<<endl ;
		}


		

	}
	
	return 0;
}