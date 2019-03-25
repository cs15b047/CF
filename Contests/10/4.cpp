#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;
char grid[2001][2001]={};
bool vis[2001][2001]={};
ll lefts[2001][2001];
ll ans=0;
ll n,m;ll r,c;ll x,y;

class cmp{
public:
	bool operator() (pair<ll,ll> a, pair<ll,ll> b){
		return ((lefts[a.first][a.second]<lefts[b.first][b.second]) || ((lefts[a.first][a.second]==lefts[b.first][b.second]) && (a < b))) ;
	}
};

int main(){
	scanf("%lld%lld%lld%lld%lld%lld",&n,&m,&r,&c,&x,&y);
	for(int i=0;i<n;i++)scanf("%s",grid[i]);
	r--;c--;
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)lefts[i][j] = 1e18;
	set<pair<ll,ll>,cmp> s;
	lefts[r][c] = 0;
	s.insert(make_pair(r,c));
	while(!s.empty()){
		ll row = s.begin()->first,col = s.begin()->second;
		s.erase(*s.begin());vis[row][col]=1;
		if(row != 0 && grid[row-1][col] != '*' && !vis[row-1][col]){
			pair<ll,ll> pr = make_pair(row-1,col);
			s.erase(pr);
			lefts[row-1][col] = min(lefts[row][col], lefts[row-1][col]);
			s.insert(pr);
		}
		if(row != n-1 && grid[row+1][col] != '*' && !vis[row+1][col]){
			pair<ll,ll> pr = make_pair(row+1,col);
			s.erase(pr);
			lefts[row+1][col] = min(lefts[row][col], lefts[row+1][col]);
			s.insert(pr);
		}
		if(col != 0 && grid[row][col-1] != '*' && !vis[row][col-1]){
			pair<ll,ll> pr = make_pair(row,col-1);
			s.erase(pr);
			lefts[row][col-1] = min(lefts[row][col]+1, lefts[row][col-1]);
			s.insert(pr);
		}
		if(col != m-1 && grid[row][col+1] != '*' && !vis[row][col+1]){
			pair<ll,ll> pr = make_pair(row,col+1);
			s.erase(pr);
			lefts[row][col+1] = min(lefts[row][col], lefts[row][col+1]);
			s.insert(pr);
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(lefts[i][j] <= x && lefts[i][j] + j - c <= y)ans++;
		}
	}
	printf("%lld\n",ans );
}