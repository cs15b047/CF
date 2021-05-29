#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll tests; scanf("%lld",&tests);
	for(int t = 0;t < tests;t++){
		/// Iput strt
		ll n, m, k; scanf("%lld%lld%lld",&n,&m,&k);
		vector<vector<ll>> answers(n, vector<ll>(k));
		for(int i = 0;i < n;i++)
			for(int j = 0;j < k;j++)
				scanf("%lld",&answers[i][j]);
		/// Iput over

		vector<ll> cnts(k, 0); // cnts[i] = answers belonging to the ith paper
		vector<ll> choices(n); // answer choices taken to each question

		for(int i = 0;i < n;i++){
			vector<vector<ll>> tmp(m + 1, cnts);
			// Keep copy of answer for each choice
			// Update copies specific to the choice
			for(int paper = 0; paper < k ;paper++){
				tmp[answers[i][paper]][paper]++;	// 1. choose copy of answer, 2. choose bucket , 3. increment
			}

			ll answer = 0, choice = 1;
			// calc greedy choice by iterating over all copies--> coresponding to choices
			for(int j = 1;j <= m;j++){
				ll tmp_ans = tmp[j][0];
				for(int x = 0;x < k;x++){
					tmp_ans = min(tmp_ans, tmp[j][x]);
				}
				if(answer < tmp_ans){
					choice = j;
					answer = tmp_ans;
				}
			}
			choices[i] = choice;
			cnts = tmp[choice]; // update count according to the greedy choice
		}
		for(int i = 0;i < n;i++)printf("%lld ", choices[i]);printf("\n");
	}
}