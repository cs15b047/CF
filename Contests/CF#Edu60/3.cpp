#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
	ll x1,y1,x2,y2,n; scanf("%lld%lld%lld%lld%lld",&x1,&y1,&x2,&y2,&n);
	char st[100002]; scanf("%s",st);
	string str(st);
	// cout << str << endl;
	// int v;scanf("%d",&v);

	ll d1 = x2 - x1,d2 = y2 - y1;

	ll nx=0,ny=0;
	set<char> useful;
	ll ans = 0;
	ll flag = 1;

	while(d1 !=0 || d2 != 0){
		// cout << d1 << " " << d2 << endl;
		nx = 0; ny = 0;
		ll sign1 = (d1 > 0) - (d1 < 0), sign2 = (d2 > 0) - (d2 < 0);
		ll rounds = 0, steps = 0;
		useful.clear();
		if(d1 > 0)useful.insert('R');
		if(d1 < 0)useful.insert('L');
		if(d2 > 0)useful.insert('U');
		if(d2 < 0)useful.insert('D');

		// for(auto it:useful)cout << it <<endl;

		vector<pair<ll,ll>> effects(n + 1);
		effects[0] = make_pair(0,0);
		for(ll i =1 ;i<=n;i++){
			// cout << i << " " <<(str[i - 1] == 'D') << " " << (str[i - 1] == 'U') << (useful.find(str[i-1]) != useful.end()) <<endl;
			if(((str[i - 1] == 'D') || (str[i - 1] == 'U')) && (useful.find(str[i-1]) != useful.end()) ){
				effects[i] = make_pair(effects[i - 1].first, effects[i - 1].second + 1);
				ny++;
			}
			else if(((str[i - 1] == 'L') || (str[i - 1] == 'R')) && useful.find(str[i-1]) != useful.end()){
				effects[i] = make_pair(effects[i - 1].first + 1, effects[i - 1].second);
				nx++;
			}
			else{
				// cout << "i: "<< i << endl;
				effects[i] = effects[i - 1];
			}
		}
		// printf("effects\n");
		// for(auto it:effects)cout << it.first << " "<< it.second << endl;
		// cout << nx << " " << ny << endl;
		if(d1*d2 != 0){
			if(nx + ny == 0){
				flag = 0;break;
			}
			rounds = min(abs(d1), abs(d2))/(nx + ny) ;
			d1 = d1 - sign1 * rounds*(nx + ny);
			d2 = d2- sign2 * rounds*(nx + ny);
			steps = n*rounds;
			ans += steps ;
			// cout << ans << endl;
			ll mag1 = abs(d1), mag2 = abs(d2);
			for(ll i =1 ;i<=n;i++){
				if(effects[i].first + effects[i].second == min(mag1,mag2)){
					ans += i;
					d1 = d1 - sign1 * (effects[i].first + effects[i].second) ;
					d2 = d2 - sign2 * (effects[i].first + effects[i].second);
					break;
				}
			}
		}
		else if(d1 == 0 && d2 != 0){
			if(ny == 0){
				flag = 0;break;
			}
			rounds = abs(d2)/(2*ny);
			steps = n*rounds;
			ll mag = abs(d2) - 2*rounds*ny ;
			ans += steps ;
			if(mag == 0)break;
			// cout << rounds << " " << steps << " " << mag <<endl;
			for(ll i =1 ;i<=n;i++){
				if(2*effects[i].second >= mag){
					ans += i;
					d2 = 0;
					break;
				}
			}
		}
		else if(d2 == 0 && d1 != 0){
			if(nx == 0){
				flag = 0;break;
			}
			rounds = abs(d1)/(2*nx);
			steps = n*rounds;
			ll mag = abs(d1) - 2*rounds*nx ;
			ans += steps ;
			if(mag == 0)break;
			for(ll i =1 ;i<=n;i++){
				if(2*effects[i].first >= mag){
					ans += i;
					d1 = 0;
					break;
				}
			}
		}
	}
	if(flag == 0){
		printf("-1\n");
	}
	else{
		printf("%lld\n",ans );
	}


}