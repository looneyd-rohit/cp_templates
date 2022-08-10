/*
GRAPHS: REPRESENTATION, TRAVERSAL TECHNIQUES, CYCLE DETECTION
*/

#include <bits/stdc++.h>
using namespace std;
#define MAXEDGES 10

void showList(vector<int> adjList[], int v)
{
    for (int i = 1; i <= v; i++)
    {
        cout << i << " : ";
        auto s = adjList[i].begin();
        auto e = adjList[i].end();
        while (s != e)
        {
            cout << *s << " ";
            s++;
        }
        cout << endl;
    }
}
void bfsG(vector<int> adjList[], int v)
{
    vector<int> visited(v + 1, 0);
    // outer for loop ensures that the disconnected parts of the graph
    // are also traversed
    for (int i = 1; i <= v; i++)
    {
        if (!visited[i])
        {
            queue<int> q;
            q.push(i);
            visited[i] = 1;
            while (!q.empty())
            {
                int val = q.front();
                cout << val << " ";
                q.pop();
                for (int j = 0; j < adjList[val].size(); j++)
                {
                    if (!visited[adjList[val][j]])
                    {
                        q.push(adjList[val][j]);
                        visited[adjList[val][j]] = 1;
                    }
                }
            }
        }
    }
}
void dfsG(vector<int> adjList[], int v)
{
    vector<int> visited(v + 1, 0);
    // outer for loop ensures that the disconnected parts of the graph
    // are also traversed
    for (int i = 1; i <= v; i++)
    {
        if (!visited[i])
        {
            stack<int> s;
            s.push(i);
            visited[i] = 1;
            while (!s.empty())
            {
                int val = s.top();
                cout << val << " ";
                s.pop();
                for (int j = 0; j < adjList[val].size(); j++)
                {
                    if (!visited[adjList[val][j]])
                    {
                        s.push(adjList[val][j]);
                        visited[adjList[val][j]] = 1;
                    }
                }
            }
        }
    }
}

bool cycleBFS(vector<int> adjList[], int v)
{
    vector<int> visited(v + 1, 0);
    // outer for loop ensures that the disconnected parts of the graph
    // are also traversed
    for (int i = 1; i <= v; i++)
    {
        if (!visited[i])
        {
            queue<pair<int, int>> q;
            q.push({i, -1});
            visited[i] = 1;
            while (!q.empty())
            {
                int val = q.front().first;
                int par = q.front().second;
                // cout<<val<<" ";
                q.pop();
                for (int j = 0; j < adjList[val].size(); j++)
                {
                    if (!visited[adjList[val][j]])
                    {
                        q.push({adjList[val][j], val});
                        visited[adjList[val][j]] = 1;
                    }
                    else
                    {
                        if (par != adjList[val][j])
                            return true;
                    }
                }
            }
        }
    }
    return false;
}

bool cycleDFS(vector<int> adjList[], int v)
{
    vector<int> visited(v + 1, 0);
    // outer for loop ensures that the disconnected parts of the graph
    // are also traversed
    for (int i = 1; i <= v; i++)
    {
        if (!visited[i])
        {
            stack<pair<int, int>> s;
            s.push({i, -1});
            visited[i] = 1;
            while (!s.empty())
            {
                int val = s.top().first;
                int par = s.top().second;
                // cout<<val<<" ";
                s.pop();
                for (int j = 0; j < adjList[val].size(); j++)
                {
                    if (!visited[adjList[val][j]])
                    {
                        s.push({adjList[val][j], val});
                        visited[adjList[val][j]] = 1;
                    }
                    else
                    {
                        if (par != adjList[val][j])
                            return true;
                    }
                }
            }
        }
    }
    return false;
}

// FOR BIPARTITE CHECKING USE OF VISITED ARRAY IS NOT USEFUL AS WE ARE ALREADY
// USING A COLOR ARRAY SO, WE CAN MODIFY THE VALUE OF OUR COLOR ARRAY TO CHECK IF THE NODE
// WAS VISITED OR NOT.
bool isBipartiteBFS(vector<int> adjList[], int v)
{
    vector<int> visited(v + 1, 0);
    vector<int> color(v + 1, -1); // color 0: blue, color 1: yellow

    // outer for loop ensures that the disconnected parts of the graph
    // are also traversed
    for (int i = 1; i <= v; i++)
    {
        if (!visited[i])
        {
            queue<int> q;
            q.push(i);
            visited[i] = 1;
            color[i] = 0;
            while (!q.empty())
            {
                int val = q.front();
                // cout<<val<<" ";
                q.pop();
                for (int j = 0; j < adjList[val].size(); j++)
                {
                    if (!visited[adjList[val][j]])
                    {
                        q.push(adjList[val][j]);
                        visited[adjList[val][j]] = 1;
                        color[adjList[val][j]] = !color[val];
                    }
                    else
                    {
                        if (color[val] == color[adjList[val][j]])
                        {
                            return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}

// FOR BIPARTITE CHECKING USE OF VISITED ARRAY IS NOT USEFUL AS WE ARE ALREADY
// USING A COLOR ARRAY SO, WE CAN MODIFY THE VALUE OF OUR COLOR ARRAY TO CHECK IF THE NODE
// WAS VISITED OR NOT.
bool isBipartiteDFS(vector<int> adjList[], int v)
{
    vector<int> visited(v + 1, 0);
    vector<int> color(v + 1, -1); // color 0: blue, color 1: yellow

    // outer for loop ensures that the disconnected parts of the graph
    // are also traversed
    for (int i = 1; i <= v; i++)
    {
        if (!visited[i])
        {
            stack<int> s;
            s.push(i);
            visited[i] = 1;
            color[i] = 0;
            while (!s.empty())
            {
                int val = s.top();
                // cout<<val<<" ";
                s.pop();
                for (int j = 0; j < adjList[val].size(); j++)
                {
                    if (!visited[adjList[val][j]])
                    {
                        s.push(adjList[val][j]);
                        visited[adjList[val][j]] = 1;
                        color[adjList[val][j]] = !color[val];
                    }
                    else
                    {
                        if (color[val] == color[adjList[val][j]])
                            return false;
                    }
                }
            }
        }
    }
    return true;
}

// shortest path in an undirected graph (using BFS - moving [breadth] wise)
void shortestPathBFS(vector<int> adjList[], int v)
{
    vector<int> distArr(v + 1, INT_MAX);
    int start, end;
    cout << "Enter the start and end location= ";
    cin >> start >> end;
    // distance moving from source to start should be 0 as start itself is source
    distArr[start] = 0;
    queue<int> q;
    // push to queue whenever distance changes to track further
    q.push(start);
    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        int dis = distArr[f];
        // checking for all adjacent elements
        for (int i = 0; i < adjList[f].size(); i++)
        {

            int temp = distArr[adjList[f][i]];
            // taking min value of already present value in list and new value
            distArr[adjList[f][i]] = min(temp, dis + 1);
            if (temp != distArr[adjList[f][i]])
                q.push(adjList[f][i]);
        }
    }
    if (distArr[end] != INT_MAX)
        cout << "Minimum path: " << distArr[end] << endl;
    else
        cout << "No valid path exists" << endl;
}

// shortest path in an undirected graph (using DFS) : [just changed the
// queue with a stack and the algorithm remains same]
void shortestPathDFS(vector<int> adjList[], int v)
{
    vector<int> distArr(v + 1, INT_MAX);
    int start, end;
    cout << "Enter the start and end location= ";
    cin >> start >> end;
    // distance moving from source to start should be 0 as start itself is source
    distArr[start] = 0;
    stack<int> s;
    // push to queue whenever distance changes to track further
    s.push(start);
    while (!s.empty())
    {
        int f = s.top();
        s.pop();
        int dis = distArr[f];
        // checking for all adjacent elements
        for (int i = 0; i < adjList[f].size(); i++)
        {

            int temp = distArr[adjList[f][i]];
            // taking min value of already present value in list and new value
            distArr[adjList[f][i]] = min(temp, dis + 1);
            if (temp != distArr[adjList[f][i]])
                s.push(adjList[f][i]);
        }
    }
    if (distArr[end] != INT_MAX)
        cout << "Minimum path: " << distArr[end] << endl;
    else
        cout << "No valid path exists" << endl;
}

int main()
{
    vector<int> adjList[11];
    cout << "Enter the edges:" << endl;
    for (int i = 0; i < 18; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
    }
    cout << "graph as adjacency list:" << endl;
    showList(adjList, 10);
    cout << "graph bfs:" << endl;
    bfsG(adjList, 10);
    cout << "graph dfs:" << endl;
    dfsG(adjList, 10);
    cout << "is cycle present?" << endl;
    if (cycleBFS(adjList, 10))
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    cout << "is cycle present?" << endl;
    if (cycleDFS(adjList, 10))
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    cout << "is bipartite graph?" << endl;
    if (isBipartiteBFS(adjList, 10))
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    cout << "is bipartite graph?" << endl;
    if (isBipartiteDFS(adjList, 10))
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    cout << endl;
    shortestPathBFS(adjList, 10);
    cout << endl;

    cout << endl;
    shortestPathDFS(adjList, 10);
    cout << endl;

    return 0;
}

/*
with cycle: (odd length)
1 4
2 6
3 5
3 8
4 1
4 7
5 3
5 6
6 2
6 5
6 9
7 4
8 3
8 9
9 6
9 8
9 10
10 9
*/

/*
without cycle:
1 4
2 6
3 5
3 8
4 1
4 7
5 3
6 2
6 9
7 4
8 3
8 9
9 6
9 8
9 10
10 9
*/
