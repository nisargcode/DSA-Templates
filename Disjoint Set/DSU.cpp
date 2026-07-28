#include <bits/stdc++.h>
using namespace std;

class DSU{
    vector<int>size , parent;
    public:
    DSU(int n){
        size.resize(n+1);
        parent.resize(n+1);
        for(int i=0 ; i<=n ; i++){
            size[i] = 1;
            parent[i] = i;
        }
    }
    int findUpar(int node){
        if(parent[node] == node) return node;
        return parent[node] = findUpar(parent[node]);
    }
    void unionBySize(int u , int v){
        int ultpu = findUpar(u);
        int ultpv = findUpar(v);
        
        if(size[ultpu] < size[ultpv]){
            size[ultpv] += size[ultpu];
            parent[ultpu] = ultpv;
        }
        else{
            size[ultpu] += size[ultpv];
            parent[ultpv] = ultpu;
        }
    }
};

int main() {
    
    DSU ds(4);
    ds.unionBySize(1 , 2);
    ds.unionBySize(3 , 4);
    if(ds.findUpar(3) == ds.findUpar(4)){
        cout << "Same Component" << endl;
    }
    else{
        cout << "Not in same Component" << endl;
    }
    if(ds.findUpar(1) == ds.findUpar(4)){
        cout << "Same Component" << endl;
    }
    else{
        cout << "Not in same Component" << endl;
    }
}
