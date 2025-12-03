#include<bits/stdc++.h>
using namespace std;

void solve(int a, int b, int c , int d){

    
    vector<int> dx = {2,  2, 1,  1, -1, -1, -2 , -2};
    vector<int> dy = {1, -1, 2, -2, -2,  2, -1 , 1};

    // cost[i][j] : min cost from a,b to reach i,x
    vector<vector<long long>> cost (8, vector<long long> (8, 1e18));

    // {cost, {i,j}};
    priority_queue<pair<long long, pair<int,int>>, vector<pair<long long, pair<int,int>>> , greater<>> pq;

    cost[a][b] = 0;
    pq.push({0, {a,b}});

    while( !pq.empty()){

        long long currCost = pq.top().first;
         
        int row = pq.top().second.first;
        int col = pq.top().second.second;

        //cout << row << " " <<  col << " " << currCost << endl;
        pq.pop();


        if( row == c && col == d) {
            break;
        }
        if( currCost > cost[row][col]) continue;

        for( int i = 0 ; i <= 7 ; i ++){
            int newRow  = row + dx[i];
            int newCol = col + dy[i];

            if( newRow >= 0  && newRow <= 7 && newCol >= 0 && newCol <= 7){

                long long edgeWeight = (row * newRow) + (col * newCol);
                if( cost[newRow][newCol] > (edgeWeight + 1ll*currCost)){
                    cost[newRow][newCol] = edgeWeight + 1ll*currCost;

                    pq.push({cost[newRow][newCol], {newRow, newCol}});
                }
            }
        }
    }

    if( cost[c][d] == 1e18){
        cout << -1 << endl;
    }
    else {
        cout << cost[c][d] << endl;
    }

    return;
}

int main() {
    // Optimization for faster I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c, d; // a, b = start (r, c); c, d = end (r, c)
    
    // The loop condition attempts to read four integers. 
    // It continues as long as the read operation is successful (i.e., not EOF).
    while (cin >> a >> b >> c >> d) {
        // Assume the coordinates are within a reasonable grid size
        // If MAX_COORD (e.g., 8) is defined, the grid size is 8x8.
        
        solve(a, b, c, d);
        //cout << min_bucks << "\n";
    }

    return 0;
}