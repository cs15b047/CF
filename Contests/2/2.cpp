#include<bits/stdc++.h>
using namespace std;

vector<int> a ;
class comp{
public:
	bool operator()(int x, int y)
	{
		return a[x] > a[y] ;
	}
};


int main()
{
	int n,k ;
	cin>>n>>k ;
	a.resize(n);
	for (int i = 0; i < n; ++i)cin >> a[i] ;
	vector<int> ind(n) ;
	for(int i=0;i<n;i++)ind[i] = i ;
	sort(ind.begin(), ind.end(),comp());
	vector<int> ans ;
	for (int i = 0; i < k; ++i)	
		ans.push_back(ind[i]) ;
	sort(ans.begin(),ans.end()); 

	long long int sum = 0;
	for (int i = 0; i < k; ++i)
		sum += a[ans[i]] ;
	cout << sum << endl ;
	for (int i = 0; i < k; ++i)
	{
		if (k==1)
		{
			cout << n ;
		}
		else if (i==0)
		{
			cout << ans[i+1]<<" " ;
		}
		else if(i != k-1)
		{
			cout << ans[i+1] - ans[i] << " " ;
		}
		else{
			cout << n - ans[i] ;
		}
	}


	return  0 ;
}