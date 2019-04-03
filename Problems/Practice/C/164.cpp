#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n,m,p;cin >> n >> m >> p;p--;
	char s[500001]; scanf("%s",s);string seq(s);
	char s1[500001]; scanf("%s",s1);string op(s1);

	stack<ll> stk;
	map<ll,ll> open_to_close, close_to_open, neg_open_to_close, neg_close_to_open;
	for(int i=0;i<n;i++){
		if(seq[i] == '('){
			stk.push(i);
		}
		else if(seq[i] == ')'){
			open_to_close[stk.top()] = i;neg_open_to_close[-stk.top()] = -i;
			close_to_open[i] = stk.top();neg_close_to_open[-i] = -stk.top();
			stk.pop();
		}
	}
	// for(auto it:open_to_close)cout << it.first << " " << it.second << endl;
	// for(auto it: close_to_open)cout << it.first << " " << it.second << endl;
	ll curr_pos = p;
	ll x;
	for(int i=0;i<m;i++){
		if(op[i] == 'D'){
			scanf("%lld",&x);
			ll pos1,pos2,other;
			if(seq[curr_pos] == '(')other = open_to_close[curr_pos];
			else other = close_to_open[curr_pos];
			pos1 = min(curr_pos,other);pos2 = max(curr_pos,other);
			auto it11 = open_to_close.find(pos1);auto it12 = open_to_close.find(pos2);it12++;
			int flag = (close_to_open.rbegin()->first == pos2);
			
			vector<ll>opens,closes;
			for(auto it = it11;it->first < pos2;it++){
				// scanf("%lld",&x);
				opens.push_back(it->first);
				closes.push_back(it->second);
			}
			for(auto it:opens){
				// scanf("%lld",&x);
				open_to_close.erase(it);neg_open_to_close.erase(-it);
			}
			for(auto it:closes){
				// scanf("%lld",&x);
				close_to_open.erase(it);neg_close_to_open.erase(-it);
			}

			// printf("%lld %lld\n",pos1,pos2 );
			// printf("%d\n",flag );
			if(flag == 1){
				ll pos11 = neg_open_to_close.upper_bound(-pos1)->first;
				ll pos12 = neg_close_to_open.upper_bound(-pos1)->first;	
				if(pos11 < pos12)curr_pos = - neg_open_to_close.upper_bound(-pos1)->first;
				else curr_pos = - neg_close_to_open.upper_bound(-pos1)->first;
				// printf("DL:%lld %lld\n",pos11,pos12 );
			}
			else{
				// curr_pos = nxt(pos2)
				ll pos11 = open_to_close.upper_bound(pos2)->first;
				ll pos12 = close_to_open.upper_bound(pos2)->first;
				if(pos11 < pos12)curr_pos = open_to_close.upper_bound(pos2)->first;
				else curr_pos = close_to_open.upper_bound(pos2)->first;
				// printf("DR:%lld %lld\n",pos11,pos12 );
			}
		}
		else if(op[i] == 'R'){
			scanf("%lld",&x);
			ll pos11 = open_to_close.upper_bound(curr_pos)->first;
			ll pos12 = close_to_open.upper_bound(curr_pos)->first;
			if(pos11 < pos12)curr_pos = open_to_close.upper_bound(curr_pos)->first;
			else curr_pos = close_to_open.upper_bound(curr_pos)->first;
			// printf("R:%lld %lld\n",pos11,pos12 );
		}
		else if(op[i] == 'L'){
			scanf("%lld",&x);
			ll pos11 = neg_open_to_close.upper_bound(-curr_pos)->first;
			ll pos12 = neg_close_to_open.upper_bound(-curr_pos)->first;
			if(pos11 < pos12)curr_pos = - neg_open_to_close.upper_bound(-curr_pos)->first;
			else curr_pos = - neg_close_to_open.upper_bound(-curr_pos)->first;
			// printf("L:%lld %lld\n",pos11,pos12 );
		}
		// printf("%lld\n",curr_pos );
	}
	// printf("%lld\n", (ll)open_to_close.size() );
	string answer;for(int i=0;i<n;i++)answer += '.';
	for(auto it: open_to_close){
		scanf("%lld",&x);
		answer[it.first] = '(';answer[it.second] = ')';
	}
	string ans;
	for(int i=0;i<n;i++){
		scanf("%lld",&x);
		if(answer[i] != '.')ans += answer[i];
	}
	cout << ans << endl;
}