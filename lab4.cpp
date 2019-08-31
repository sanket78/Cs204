include<bits/stdc++.h>
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

vector<llchar> itop(string s,bool &error)
{
    stack<char> st;
    st.push('0');
    ll n=s.size();
    vector<llchar> tt;
    bool flag=0;
    REP(i,0,n)
    {
        if(s[i]<='9'&&s[i]>='0')
        {
            if(flag==1)
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
                flag=1;
            }
        }
        else if(s[i] == '(')
        {
            st.push(s[i]);
            flag=0;
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
            flag=0;
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
            flag=0;
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
        while(n--)
        {
            string s0;
            cin>>s0;
            ll flag_unary=1;
            string s;
            REP(i,0,s0.size())
            {
                  if(flag_unary==1&&s0[i]=='-') s+="0";
                  else if(s0[i]>='0'&&s0[i]<='9') flag_unary=0;
                  else flag_unary=1;
                  s+=s0[i];
            }
            struct node *root;
            struct node *cur;
            bool error=0;
            vector<llchar> postfix=itop(s,error);
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
            cout<<eval(root)<<'\n';
        }
    }

    return 0;
}






