#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    long long int n,k,s;
    cin>>n>>k>>s ;

    if(((n-1) + (k-1)*(n-1) < s) || (k > s) ){cout<< "NO"; exit(0);}

    vector<int> houses;

    if(s - (n-1) >= k - 1)
    {
        houses.push_back(n);
        s = s - (n-1);k = k -1 ;
        int a = 1;
        while(k >0 && s-(n-1)>=k-1){
            houses.push_back(a);
            if(a == 1)a= n;else a = 1;
            s -= (n-1); k-- ;
        }
        if (k > 0)
        {
            int num ;
            if(a == n)        
                num = 1+(s-(k-1)) ;                    
            else        
                num = n - (s-(k-1)) ;        
            houses.push_back(num) ;
            s -= (s- (k-1)) ; k -- ;
            while(k!=0)
            {
                if(houses.back() == num+1)
                    houses.push_back(num);
                else houses.push_back(num+1);
                k-- ;
            }
        }
        
    }
    else
    {
        int num = 1 + s-(k-1) ;k--;
        houses.push_back(num) ;
        while(k!=0)
        {
            if(houses.back() == num+1)
                houses.push_back(num);
            else houses.push_back(num+1);
            k-- ;
        }
    }

    cout<< "YES"<<endl ;
    for(int i=0;i<houses.size();i++)
    {
        cout << houses[i] <<" " ;
    }

    return 0;
}
