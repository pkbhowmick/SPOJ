#include <bits/stdc++.h>
#define pb push_back
#define sc1(n) scanf("%lld",&n)
#define sc2(a,b) scanf("%lld%lld",&a,&b)
#define sc3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define MX 100000
using namespace std;

typedef long long int ll;
typedef unsigned long long ul;

char P[1005];
ll pi[1005];
char T[1005];
ll prefix(ll len)
{
    ll now;
    pi[0]=now=-1;
    ll mx=-1;
    for(ll i=1; i<len; i++)
    {
        while(now!=-1&&P[now+1]!=P[i])
        {
            now=pi[now];
        }
        if(P[now+1]==P[i])
        {
            pi[i]=++now;

        }
        else
            pi[i]=now=-1;

        mx=max(mx,now);
    }
    for(ll i=1;i<len;i++)
        P[i-1]=P[i];

    return mx+1;
}
int main()
{
    ll test;
    sc1(test);
    while(test--)
    {
        scanf("%s",P);
        ll len=strlen(P);
        ll ans=0;
        for(ll i=0; i<len; i++)
        {
            ll now=prefix(len-i);
            //cout<<P<<endl;
            //cout<<now<<endl;
            ans+=(len-i-now);

        }
        printf("%lld\n",ans);
    }
    return 0;
}
