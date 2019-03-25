#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n,m;
    cin >>n >> m ;
    vector<int>a,b;a.resize(n);b.resize(n);
    vector<int>c;c.resize(n);

    long long int sum = 0,sumi = 0 ;
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>b[i] ;
        c[i]= a[i]- b[i];        
        sum += b[i];
        sumi += a[i] ;
    }
    long long int residual = sumi - m ;
    if(sum > m){cout<<"-1";exit(0);}
    if(sumi < m){
        cout << "0" << endl ;
        exit(0) ;
    }

    sort(c.begin(),c.end());
    reverse(c.begin(),c.end());

    // for(int i=0;i<c.size();i++)
    //     cout<<c[i]<<" " ;

    long long int s = 0 ;
    for(int i=0;i<n;i++)
    {        
        if(s >= residual){
            cout<<i<<endl;
            exit(0) ;
        }
        s += c[i];
    }
    if(s >= residual)
        cout << n <<endl ;


    return 0;
}
