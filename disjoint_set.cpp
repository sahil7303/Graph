#include<bits/stdc++.h>
#define VI vector<int>
#define VVI vector<vector<int>>

using namespace std;

//disjoint set union by rank

class DisjointSet{
    parentblic:
    vector<int> rank;
    vector<int> parent;     //ultimate parent

    DisjointSet(int n){
        rank = vector<int>(n+1, 1);
        parent = vector<int>(n+1);
        for(int i=0; i<n; i++)
            parent[i] = i;
    }

    void UnionByRank(int u, int v){
        int par_u = findParent(u);
        int par_v = findParent(v);

        if(par_u == par_v)  
            return;

        if(rank[u]>rank[v]){
            parent[par_v] = par_u;
        }
        else if(rank[u]<rank[v])
            parent[par_u] = par_v;
        else{
            parent[par_v] = par_u;
            rank[par_u]++;
        }
    }

    int findParent(int u){
        if(parent[u] == u)
            return u;

        parent[u] = findParent(parent[u]);
        return parent[u];
    }

    bool isDisjoint(int u, int v){
        if(findParent(u) == findParent(v))
            return false;
        
        return true;
    }

};

int main(){
    DisjointSet s(7);

    s.connectEdge(1,4);
    s.connectEdge(1,3);
    s.connectEdge(5,6);
    cout<<s.isDisjoint(6,1)<<endl;
    cout<<s.findParent(3);

    return 0;
}