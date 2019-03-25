#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

int main()
{
	int n;cin>>n;
	char s[100001];scanf("%s",s);
	string  str(s);
	map<char,int> cnt,tmp ;
	for(int i=0;i<n;i++)cnt[str[i]]++;
	if(cnt.size() == 1)cout << 1 << endl ;
	else{
		int i = 0;
		tmp[str[i]] = 1;
		while(tmp.size() < cnt.size()){
			i++;
			tmp[str[i]]++;
		}
		int p1 = 0, p2 = i, ans = p2 - p1 + 1 ;
		while(tmp[str[p1]] > 1){
			tmp[str[p1]]--;
			p1++;
		}
		ans = p2 - p1 + 1; 
		while(p2 < n-1){
			p2++;
			tmp[str[p2]]++;
			while(tmp[str[p1]] > 1){
				tmp[str[p1]]--;
				p1++;
			}
			ans = min(ans, p2-p1+1) ;
		}
		cout << ans <<endl ;
	}

	return 0;
}