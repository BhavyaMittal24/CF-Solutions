#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<string> maze(n);

    pair<int,int> start, end;
    for(int i = 0; i < n; i ++){
        string s;
        cin >> s;

        for(int j = 0; j < m; j ++){
            if(s[j] == 'A'){
                start  = {i,j};
            }
            else if(s[j] == 'B'){
                end = {i,j};
            }
        }

        maze[i] = s;
        // n * m maze of n rows and each row has size m
    }

    //cout << start.first << " " << start.second << "\n";

    //cout << end.first <<   "  " << end.second << "\n";
     // mao of which cell leads to the current cell
    // map<pair, pair> parent
    // tells me the parent of the current cell

    /// go from start to end;

    vector<vector<int>> vis(n, vector<int> (m,0));
    // vis : n * m : with each value as 0 : vis[i][j] = 0;

    queue<pair<int,int>> q;

    map<pair<int,int> , pair<int,int>> parent;
    q.push(start);

    int dx[4] = {1,-1, 0,0};
    int dy[4] = {0, 0, 1, -1};
    //          D  U R L

    vis[start.first][start.second] = 1;

    while( !q.empty() && vis[end.first][end.second] == 0){

        auto node = q.front();
        q.pop();

        int row = node.first;
        int col = node.second;

        //cout << row << " " << col << "\n";
        for(int i = 0; i < 4; i ++){
            int nrow = row + dx[i];
            int ncol = col + dy[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && (maze[nrow][ncol] != '#') && (vis[nrow][ncol] == 0) ){
                
                q.push({nrow, ncol});

                pair<int,int> key = {nrow, ncol};
                parent[key] = {row, col};
                
                vis[nrow][ncol]  =1;

                if(nrow == end.first && ncol == end.second){
                    break;
                }
            }
        }

    }
 

    if(vis[end.first][end.second] == 0){
        cout << "NO\n";
        return 0;
    }


    // trace the path from start to end

    string path = "";

    int currRow = end.first;
    int currCol = end.second;

    while( (currRow != start.first) || (currCol != start.second)){

        //cout << currRow << " " << currCol << "\n";


        auto parentPair = parent[{currRow, currCol}];

        int parentRow = parentPair.first;
        int parentCol = parentPair.second;

        if( parentRow == currRow){

            int x = parentCol - currCol;
            if(x == -1){
                // parentCol -> currCol
                path += 'R';
            }
            else {
                path += 'L';
            }
        }

        else {

            int y = parentRow - currRow;

            if(y == -1){
                path += 'D';
            }
            else {
                path += 'U';
            }
        }

        currRow = parentRow;
        currCol = parentCol; 
    }

    reverse(path.begin(), path.end());

    cout << "YES\n";
    cout << path.length() << "\n";
    cout << path << "\n";

    return 0;
}
