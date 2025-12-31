#include<bits/stdc++.h>
using namespace std;

vector<int> topo;

int gcd( int a, int b){
	if( b == 0) return a;

	return gcd(b , a % b);
}

void dfs(int node, vector<int> &vis, vector<vector<int>> &adj, vector<int>& component, bool getSCC){

    vis[node] = 1;

    if( getSCC){
        component.push_back(node);
    }

    for(int x : adj[node]){
        if( !vis[x]) dfs(x, vis, adj, component, getSCC);
    }

    if( !getSCC){
        topo.push_back(node);
    }
}

void setGCD( int node, vector<set<int>> &dp, vector<set<int>> &cond_adj, vector<int> &vis, vector<int> &sccVal){
	vis[node ] = 1;

    dp[node].insert(sccVal[node]);

	for(int x : cond_adj[node]){
		// vis acts as if problem has been solved or not : checks like dp[node] != -1
		if( vis[x] == 0){
			setGCD( x, dp, cond_adj, vis, sccVal);
		}
        for(int j : dp[x]){
            dp[node].insert(gcd(sccVal[node], j));
        }
	}
}

int main(){

    const long long mod = 1e9 +7;
    int n, m;

    cin >> n >> m;

    vector<int> val(n+1, 0);

    for(int i = 1; i <= n ; i++) cin >> val[i];


    vector<vector<int>> adj(n+1 );

    vector<vector<int>> rev_adj(n+1);

    for(int i = 0; i < m ;i ++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        rev_adj[v].push_back(u);
    }

    vector<int> component;

    vector<int> vis(n+1, 0);

    for(int i = 1; i <= n ;i ++){
        if( vis[i] == 0){
            dfs(i, vis, adj, component, false);
        }
    }


    reverse(topo.begin(), topo.end() );

    fill(vis.begin(), vis.end(), 0);


	vector<int> roots(n+1, 0);
    // storing the value for th minGCd for esch SCC

	vector<int> sccVal(n+1, 0);
	int idx = 1;

    for( int node : topo){

        if( vis[node] == 0){
            component = {};
            dfs(node, vis, rev_adj, component, true);

            int minGCDForSCC = 0;
            for(int x : component){
			   if(minGCDForSCC == 0) minGCDForSCC = val[x];
               roots[x] = idx;
			   minGCDForSCC =  gcd( minGCDForSCC, val[x]);
            }

			sccVal[idx] = minGCDForSCC;
			idx++;
        }
        
    }

	int sccCount = idx -1;

	vector<set<int>> cond_adj(n+1);

    // form a new graph with the SCCs

    // root[i] -> roots[x] : it may be that there could be multiple edges from one scc to another scc
	for(int i = 1; i <= n ; i ++){
		for(int x : adj[i]){
			// i ->x
			if(roots[i] != roots[x]){
				// roots[i] -> roots[x];
				cond_adj[roots[i]].insert(roots[x]);
			}
		}
	}

    // dp[i] : contains all possible divisors starting from the path containing the node i
    vector<set<int>> dp(n+1);
	// use these values to get yourself started

	fill(vis.begin(), vis.end(), 0);

	// dp is the array storign the min value of gcd when you start from any of the nodes

	int minGCD = 1e6;

	for(int i = 1; i <= sccCount; i ++){
		if(vis[i] == 0){
			setGCD(i, dp, cond_adj, vis, sccVal);
		}
	}

	for(int i = 1 ; i <= sccCount ; i ++){
        minGCD = min( minGCD, *dp[i].begin());
	}

	cout << minGCD << endl;
    return 0;
}