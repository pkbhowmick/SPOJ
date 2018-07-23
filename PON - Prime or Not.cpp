#include <bits/stdc++.h>
#define pb push_back
#define sc1(n) scanf("%lld",&n)
#define sc2(a,b) scanf("%lld%lld",&a,&b)
#define sc3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define MX 100000
using namespace std;

typedef long long int ll;
typedef unsigned long long ul;

ll bigmul(ll a,ll b,ll m)
{
    ll res=0;
    a=a%m;
    while(b)
    {
        if(b&1LL)
        {
            res=(res+a)%m;
        }
        a=(a*2LL)%m;
        b=b/2LL;
    }
    return res%m;

}
ll bigmod(ll a,ll b,ll m)
{
    if(b==0)return 1LL%m;
    ll x=bigmod(a,b/2,m);
    x=bigmul(x,x,m);
    if(b%2==1)
        x=bigmul(x,a,m);
    return x;
}
bool miller_rabin(ll p, ll iteration)
{
    if(p<2) return false ;
    if(p%2==0&&p!=2) return false ;

    ll s = p-1 ;
    while(s%2==0) s/=2;

    for(ll i=1;i<=iteration;i++)
    {
        ll a = rand() % (p-1)+1 , temp = s ;

        ll mod = bigmod(a,temp,p);
        while(mod!=1&&mod!=p-1&&temp!=p-1)
        {
            mod = bigmul(mod,mod,p);
            temp*=2;
        }
        if(temp%2==0&&mod!=p-1) return false ;
    }
    return true ;
}
int main()
{
    ll test;
    sc1(test);
    while(test--)
    {
        ll n;
        sc1(n);
        if(n%2==0)
        {
            if(n==2)
                printf("YES\n");
            else
                printf("NO\n");

            continue;
        }
        ll ans=miller_rabin(n,50);
        if(ans)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
