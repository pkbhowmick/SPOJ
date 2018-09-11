#include <bits/stdc++.h>
#define pb push_back
#define sc1(n) scanf("%lld",&n)
#define sc2(a,b) scanf("%lld%lld",&a,&b)
#define sc3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define MX 200000
using namespace std;

typedef long long int ll;
typedef unsigned long long ul;

ll arr[MX+5];
ll tree[MX*4+5];
struct A
{
    ll val;
    ll id;
}in[MX+5];
bool comp(A a,A b)
{
    return a.val<b.val;
}
map<ll,ll>mp;
void update(ll n,ll L,ll R,ll pos)
{
    if(L==R)
    {
        tree[n]++;
        return;
    }
    ll mid=(L+R)/2;
    if(pos<=mid)update(2*n,L,mid,pos);
    else update(2*n+1,mid+1,R,pos);

    tree[n]=tree[2*n]+tree[2*n+1];
}
ll query(ll n,ll L,ll R,ll l,ll r)
{
    if(r<L || R<l||l>r)return 0;
    if(l<=L&&R<=r)return tree[n];

    ll mid=(L+R)/2;
    ll x=query(n*2,L,mid,l,r);
    ll y=query(n*2+1,mid+1,R,l,r);

    return x+y;
}
int main()
{
    ll test;
    sc1(test);
    while(test--)
    {
        memset(tree,0,sizeof tree);
        mp.clear();
        ll n;
        sc1(n);
        for(ll i=1;i<=n;i++)
        {
            sc1(in[i].val);
            in[i].id=i;
            arr[i]=in[i].val;
        }
        sort(in+1,in+n+1,comp);
        ll now=0;
        for(ll i=1;i<=n;i++)
        {
            if(mp.count(in[i].val)==0)
                mp[in[i].val]=++now;
        }
        ll ans=0;
        for(ll i=n;i>=1;i--)
        {
            ll id=arr[i];
            id=mp[id];
            ans+=query(1,1,now,1,id-1);
            update(1,1,now,id);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
