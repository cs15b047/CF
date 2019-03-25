#include<bits/stdc++.h>
using namespace std ;

int wu(string s1, string s2,vector<int> w){
	int n = s1.length();
	int ans = 0;
	for(int i=0;i<n;i++){
		if(s1[i] == s2[i]){
			ans +=w[i] ;
		}
	}
	return ans ;
}

int binsearch(int x, vector<pair<int,int>> arr){

	if(x >= arr.back().first)return -1 ;
	int l =0,r= arr.size()-1,m;

	while(l < r){
		m=(l+r)/2;
		if(arr[m].first > x)r = m;
		else if(arr[m].first <= x)l = m + 1 ;		
	}
	return l ;

}

int main(int argc, char const *argv[])
{
	int n,m,q;cin>>n>>m>>q ;
	vector<int> w(n) ;
	for(int i=0;i<n;i++)scanf("%d",&w[i]); ;
	map<string,int> cnts; 
	for(int i=0;i<m;i++){
		char stri[20] ;scanf("%s",stri);
		string x=stri; cnts[x]++ ;
	}
	vector<pair<string,int>> counts ;
	for(auto& it:cnts)counts.push_back(make_pair(it.first,it.second)) ;

	// for(auto it:counts)cout << it.first <<" "<<it.second << " "<<endl ;

	vector<string> t(q);
	vector<int> K(q);
	for(int i=0;i<q;i++){
		int y;char x[20];
		// cin>>t[i]>>K[i] ;
		scanf("%s",x);t[i] = x;
		scanf("%d",&y);K[i] = y;
	}
	map<string,int> un_q ;	
	for(auto it: t)un_q[it]++;
	vector<string> unique_q ;
	for(auto it: un_q)unique_q.push_back(it.first);
	
	// for(auto it:unique_q)cout << it <<" " ;
	// cout << endl ;
	
	vector<vector<pair<int,int>>> answer(unique_q.size()) ;
	
	for(int i=0;i<unique_q.size();i++){
		answer[i].resize(counts.size());
		for(int j=0;j< counts.size();j++){
			answer[i][j] = make_pair(wu(unique_q[i],counts[j].first, w), j) ;
		}
		sort(answer[i].begin(),answer[i].end()) ;
	}	
	vector<vector<int>> suffix_sum_ans(unique_q.size()) ;
	for(int i=0;i<unique_q.size();i++){
		suffix_sum_ans[i].resize(counts.size());
		suffix_sum_ans[i].back() = counts[answer[i].back().second].second ;
		for(int j=counts.size()-2;j>=0 ;j--){
			suffix_sum_ans[i][j] = suffix_sum_ans[i][j+1] + counts[answer[i][j].second].second ;
		}
	}

	// for(auto it:answer){
	// 	for(auto it2:it){
	// 		cout << it2.first <<","<< it2.second <<" ";
	// 	}
	// 	cout<<endl ;
	// }

	// for(auto it:suffix_sum_ans){
	// 	for(auto it2:it){
	// 		cout << it2 <<" ";
	// 	}
	// 	cout<<endl ;
	// }

	map<string,int>q_map ;
	for(int i=0; i< unique_q.size();i++)q_map[unique_q[i]] = i;

	for(int i=0;i<q;i++){
		int index = -1 ;
		int row = q_map[t[i]] ;
		// cout << q_map[t[i]] << " "<< K[i]<<" " ;
		index = binsearch(K[i],answer[row]) ;
		// cout << index <<endl ;
		if(index == -1){
			cout <<suffix_sum_ans[row][0] <<endl ;
		}
		else{
			cout << suffix_sum_ans[row][0] - suffix_sum_ans[row][index] << endl ;
		}
	}



	
	


	return 0;
}