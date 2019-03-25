#include <bits/stdc++.h>
using namespace std ;
int main(int argc, char const *argv[])
{
	char str[100001] ;
	scanf("%s",str) ; 
	string s = str;
	int n = s.length() ;
	int i =0 ;
	int ans = 1 ;
	int part1=-1,part2=-1;
	while(i < s.length())
	{
		int strt = i,curr=strt ;
		while(curr < n-1 && s[curr] != s[curr + 1]){
			curr++;
			i++;
		}
		int len = curr - strt + 1 ;
		if (strt == 0)		
			part1 = len ;
		if(strt != 0 && curr == n - 1)part2 = len ;
		ans = max(ans,len) ;
		i++ ;
	}	
	if (s[0] != s[n-1])
	{
		ans = max(ans, part1 + part2) ;
	}
	cout << ans <<endl ;

	

	return 0;
}