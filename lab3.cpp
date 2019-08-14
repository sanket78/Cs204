#include<bits/stdc++.h>

using namespace std;

bool ismatching(string s1)
{stack<char> a;
int i=0;
char x;
for(i=0;i<s1.length();i++)
{ 
     if(s1[i]=='('||s1[i]=='['||s1[i]=='{'||s1[i]=='<')
{a.push(s1[i]);
continue;}

if(s1[i]=='|'&&a.empty())
{a.push(s1[i]);
continue;}

if(s1[i]=='|'&& !a.empty())
{x=a.top();
if(x=='|')
{a.pop();}
if(x!='|')
{a.push('|');}}

if((s1[i]=='}'||s1[i]==')'||s1[i]==']'||s1[i]=='>')&& a.empty())
{return false;
break;}

if(s1[i]=='}')
{x=a.top();
if(x=='{')
a.pop();
if(x!='{')
{return false;
break;}}

if(s1[i]==')')
{x=a.top();
if(x=='(')
a.pop();
if(x!='(')
{return false;
break;}}

if(s1[i]=='>')
{x=a.top();
if(x=='<')
a.pop();
if(x!='<')
{return false;
break;}}

if(s1[i]==']')
{x=a.top();
if(x=='[')
a.pop();
if(x!='[')
{return false;
break;}}

}
return(a.empty());}


int main()
{int n,i,j;
cin>>n;
for(i=0;i<n;i++)
{string s;
cin>>s;
if (ismatching(s)) 
        cout << "YES"<<endl; 
    else
        cout << "NO"<<endl; }}

