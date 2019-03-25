#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n ;
	vector<int> d(n);
	for (int i = 0; i < n; ++i)	
		cin>>d[i] ;	
	vector<long long int> sum1(n),sum2(n);

	sum1[0] = d[0];
	sum2[n-1] = d[n-1] ;

	for (int i = 1; i < n; ++i)
	{
		sum1[i]  = sum1[i-1] + d[i];
		sum2[n-1-i] = sum2[n-i] + d[n-i-1] ;
	}
	map<long long int,int> sum_ind ;
	for (int i = 0; i < n; ++i)
	{
		sum_ind[sum1[i]] = i ;
	}
	long long int large = 0 ;
	int ptr1=0,ptr2 = n-1 ;

	while(ptr1 < ptr2)
	{
		if (sum1[ptr1] == sum2[ptr2])
		{
			large = max(large, sum1[ptr1]) ;
			ptr1 ++ ;
		}
		else if (sum1[ptr1] < sum2[ptr2])
		{
			ptr1++ ;
		}
		else{
			ptr2-- ;
		}
	}

	// for (int i = 0; i < n; ++i)
	// {
	// 	if (sum_ind.find(sum2[i]) != sum_ind.end())
	// 	{
	// 		if (sum_ind[sum2[i]] < i)
	// 		{
	// 			large = max(large, sum2[i]) ;
	// 		}
			
	// 	}
	// }
	cout << large <<endl ;	

	

	return  0 ;
}