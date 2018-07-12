#include <bits/stdc++.h>
#define pb push_back
#define sc1(n) scanf("%lld",&n)
#define sc2(a,b) scanf("%lld%lld",&a,&b)
#define sc3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define MX 100000
using namespace std;

typedef long long int ll;
typedef unsigned long long ul;

struct Q
{
    ll l,r,val,id;
}qu[200005];

bool comp(Q a,Q b)
{
    return a.val>b.val;
}
struct IN
{
    ll id;
    ll val;
}in[30005];
bool comp2(IN a,IN b)
{
    return a.val>b.val;
}
ll tree[150005];

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
    if(r<L || R<l)return 0;
    if(l<=L&&R<=r)return tree[n];

    ll mid=(L+R)/2;
    ll x=query(n*2,L,mid,l,r);
    ll y=query(n*2+1,mid+1,R,l,r);

    return x+y;
}

ll ans[200005];

int main()
{
    ll n;
    sc1(n);
    for(ll i=1;i<=n;i++)
    {
        sc1(in[i].val);
        in[i].id=i;
    }

    ll q;
    sc1(q);
    for(ll i=1;i<=q;i++)
    {
        sc3(qu[i].l,qu[i].r,qu[i].val);
        qu[i].id=i;
    }
    sort(in+1,in+n+1,comp2);
    sort(qu+1,qu+q+1,comp);

    ll pt=1;
    for(ll i=1;i<=q;i++)
    {
        ll noww=qu[i].val;
        while(pt<=n&&in[pt].val>noww)
        {
            update(1,1,n,in[pt].id);
            pt++;
        }
        ans[qu[i].id]=query(1,1,n,qu[i].l,qu[i].r);
    }
    for(ll i=1;i<=q;i++)
    {
        printf("%lld\n",ans[i]);
    }

    return 0;
}
/*
10
3 5 6 5 6 4 2 1 4 7
5
1 4 6
1 7 5
4 9 4
3 3 6
6 10 8
*/
