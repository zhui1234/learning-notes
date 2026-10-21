#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1;
const int mod=988244353;
int Log[N];

int main()
{
    for(int i=2;i<N;i++)
        Log[i]=Log[i>>1]+1;
    int t,l,r;
    cin>>t;
    while(t--)
    {
        cin>>l>>r;
        int x=Log[r/l];
        int num=r/(1<<x)-l+1;
        if(r/(1<<(x-1))/3>=l)
            num+=(r/(1<<(x-1))/3-l+1)*x;
        cout<<x+1<<' '<<num<<endl;
    }
    return 0;
}