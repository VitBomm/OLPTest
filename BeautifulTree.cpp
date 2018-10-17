#include <iostream>
#include <vector>
#include <queue>
#define MAX 2005
using namespace std;
int v;
int a,b;
int _maxtemp = -1;
int countt = 0;
vector<int> result;
bool visited[MAX];
int path [MAX];
vector<int> graph[MAX];
struct option
{
    bool operator()(pair<int,int> &a,pair<int, int> &b)
    {
        return a.second > b.second;
    }
};
void BFS(int s)
{
    for(int i = 0; i <v;i++)
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
int PrintPathRecursion(int s, int f)
{
    countt++;
    if(s == f)
    {
        return countt;
    }
    else
    {
        if(path[f] == -1)
        {
            return countt;
        }
        else
        {
            PrintPathRecursion(s,path[f]);
        }
    }
    return countt;
}

int main(){
    cin>>v;
    for(int i = 0; i <v-1;i++)
    {
        cin>> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int _mintemp = -1;
    pair<int,int> save;
    priority_queue<pair<int, int>,vector<pair<int, int>>,option> pq;
    vector<pair<int, int>> test;
    for(int i = 0;i < v;i++)
    {
        BFS(i);
        _maxtemp = -1;
        _mintemp = -1;
        for(int j = 0; j<v;j++)
        {
            countt = 0;
            if(i!=j)
            {
           _maxtemp = max(_maxtemp,PrintPathRecursion(i,j)-1);
            if(_maxtemp > _mintemp)
            {
                _mintemp = _maxtemp;
                save.first = i;
                save.second = _maxtemp;
            }
            }
        }
        pq.push(save);
    }
    pair<int, int> temp1;
    temp1 = pq.top();
    pq.pop();
    cout<<temp1.first;
    pair<int, int> temp2;
    while(!pq.empty())
        {
            temp2 = pq.top();
            pq.pop();
            if(temp2.second == temp1.second)
                {
                    cout<<" "<<temp2.first;
                }
            else
                {
                    break;
                }
        }
    // 4 1 0 1 2 1 3
    return 0;
}
