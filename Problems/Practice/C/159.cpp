#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n,m; scanf("%lld%lld",&n,&m);
	vector<ll> report(n + 1);for(ll i=1;i<=n;i++)scanf("%lld",&report[i]);
	vector<ll> lengths(m), order(m); for(ll i=0;i<m;i++)scanf("%lld%lld",&order[i],&lengths[i]);
	vector<ll> greatest(m);
	vector<ll> greats;
	greatest[m - 1] = m - 1;
	greats.push_back(greatest[m - 1]);
	for(ll i = m - 2;i >= 0;i--){
		if(lengths[i] > lengths[greatest[i + 1]]){
			greatest[i] = i;
			greats.push_back(greatest[i]);
		}
		else{
			greatest[i] = greatest[i + 1];
		}
	}
	// for(auto it:greatest)cout << it << " ";cout << endl;
	reverse(greats.begin(), greats.end());

	// for(auto it:greats)cout << it << " ";cout << endl;

	ll l = greats.size();
	sort(report.begin() + 1, report.begin() + lengths[greats[0]] + 1);
	int rev;
	vector<pair<ll,ll>> answers;answers.clear();
	pair<ll,ll> ip = make_pair(1, lengths[greats[0]]),op = make_pair(1, lengths[greats[0]]), ind;
	for(int i=0;i<l;i++){
		ip  = op;
		rev = (order[greats[i]] == 2);
		
		// cout << ip.first << " " << ip.second << endl;
		// cout << rev<<endl;
		
		if(i != l - 1){
			if(rev == 1){
				ind = make_pair(ip.first + lengths[greats[i]] - lengths[greats[i + 1]] - 1 , ip.first);
				op = make_pair(ip.first + lengths[greats[i]] - lengths[greats[i + 1]], ip.second);
			}
			else{
				ind = make_pair(ip.first + lengths[greats[i + 1]], ip.second);
				op = make_pair(ip.first, ip.first + lengths[greats[i + 1]] - 1);
			}
		}
		else{
			ind = ip;
			if(rev == 1)ind = make_pair(ip.second, ip.first);
		}
		// cout << ind.first << " " << ind.second << endl;
		answers.push_back(ind);
	}
	vector<ll> fin_report = report;
	// cout << "yolo" << endl;
	for(int i=0;i<l;i++){
		int k;
		if(i == l - 1)k = 1;
		else k=lengths[greats[i + 1]] + 1;
		// cout << k << " " << answers[i].first << " " << answers[i].second << endl;
		if(answers[i].first > answers[i].second){
			for(int j = answers[i].first;j>=answers[i].second;j--,k++)
				fin_report[k] = report[j];
		}
		else{
			for(int j = answers[i].first;j<=answers[i].second;j++,k++)
				fin_report[k] = report[j];
		}
	}
	for(int i=1;i<=n;i++)printf("%lld ",fin_report[i]);
	printf("\n");
}