#include<bits/stdc++.h>
using namespace std ;

vector<int>s,I ;
class comp{
public:
	bool operator()(int a, int b){
		return s[a] < s[b] ;
	}
};

int main(int argc, char const *argv[])
{
	int n;cin >>n ;
	vector<vector<int>> m(n) ;
	for(int i=0;i<n;i++){
		m[i].resize(4);cin>>m[i][0]>>m[i][1]>>m[i][2]>>m[i][3] ;
	}
	s.resize(n);I.resize(n);
	for(int i=0;i<n;i++){
		s[i]  = m[i][0] + m[i][1] + m[i][2] + m[i][3] ;
		I[i] = i ;
	}

	stable_sort(I.begin(),I.end(),[] (const auto& lhs, const auto& rhs) {
    return s[lhs] > s[rhs];}) ;

	for (int i = 0; i < n; ++i)
	{
		if(I[i]==0)cout << i+1<<endl ;
	}
	
	return 0;
}