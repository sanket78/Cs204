#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define PB push_back

ll prec(char c)
{
    switch(c)
    {
        case '+':
            return 0;
        case '-':
            return 0;
        case '*':
            return 1;
        case '/':
            return 1;
        case '^':
            return 2;
        default:
            return -1;
    }
    return -1;
}

struct llchar
{
    bool f;
    ll x;
    char c;
};


struct node
{
    char c;
    ll dat;
    struct node *parent,*left,*right;
};

struct node *createNode()
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    return temp;
}

vector<llchar> itop(string s,bool &error,ll var_cnt,string var_name[],ll var_val[]) 
{
    stack<char> st;
    st.push('0');
    ll n=s.size();
    vector<llchar> tt;
    bool flag_num=0;
    bool flag_var=0;
    string var;
    REP(i,0,n)
    {
        if(flag_var==1)
        {
            while((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')&&i<n)
            {
                var+=s[i];
                i++;
            }
            bool flag_init=0;
            ll dat;
            REP(j,0,var_cnt)
            {
                if(var==var_name[j])
                {
                    dat=var_val[j];
                    flag_init=1;
                    break;
                }
            }
            var.clear();
            if(flag_init==0) 
            {
                error=1;
                return tt;
            }
            llchar temp;
            temp.x=dat;
            temp.f=0;
            tt.PB(temp);
            flag_var=0;
            i--;
        }
        else if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))
        {
            flag_var=1;
            i--;
        }
        else if(s[i]<='9'&&s[i]>='0')
        {
            if(flag_num==1)
            {
                tt[tt.size()-1].x*=10;
                tt[tt.size()-1].x+=(s[i]-'0');
            }
            else
            {
                llchar temp;
                temp.x=(s[i]-'0');
                temp.f=0;
                tt.PB(temp);
                flag_num=1;
            }
        }
        else if(s[i] == '(')
        {
            st.push(s[i]);
            flag_num=0;
        }
        else if(s[i] == ')') 
        { 
            while(st.top()!='0'&&st.top()!='(') 
            {
                llchar temp;
                temp.f=1;
                temp.c=st.top();
                st.pop();
                tt.PB(temp);
            } 
            if(st.top()=='(')
            {
                st.pop(); 
            }
            else
            {
                error=1;
                return tt;
            }
            flag_num=0;
        }
        else if(prec(s[i])>=0)
        { 
            while(st.top()!='0'&&prec(s[i])<=prec(st.top()))
            {
                if(s[i]=='^'&&st.top()=='^') break;
                llchar temp;
                temp.c=st.top();
                temp.f=1; 
                st.pop(); 
                tt.PB(temp);
            }
            st.push(s[i]);
            flag_num=0;
        }
        else
        {
            error=1;
            return tt;
        }
        
    }
    while(st.top()!='0') 
    { 
        llchar temp;
        temp.c=st.top();
        temp.f=1; 
        st.pop(); 
        tt.PB(temp);
    }
    return tt;
}

ll pow(ll x,ll y)
{
    ll t=1;
    while(y--)
    {
        t*=x;
    }
    return t;
}

ll eval(struct node* root)
{
    if(root->left==NULL)
    {
        return root->dat;
    }
    else
    {
        switch (root->c)
        {
            case '+':
                return eval(root->right)+eval(root->left);
            case '-':
                return eval(root->right)-eval(root->left);
            case '*':
                return eval(root->right)*eval(root->left);
            case '/':
                return eval(root->right)/eval(root->left);
            case '^':
                return pow(eval(root->right),eval(root->left));
        }
    }
    return -1;
}

int main()
{
    ll q;
    cin>>q;
    while(q--)
    {
        ll n;
        cin>>n;
        ll var_cnt=0;
        string var_name[n];
        ll var_val[n];
        while(n--)
        {
            string s00;
            cin>>s00;
            ll flag_assgn=0;
            ll var_size;
            string s0;
            string uninit_var;
            REP(i,0,s00.size())
            {
                if(s00[i]=='=') 
                {
                    flag_assgn++;
                    var_size=i;
                }
            }
            if(flag_assgn>1)
            {
                cout<<"CANT BE EVALUATED\n";
                continue;
            }
            else if(flag_assgn==1)
            {
                s0=s00.substr(var_size+1,s00.size()-var_size-1);
                uninit_var=s00.substr(0,var_size);
                bool flag_var_name_correct=0;
                REP(i,0,var_size)
                {
                    if(!((uninit_var[i]>='a'&&uninit_var[i]<='z')||(uninit_var[i]>='A'&&uninit_var[i]<='Z'))) flag_var_name_correct=1;
                }
                if(flag_var_name_correct==1)
                {
                    cout<<"CANT BE EVALUATED\n";
                    continue;
                }
            }
            else
            {
                s0=s00;
            }
            ll flag_unary=1;
            string s;
            REP(i,0,s0.size())
            {
                  if(flag_unary==1&&s0[i]=='-') s+="0";
                  else if((s0[i]>='0'&&s0[i]<='9')||(s0[i]>='a'&&s0[i]<='z')||(s0[i]>='A'&&s0[i]<='Z')) flag_unary=0;
                  else flag_unary=1;
                  s+=s0[i];
            }
            struct node *root;
            struct node *cur;
            bool error=0;
            vector<llchar> postfix=itop(s,error,var_cnt,var_name,var_val);
            if(error==1)
            {
                cout<<"CANT BE EVALUATED\n";
                continue;
            }
            REPI(i,0,postfix.size())
            {
                if(postfix[i].f==0&&i==postfix.size()-1)
                {
                    struct node *temp=createNode();
                    temp->dat=postfix[i].x;
                    temp->left=temp->right=temp->parent=NULL;
                    cur=root=temp;
                }
                else if(postfix[i].f==1&&i==postfix.size()-1)
                {
                    struct node *temp=createNode();
                    temp->c=postfix[i].c;
                    temp->left=temp->right=temp->parent=NULL;
                    cur=root=temp;
                }
                else if(postfix[i].f==0)
                {
                    if(cur->left==NULL)
                    {
                        struct node *temp=createNode();
                        temp->dat=postfix[i].x;
                        temp->left=temp->right=NULL;
                        temp->parent=cur;
                        cur->left=temp;
                    }
                    else
                    {
                        struct node *temp=createNode();
                        temp->dat=postfix[i].x;
                        temp->left=temp->right=NULL;
                        temp->parent=cur;
                        cur->right=temp;
                        while(cur->right!=NULL)
                        {
                            if(cur->parent==NULL) break;
                            cur=cur->parent;
                        }
                    }
                }
                else
                {
                    if(cur->left==NULL)
                    {
                        struct node *temp=createNode();
                        temp->c=postfix[i].c;
                        temp->left=temp->right=NULL;
                        temp->parent=cur;
                        cur->left=temp;
                        cur=temp;
                    }
                    else
                    {
                        struct node *temp=createNode();
                        temp->c=postfix[i].c;
                        temp->left=temp->right=NULL;
                        temp->parent=cur;
                        cur->right=temp;
                        cur=temp;
                    }
                }
            }
            if(flag_assgn==1)
            {
                bool flag_init=0;
                REP(j,0,var_cnt)
                {
                    if(uninit_var==var_name[j])
                    {
                        var_val[j]=eval(root);
                        flag_init=1;
                        break;
                    }
                }
                if(flag_init==0)
                {
                    var_name[var_cnt]=uninit_var;
                    var_val[var_cnt]=eval(root);
                    var_cnt++;
                }
            }
            else
            {
                cout<<eval(root)<<'\n';
            }
        }
    }

    return 0;
}