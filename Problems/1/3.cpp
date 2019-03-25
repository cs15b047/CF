#include<bits/stdc++.h>
using namespace std;

long long int big = 10000000000000 ;

int main(int argc, char const *argv[])
{
	
	int n,m;cin >>n>>m ;
	vector<vector<long long int> > C(m+1) ; 
	for(int i=0;i<n;i++){
		int p,c ;cin >>p >> c ;
		C[p].push_back(c) ;
	}
	for(int i=1;i<=m;i++){
		sort(C[i].begin(),C[i].end()) ;
	}

	long long int answer = big ;

	for(int v = 1;v <=n; v++)
	{
		long long int sum = 0, cnt = C[1].size() ;
		vector<int> rest ;
		for(int j=2;j<=m;j++){
			if (C[j].size() < v)
			{
				for(int k=0;k<C[j].size();k++){
					rest.push_back(C[j][k]) ;
				}
			}
			else{
				for(int k=0;k<=C[j].size()-v;k++){
					sum += C[j][k] ;
					cnt++ ;
				}
				for(int k=C[j].size()-v+1;k<C[j].size();k++){
					rest.push_back(C[j][k]) ;
				}
			}
		}
		if(cnt < v){
			sort(rest.begin(),rest.end()) ;
			for(int k=0;k < v - cnt;k++){
				sum += rest[k] ;
			}
		}
		answer = min(answer, sum) ;
	}
	cout << answer<<endl ;




	return 0;
}