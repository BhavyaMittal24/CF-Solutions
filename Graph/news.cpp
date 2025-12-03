#include<bits/stdc++.h>
using namespace std;;


void dfs( int node, vector<set<int>> adj, vector<int> &vis, int color, int & count){

    vis[node] = color;
    count++;

    for( int x : adj[node]){
        if( !vis[x]){
            dfs(x, adj, vis, color, count);
        }
    }
}
int main(){

    int n, m;
    cin >> n >> m;

    vector<set<int>> adj(n+1);

    // m groups
    for(int i = 0 ; i < m ; i ++){
        int k;
        cin >> k;
        set<int> s;

        // list of users in a group

        // logk * k
        for(int j = 0; j < k ; j ++){
            int ele;
            cin >> ele;
            s.insert(ele);
        }

        // ele .... st
        // new set for ele : st.erase(ele) + old set

        // k logk * lokk
        for( auto it : s){
            int ele = it;
            set<int> original = adj[ele];
            
            set<int> append = s;

            append.erase(ele);
            if( append.size()  > original.size()) {
                swap(original, append);
            }

            while( !append.empty()){
                original.insert(*append.begin());
                append.erase(append.begin());
            }
            adj[ele] = original;  
        }
    }

    vector<int> vis(n+1,0);

    map<int,int> mp;

    int color = 1;
    for(int i  = 1; i <=n; i ++){

        if( !vis[i]){
            int count = 0;
            dfs(i, adj, vis, color, count);
            mp[color] = count;
            color++;
        }
    }

    for(int i = 1; i<=n ; i ++){
        // vis[i] gives color for that connected component
        cout << mp[vis[i]] << " ";
    }
    return 0;
}