#include <bits/stdc++.h>
using namespace std;
int n,k;
queue <int> c;
int cnt=0;
int cur=0;
int x=1;
int x1=0;
int x2=0;
vector < int > ov;
vector < vector < int > > a;
vector < bool > b;

void bfs(int v)
{

    ov[v]=cur;
    x1++;


    b[v]=true;
    for(int i=0;i<a[v].size();i++)
    {
            if(b[a[v][i]]==false)
            {
                x2++;
                c.push(a[v][i]);
                b[a[v][i]]=true;
            }

    }
    if(x1==x)
    {
        cur++;
     x=x+x2;
     x2=0;
    }
}

int main(){
//freopen("pathbge1.in","r",stdin);
//freopen ("pathbge1.out","w",stdout);
    cin>>n>>k;
    a.resize(n);
    ov.resize(n);
    b.resize(n);
    for(int i=0;i<n;i++)
        b[i]=false;
    for(int i=0;i<k;i++)
    {
        int a1,a2;
        cin>>a1>>a2;
        a[a1-1].push_back(a2-1);
        a[a2-1].push_back(a1-1);

    }
    c.push(0);
    while(c.size()!=0)
    {

        bfs(c.front());
        c.pop();
    }
    for(int i=0;i<n;i++)
    {
       cout<<ov[i]<<" ";
    }
}
