#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

ll my_fn(ll budget, vector<ll> strt, vector<ll> end, vector<ll> prefix_sum, vector<ll> length){
	int gaps = strt.size();
	if(gaps == 0)return budget;
}

int main(){
	ll n;cin>>n;
	char s[1501];scanf("%s",s);string str(s);

	vector<ll> strt,end,prefix_sum,length;
	map<char,bool> char_present;
	for(int i=0;i<str.length();i++)char_present[str[i]]=true;
	int len = str.length();
	for(auto it: char_present){
		char c = it.first ;
		int j=0;
		while(j < len){
			if(str[j] != c){
				strt.push_back(j);
				while(j < len && str[j] != c)j++;
				end.push_back(j-1);
				length.push_back(end.back()-strt.back()+1);
				if(prefix_sum.empty())prefix_sum.push_back(end.back()-strt.back()+1);
				else prefix_sum.push_back(prefix_sum.back() + (end.back()-strt.back()+1));
			}
			else j++;
		}
		for(auto it1:strt)cout << it1 << " ";cout <<endl;
		for(auto it1:end)cout << it1 << " ";cout <<endl;
		for(auto it1:prefix_sum)cout << it1 << " ";cout <<endl;
		break;
	}
}