#include<bits/stdc++.h>
using namespace std;

int main(){

    int n, m;
    cin >> n  >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            cin >> grid[i][j];
        }
    }

    // parent of any {i,j} from where it came
    vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>> (m));

    int startRow = 0;
    int startCol = 0;

    int endRow = 0;
    int endCol = 0;
    vector<vector<int>> vis(n, vector<int>(m, 0));

    for(int i=0; i < n; i++){
        for(int j = 0; j < m; j ++){
            if( grid[i][j] == 'A'){
                startRow = i;
                startCol = j;
            }

            else if( grid[i][j] == 'B'){
                endRow = i;
                endCol = j;
            }
        }
    }

    queue<pair<int,int>> q;

    vis[startRow][startCol] = 1;
    q.push({startRow, startCol});


    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};


   
    while(!q.empty()){

        auto currNode = q.front();
        q.pop();
        
        int row = currNode.first;
        int col = currNode.second;

        for(int i=0;i<4;i++){
            int newRow = row + dx[i];
            int newCol = col + dy[i];

            if( newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] != '#' ){
                
                // newRow, newCol is not visited yet : 
                if( vis[newRow][newCol] == 0) {
                    
                    vis[newRow][newCol] = 1;
                    parent[newRow][newCol] = {row, col};
                    q.push({newRow, newCol});

                    if( grid[newRow][newCol] == 'B'){
                        break;
                    }
                }
            }
        }
    }

    
                      // parent of child1
    // node1      ->  child1
    // A -->ith node               B

    if( vis[endRow][endCol] == 0) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    char curr = 'B';

    int row = endRow;
    int col = endCol;

    vector<char> path;

    while ( curr != 'A'){
        pair<int,int> parentElement = parent[row][col];
        int parentRow = parentElement.first;
        int parentCol = parentElement.second;
        char dir;
        

        //cout << row << " " << col << endl;
        if( row == parentRow) {
            dir = (col - parentCol == 1) ? 'R' : 'L';
        }

        else if( col == parentCol){
            dir = (row - parentRow == 1) ? 'D' : 'U';
        }

        path.push_back(dir);

        curr = grid[parentRow][parentCol];
        row = parentRow;
        col = parentCol;
    }

    cout << path.size() << endl;
    reverse(path.begin(), path.end());

    for( auto it : path){
        cout << it ;
    }
}