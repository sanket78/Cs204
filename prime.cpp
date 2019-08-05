#include<bits/stdc++.h>

using namespace std;

string s12;

int big(string s1,string s2);

string sub(string s1,string s2);

vector<int> mul(string s1,string s2);

string add(string s1,string s2);

int isprime(string s1);

string divide(string s1,string s2);


vector<int> mul(string s1,string s2)

{int a,b,c,i,j,carry,multy;
c=big(s1,s2);
if(c==2)
swap(s1,s2);
a=s1.length();
b=s2.length();
carry=0;
vector<int> x,y,z(a+b,0);
for(i=0;i<a;i++)
x.push_back(s1[i]-'0');
for(i=0;i<b;i++)
y.push_back(s2[i]-'0');
reverse(x.begin(),x.end());
reverse(y.begin(),y.end());
for(i=b;i<a;i++)
y.push_back(0);
a=x.size();
b=y.size();
for(j=0;j<b;j++)
{if(carry>0)
{z[a-1+j]=carry+z[a-1+j];
carry=0;}
    for(i=0;i<a;i++)
{multy=x[j]*y[i];
    int temp=z[i+j]+multy+carry;
    z[i+j]=temp%10;
    carry=temp/10;
}}
if(carry>0)
z[a+b-1]=carry;
reverse(z.begin(),z.end());
    return(z);
} 


string sub(string s1,string s2)
{int a,b,i,j,c,sub,carry;
char temp;
string s5="";
c=big(s1,s2);
if(c==2)
swap(s1,s2);
a=s1.length();
b=s2.length();
reverse(s1.begin(),s1.end());
reverse(s2.begin(),s2.end());
for(i=b;i<a;i++)
s2.push_back('0');
for(i=0;i<a;i++)
{if(s1[i]-s2[i]<0)
{temp=s1[i]+10-s2[i]+'0';
s1[i+1]=s1[i+1]-1;
    s5.push_back(temp);
}
else
s5.push_back(s1[i]-s2[i]+'0');}

reverse(s5.begin(),s5.end());
return(s5);}

int big(string s1,string s2)
{int a,b,i=0,j=0,c,d;
while(s1[i]=='0')
i++;
while(s2[j]=='0')
j++;
a=s1.length()-i;
b=s2.length()-j;
if(a<b)
return(2);
if(b<a)
return(1);
if(a==b)
{c=s1.length();
d=s2.length();
reverse(s1.begin(),s1.end());
reverse(s2.begin(),s2.end());
if(c<d)
{for(i=c;i<d;i++)
s1.push_back('0');}
if(d<c)
{for(i=d;i<c;i++)
s2.push_back('0');}
a=s1.length();
    for(i=a-1;i>=0;i--)
{if((s1[i]-'0')!=(s2[i]-'0'))
{if((s1[i]-'0')>(s2[i]-'0'))
return(1);
else
return(2);}}
    return(3);
}}

string add(string s1,string s2)
{int sum,carry,i,j,a,b;
char temp;
string s3="";
a=s1.length();
b=s2.length();
if(a<b)
swap(s1,s2);
a=s1.length();
b=s2.length();
reverse(s1.begin(),s1.end());
reverse(s2.begin(),s2.end());
carry=0;
for(i=0;i<b;i++)
{sum=s1[i]-'0'+s2[i]-'0'+carry;
carry=sum/10;
sum=sum%10;
s3.push_back(sum+'0');}
for(i=b;i<a;i++)
{sum=s1[i]-'0'+carry;
carry=sum/10;
sum=sum%10;
s3.push_back(sum+'0');}
if(carry>0)
s3.push_back(carry+'0');
reverse(s3.begin(),s3.end());
return(s3);}

string divide(string s1,string s2)
{int i,c,temp;
c=big(s1,s2);
if(c==2)
swap(s1,s2);
int a=s1.length(),b=s2.length();
string s3="",s5="";
for(i=0;i<a;i++)
{
s3.push_back(s1[i]);
if(big(s2,s3)==1)
s5.push_back('0');
else
{int j=0;
for(j=0;big(s2,s3)!=1;j++)
{s3=sub(s3,s2);}
s5.push_back(j+'0');}}
s12=s3;
return(s5);}

int isprime(string s1)
{int i,j,a;
cin>>s1;
string s3="",s13="";
s3.push_back('1');
s13.push_back('2');
string s2=divide(s1,s13);
for(i=2;big(s2,s3)==1;i++)
{string s15="";
char f='0'+1;
s15.push_back(f);
s3=add(s3,s15);
divide(s1,s3);
string s4;
s4=s12;
int c=0;
for(i=0;i<s4.length();i++)
{ if(s4[i]=='0')
c++;}
if(c==s4.length())
return(0);}
return(1);}




int main()
{int k,l;
 cin>>l;
 for(k=0;k<l;k++)
 {   string s1,s2="",s3="";
cin>>s1;
s2.push_back('1');
s3.push_back('2');
if(s1==s2)
cout<<"neither prime nor composite"<<endl;
if(s1==s3)
cout<<"1"<<endl;
else
{  if(isprime==0)
cout<<"Composite"<<endl;
if(isprime==1)
cout<<"Prime"<<endl;}}
  
}
