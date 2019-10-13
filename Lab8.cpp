#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)

void dswap(double &a,double &b)
{
    double t=a;
    a=b;
    b=t;
    return;
}

void isort(double a[],ll n)
{
    REP(i,1,n)
    {
        ll j=i;
        while(a[j-1]>a[i])
        {
            j--;
            if(j==0) break;
        }
        double t=a[i];
        REPI(k,j,i)
        {
            a[k+1]=a[k];
        }
        a[j]=t;
    }
    return;
}

double select(double a[],ll n,ll k)
{
    double med[(n-1)/5+1];
    for(ll i=0;i<n;i+=5)
    {
        isort(a+i,n-i>=5?5:n-i);
        if(n-i>=5) med[i/5]=a[i+2];
        else med[i/5]=a[i+(n-i-1)/2];
    }
    if((n-1)/5==0)
    {
        return a[k];
    }
    double mmed=select(med,(n-1)/5+1,(((n-1)/5+1)-1)/2);
    ll j=0;
    REP(i,0,n)
    {
        if(a[i]<mmed) 
        {
            dswap(a[i],a[j]);
            j++;
        }
    }
    if(j==k) return mmed;
    else if(j>k) return select(a,j,k);
    else return select(a+j+1,n-j-1,k-j-1);
}

int main()
{
    ll test_cases;
    cin>>test_cases;
    while(test_cases--)
    {
        ll n;
        cin>>n;
        double x,y,r[n];
        REP(i,0,n)
        {
            cin>>x>>y;
            r[i]=x*x+y*y;
        }
        cout<<sqrt(select(r,n,(n-1)/2))<<'\n';
    }

    return 0;
}