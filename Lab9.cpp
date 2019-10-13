#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define pll pair<ll,ll>
#define V(a) vector<a>
#define MP make_pair
#define PB push_back
#define DB pop_back()
#define F first
#define S second

bool comp(pll &a,pll &b)
{
    if(a.S*b.F!=a.F*b.S) return a.S*b.F>a.F*b.S;
    else if(a.F!=b.F) return a.F>b.F;
    else return a.S>b.S;
}


int main()
{
    ll n;
    cin>>n;
    pll p[n];
    REP(i,0,n)
    {
        ll x,y;
        cin>>x>>y;
        p[i]=MP(x,y);
    }
    if(n<=1)
    {
        cout<<n<<'\n';
        REP(i,0,n)
        {
            cout<<p[i].F<<' '<<p[i].S<<'\n';
        }
        return 0;
    }
    REP(i,1,n)
    {
        if(p[i].F<p[0].F||(p[i].F==p[0].F&&p[i].S<p[0].S)) swap(p[i],p[0]);
    }
    REP(i,1,n)
    {
        p[i].F-=p[0].F;
        p[i].S-=p[0].S;
    }
    sort(p+1,p+n,comp);
    REP(i,1,n)
    {
        p[i].F+=p[0].F;
        p[i].S+=p[0].S;
    }
    
    V(pll) rp;
    rp.PB(p[0]);
    REP(i,1,n)
    {
        if(p[i]!=p[0])
        {
            if(rp.size()==1) rp.PB(p[i]);
            else if((rp[rp.size()-1].F-p[0].F)*(p[i].S-p[0].S)!=(rp[rp.size()-1].S-p[0].S)*(p[i].F-p[0].F)) rp.PB(p[i]);
        }
    }
    ll nv=rp.size();
    if(rp.size()<=3)
    {
        cout<<nv<<'\n';
        REP(i,0,nv)
        {
            cout<<rp[i].F<<' '<<rp[i].S<<'\n';
        }
        return 0;
    }

    V(pll) st;
    st.PB(rp[0]);
    st.PB(rp[1]);
    st.PB(rp[2]);
    REP(i,3,nv)
    {
        while((rp[i].S-st[st.size()-2].S)*(st[st.size()-1].F-st[st.size()-2].F)>=(rp[i].F-st[st.size()-2].F)*(st[st.size()-1].S-st[st.size()-2].S))
        {
            st.DB;
        }
        st.PB(rp[i]);
    }
    cout<<st.size()<<'\n';
    REP(i,0,st.size())
    {
        cout<<st[i].F<<' '<<st[i].S<<'\n';
    }

    return 0;
}