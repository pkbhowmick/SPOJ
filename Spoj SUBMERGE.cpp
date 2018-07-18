#include <bits/stdc++.h>
#define pb push_back
#define sc1(n) scanf("%lld",&n)
#define sc2(a,b) scanf("%lld%lld",&a,&b)
#define sc3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define MX 100000
using namespace std;

typedef long long int ll;
typedef unsigned long long ul;
ll low[10004];
ll st[10004];
ll vis[10004];
ll par[10004];
ll root,child,ans,tmm;
vector<ll>V[10004];
set<ll>S;
void FindAP(ll u,ll p)
{
    tmm++;
    st[u]=tmm;
    low[u]=tmm;
    vis[u]=1;
    if(p==root)
        child++;
    if(u!=root)
    par[u]=p;
    for(ll i=0;i<V[u].size();i++)
    {
        ll v=V[u][i];
        if(v==par[u])continue;
        if(vis[v]==1){
            low[u]=min(low[u],st[v]);
            continue;
        }
        FindAP(v,u);
        low[u]=min(low[u],low[v]);
        if(st[u]<=low[v]&&u!=root)
        {
            S.insert(u);
        }
    }

}
int main()
{
    ll n,m;
    while(sc2(n,m)==2)
    {
        if(n==0&&m==0)break;
        S.clear();
        for(ll i=1;i<=n;i++)
        {
            vis[i]=0;
            V[i].clear();
            low[i]=0;
            st[i]=0;
            par[i]=-1;
        }
        for(ll i=1;i<=m;i++)
        {
            ll a,b;
            sc2(a,b);
            V[a].pb(b);
            V[b].pb(a);
        }
        root=1;
        child=0;
        tmm=0;
        FindAP(1,-1);
        if(child>=2)
            S.insert(root);
        ans=S.size();
        printf("%lld\n",ans);
    }
    return 0;
}
/*
6 5
1 2
2 3
5 4
5 6
5 2
*/

