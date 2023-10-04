/*
GRAPHS: REPRESENTATION, TRAVERSAL TECHNIQUES, CYCLE DETECTION
*/

#include<bits/stdc++.h>
using namespace std;
#define MAXEDGES 10

void showList(vector<int> adjList[], int v){
    for(int i=1; i<=v; i++){
        cout<<i<<" : ";
        auto s = adjList[i].begin();
        auto e = adjList[i].end();
        while(s!=e){
            cout<<*s<<" ";
            s++;
        }
        cout<<endl;
    }
}
// void bfsG(vector<int>adjList[],int v){
//     vector<int> visited(v+1,0);
//     // outer for loop ensures that the disconnected parts of the graph
//     // are also traversed
//     for(int i=1; i<=v; i++){
//         if(!visited[i]){
//             queue<int> q;
//             q.push(i);
//             visited[i]=1;
//             while(!q.empty()){
//                 int val = q.front();
//                 cout<<val<<" ";
//                 q.pop();
//                 for(int j=0; j<adjList[val].size(); j++){
//                     if(!visited[adjList[val][j]]){
//                         q.push(adjList[val][j]);
//                         visited[adjList[val][j]]=1;
//                     }
//                 }
//             }
//         }
//     }
// }
// void dfsG(vector<int>adjList[],int v){
//     vector<int> visited(v+1,0);
//     // outer for loop ensures that the disconnected parts of the graph
//     // are also traversed
//     for(int i=1; i<=v; i++){
//         if(!visited[i]){
//             stack<int> s;
//             s.push(i);
//             visited[i]=1;
//             while(!s.empty()){
//                 int val = s.top();
//                 cout<<val<<" ";
//                 s.pop();
//                 for(int j=0; j<adjList[val].size(); j++){
//                     if(!visited[adjList[val][j]]){
//                         s.push(adjList[val][j]);
//                         visited[adjList[val][j]]=1;
//                     }
//                 }
//             }
//         }
//     }
// }


// bool cycleBFS(vector<int>adjList[],int v){
//     vector<int> visited(v+1,0);
//     // outer for loop ensures that the disconnected parts of the graph
//     // are also traversed
//     for(int i=1; i<=v; i++){
//         if(!visited[i]){
//             queue<pair<int,int>> q;
//             q.push({i,-1});
//             visited[i]=1;
//             while(!q.empty()){
//                 int val = q.front().first;
//                 int par = q.front().second;
//                 // cout<<val<<" ";
//                 q.pop();
//                 for(int j=0; j<adjList[val].size(); j++){
//                     if(!visited[adjList[val][j]]){
//                         q.push({adjList[val][j],val});
//                         visited[adjList[val][j]]=1;
//                     }else{
//                         if(par!=adjList[val][j])
//                         return true;
//                     }
//                 }
//             }
//         }
//     }
//     return false;
// }
bool cyclingDFS(vector<int>adjList[], int i, vector<int>vis,vector<int>dfsVis){
    vis[i] = 1;
    dfsVis[i]=1;
    for(int j=0; j<adjList[i].size(); j++){
        if(!vis[adjList[i][j]]){
            if(cyclingDFS(adjList,adjList[i][j],vis,dfsVis))
            return true;
        }else{
            if(dfsVis[adjList[i][j]])
            return true;
        }
    }
    dfsVis[i]=0;
    return false;
}
bool cycleDFS(vector<int>adjList[],int v){
    vector<int> visited(v+1,0);
    vector<int> dfsPathVisited(v+1,0);
    // outer for loop ensures that the disconnected parts of the graph
    // are also traversed
    for(int i=1; i<=v; i++){
        if(!visited[i]){
            if(cyclingDFS(adjList,i,visited,dfsPathVisited))
            return true;
        }
    }
    return false;
}

void topologicalDFS(vector<int>adjList[], int i, vector<int>&vis, stack<int> &s){
    vis[i] = 1;
    for(int j=0; j<adjList[i].size(); j++){
        if(!vis[adjList[i][j]]){
            topologicalDFS(adjList,adjList[i][j],vis,s);
        }
    }
    s.push(i);
}
void topoDFS(vector<int>adjList[],int v){
    vector<int> visited(v+1,0);
    // additional stack data structure required for preserving order of elements
    stack<int> s;
    // outer for loop ensures that the disconnected parts of the graph
    // are also traversed
    for(int i=1; i<=v; i++){
        if(!visited[i]){
            topologicalDFS(adjList,i,visited,s);        // generating the order
        }
    }
    cout<<"Topological sorted order:"<<endl;
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

void topoBFS(vector<int> adjList[],int v){
    vector<int> ind(v+1);
    // calculating indegree of all the nodes/vertices
    for(int i=1; i<=v; i++){
        for(int j=0; j<adjList[i].size(); j++){
            ind[adjList[i][j]]++;
        }
    }

    queue<int> q;
    for(int i=1; i<=v; i++){
        if(ind[i]==0)
        q.push(i);
    }
    int count=0;
    while(!q.empty()){
        int val = q.front();
        q.pop();
        count++;
        cout<<val<<" ";
        for(int i=0; i<adjList[val].size(); i++){
            ind[adjList[val][i]]--;
            if(ind[adjList[val][i]]==0)
            q.push(adjList[val][i]);
        }
    }
    if(count==v) cout<<"\nthe graph is not cyclic!";
    else cout<<"\nthe graph is cyclic";
    cout<<endl;
}


// For finding the shortest path in directed acyclic graph we use Kahn's Algorithm
// of topological sorting, hence once we receive the sorted order of elements
// we now go on traversing the elemnets in order and check for its adjacent
// items and update the distance to it. This way we get the minimum distance of
// all vertices from the start
void dfsKahn(vector<pair<int,int>>adjList[],int i,vector<int>&vis,stack<int>&s){
    vis[i]=1;
    for(int j=0; j<adjList[i].size(); j++){
        if(!vis[adjList[i][j].first]){
            dfsKahn(adjList,adjList[i][j].first,vis,s);
        }
    }
    s.push(i);
}
void shortestPathKahn(vector<pair<int,int>>adjList[],int v){
    // here i will use DFS (stack) based implementation of Kahn's Algorithm
    vector<int> visited(v+1,0);
    // additional stack data structure required for preserving order of elements
    stack<int> s;
    vector<int> distArr(v+1,INT_MAX);
    int start,end;
    cout<<"Enter the start and the end= ";
    cin>>start>>end;
    distArr[start]=0;
    dfsKahn(adjList,start,visited,s);
    while(!s.empty()){
        int val = s.top();
        s.pop();
        int dis = distArr[val];
        for(int j=0; j<adjList[val].size(); j++){
            int temp = distArr[adjList[val][j].first];
            distArr[adjList[val][j].first]=min(temp,(dis+adjList[val][j].second));
        }
    }
    cout<<"Minimum distance= "<<distArr[end]<<endl;
}


int main(){
    // vector<int> adjList[11];

    // with cycle (odd length)
    // adjList[1].push_back(2);
    // adjList[2].push_back(3);
    // adjList[3].push_back(4);
    // adjList[3].push_back(6);
    // adjList[4].push_back(5);
    // adjList[5].push_back(10);
    // adjList[6].push_back(5);
    // adjList[7].push_back(2);
    // adjList[7].push_back(8);
    // adjList[8].push_back(9);
    // adjList[9].push_back(7);

    // without cycle
    // adjList[2].push_back(3);
    // adjList[3].push_back(1);
    // adjList[4].push_back(0);
    // adjList[4].push_back(1);
    // adjList[5].push_back(6);
    // adjList[5].push_back(2);



    // cout<<"graph as adjacency list:"<<endl;
    // showList(adjList,10);
    
    // if(cycleDFS(adjList,10))
    // cout<<"yes"<<endl;
    // else
    // cout<<"no"<<endl;

    // topoDFS(adjList,10);
    
    // topoBFS(adjList,10);

    // directed weighted acyclic graph:
    vector<pair<int,int>>adjList[11];
    adjList[1].push_back({2,2});
    adjList[2].push_back({3,1});
    adjList[3].push_back({4,3});
    adjList[3].push_back({6,6});
    adjList[4].push_back({5,5});
    adjList[5].push_back({10,4});
    adjList[6].push_back({5,1});
    adjList[7].push_back({2,3});
    adjList[7].push_back({8,1});
    adjList[8].push_back({9,4});

    cout<<endl;
    shortestPathKahn(adjList,10);
    cout<<endl;

    return 0;
}

/*
with cycle: (odd length)
1 2
2 3
3 4
4 5
5 10
6 5
7 8
8 9
9 7
10 
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
