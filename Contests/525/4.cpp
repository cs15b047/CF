#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	int prev_flag = 99;
	ll kc = 0, kd = 0;
	ll c,d;
	ll i1,i2;

	for(int i = 29;i >= 0; i--){
		// printf("estimates : %lld %lld\n",kc,kd );
		if(prev_flag == 99){
			c = kc; d = kd;
			printf("? %lld %lld\n",c,d );fflush(stdout);
			scanf("%lld",&i1);
		}

		else i1 = prev_flag;
		c = (ll)pow(2,i) + kc;
		d = (ll)pow(2,i) + kd;
		printf("? %lld %lld\n",c,d );fflush(stdout);
		scanf("%lld",&i2);

		if(i1 == -1 && i2 == 1){
			kc = kc ;kd += ((ll)pow(2,i));
			prev_flag = 99;
		}
		else if(i1 == 1 && i2 == -1){
			kc += ((ll)pow(2,i))  ;kd = kd;
			prev_flag = 99;
		}
		else if(i1 == i2){
			prev_flag = i1;
			ll i3;
			c = kc; d = ((ll)pow(2,i)) + kd ;
			printf("? %lld %lld\n",c,d );fflush(stdout);
			scanf("%lld",&i3);
			if(i3 == -1){kc = kc;kd = kd;}
			else if(i3 == 1){kc = ((ll)pow(2,i)) + kc;kd = ((ll)pow(2,i)) + kd;}
		}
	}
	printf("! %lld %lld\n",kc,kd );fflush(stdout);
}