#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#define MAX 20005
using namespace std;
int n;
vector<int> v[MAX];
bool visited[MAX];
int path [MAX];
void BFS(int s,vector<int> graph[])
{
    for(int i = 1; i <=n;i++)
    {
        visited[i] = false;
        path[i] = -1;
    }
    queue<int> q;
    visited[s] = true;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for(int i = 0; i <graph[u].size();i++)
        {
            int v = graph[u][i];
            if(!visited[v])
            {
                visited[v] = true;
                q.push(v);
                path[v] = u;
            }
        }
    }
}
void CountValue(int s, int f, map<int,int> &mapp)
{
    if(s == f || s == path[f] || path[f] == -1 )
    {
        return;
    }
    else
    {
        mapp[path[f]]++;
        CountValue(s,path[f],mapp);
    }
}
int main()
{
    int q;
    int countt = 0;
    cin>>q;
    while (q--) {
        countt++;
        map<int,int> _map2;
        map<pair<int, int>,bool> _mapp;
        vector<int> graph[MAX];
        cin>>n;
        int a,b;
        for(int i = 0 ; i<n-1;i++)
        {
            cin>>a>>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        pair<int, int> lol;
        for(int i = 1;i<n;i++)
        {
            BFS(i,graph);
            for(int j = i+1 ; j<=n;j++)
            {
                if(_mapp[make_pair(i,j)] == false)
                {
                    CountValue(i, j,_map2);
                    lol.first = j;
                    lol.second = i;
                    _mapp[lol] = true;
                }
            }
        }
        int result = -1;
        map<int, int>::iterator it;
        for(it = _map2.begin(); it != _map2.end();it++)
        {
            result = max(_map2[it->first],result);
        }
        cout<<"Case #"<<countt<<": "<<result<<endl;
    }
    return 0;
}
//
