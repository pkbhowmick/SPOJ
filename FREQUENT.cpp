#include <bits/stdc++.h>
#define pb push_back
#define sc1(n) scanf("%lld",&n)
#define sc2(a,b) scanf("%lld%lld",&a,&b)
#define sc3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define MX 100000
using namespace std;

typedef long long int ll;
typedef unsigned long long ul;

ll arr[100005];
ll mn[100005];
ll tree[400005];
vector<ll>V;

void build(ll node,ll l,ll r)
{
    if(l==r)
    {
        tree[node]=mn[l];
        return;
    }
    ll mid=(l+r)/2;
    build(node*2,l,mid);
    build(node*2+1,mid+1,r);

    tree[node]=max(tree[node*2],tree[node*2+1]);
}
ll query(ll node,ll b,ll e,ll l,ll r)
{
    if(b>r||e<l||b>e)
        return 0;
    if(b>=l&&e<=r)
        return tree[node];
    ll mid=(b+e)/2;
    ll p1=query(node*2,b,mid,l,r);
    ll p2=query(node*2+1,mid+1,e,l,r);

    return max(p1,p2);
}
int main()
{
    ll n,q;
    while(sc1(n)&&n)
    {
        V.clear();
        sc1(q);
        for(ll i=0; i<n; i++)
        {
            sc1(arr[i]);
        }
        ll now=1;
        ll id=0;
        ll last=0;
        for(ll i=1; i<n; i++)
        {
            if(arr[i]!=arr[i-1])
            {
                mn[++id]=now;

                last=last+now;
                V.pb(last);
                now=1;

            }
            else
            {
                now++;
            }
        }
        if(now!=0)
        {
            mn[++id]=now;
            last=last+now;
            V.pb(last);
        }
        build(1,1,id);

        while(q--)
        {
            ll a,b;
            sc2(a,b);
            ll id1=lower_bound(V.begin(),V.end(),a)-V.begin();
            ll id2=lower_bound(V.begin(),V.end(),b)-V.begin();
            id1++,id2++;
            ll l=id1;
            ll r=id2;
            //cout<<l<<" "<<r<<endl;
            id2--;
            id1++;
            //cout<<id1<<" "<<id2<<endl;
            ll ans=query(1,1,id,id1,id2);
            //cout<<ans<<endl;
            if(l<r)
                ans=max(ans,max(V[l-1]-a+1,b-V[r-1-1]));
            else
                ans=max(ans,b-a+1);
            printf("%lld\n",ans);
        }
    }
    return 0;
}
