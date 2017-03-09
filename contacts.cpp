#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;

typedef long long int lli;

struct node{
    int countn;
    int a[29];

    node()
    {
        countn = 0;
        memset(a,-1,sizeof(a));
    }
};

node data[22*100002];

int sz = 1;

void insert_n(string str)
{
    int curr = 1;

    for(int i=0;i<str.size();i++)
    {
        int x = str[i] - 'a' + 1;

        //cout<<x<<endl;

        if(data[curr].a[x] == -1)
        {
            data[curr].a[x] = ++sz;
        }

        curr = data[curr].a[x];
        data[curr].countn++;
    }
}

int Query(string str)
{
    int curr = 1;

    for(int i=0;i<str.size();i++)
    {
        int x = str[i] - 'a' + 1;

        //cout<<x<<endl;

        if(data[curr].a[x] == -1)
        {
            return 0;
        }

        curr = data[curr].a[x];
    }

    return data[curr].countn;
}

int main()
{
    //freopen("in.txt","rt",stdin);

    int num;
    cin>>num;

    while(num--)
    {

        string dec,name;
        cin>>dec>>name;

        if(dec == "add")
        {
            insert_n(name);
        }
        else if(dec == "find")
        {
            int result = Query(name);

            cout<<result<<endl;
        }
    }

    return 0;
}
