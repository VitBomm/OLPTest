#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int e,t,n,m;
int main()
{
    cin>>t;
    int countt = 0;
    while(t--)
    {
        countt++;
        cin>>n>>m;
        int temp = 1;
        long long int _MAX;
        vector<long long int> v1;
        vector<long long int> v2;
        map<pair<int,int>,bool> mapp;
        long long int S = 0;
        for(int i = 0 ; i <n;i++)
        {
            cin>>e;
            v1.push_back(e);
        }
        sort(v1.begin(),v1.end());
 
        v2.push_back(0);
        v2.push_back(n-1);
        int temp1, temp2;
        while (temp < m) {
            _MAX = -1;
            pair<int, int> lol;
            for(int i = 1 ; i <n;i++)
            {
                if(mapp[make_pair(i,i-1)] == false)
                {
                    if(v1[i] - v1[i-1] > _MAX)
                    {
                        _MAX = v1[i] - v1[i-1];
                    temp1 = i;
                    temp2 = i-1;
                    }
                }
            }
            lol.first = temp1;
            lol.second = temp2;
            mapp[lol] = true;
            v2.push_back(temp2);
            v2.push_back(temp1);
            temp++;
        }
        sort(v2.begin(),v2.end());
        if(m == 1)
        {
            cout<<"Case #"<<countt<<": "<<v1[n-1] - v1[0]<<endl;
            continue;
        }
        for(int i = 1 ; i<v2.size();i++)
        {
            S+= v1[v2[i]] - v1[v2[i-1]];
            i++;
        }
        cout<<"Case #"<<countt<<": "<<S<<endl;
    }
    return 0;
}
