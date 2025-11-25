#include<bits/stdc++.h>
using namespace std;


int dx[] = {0,0,1,-1};
int dy[] = {-1,1,0,0};


// returns if cycle is present or not
bool dfs( int row, int col, int parentRow, int parentCol, vector<vector<char>> & grid, vector<vector<int>>& vis, char dotColor){

    vis[row][col] = 1;

    int n = grid.size();
    int m = grid[0].size();

    // adj matrix  : look for all the adj nodes in all 4 directions: top, down, left, right
    for(int i = 0; i < 4; i++){
        int newRow = row + dx[i];
        int newCol = col + dy[i];

        if( newRow >= 0 && newRow < n && newCol >=0 && newCol < m && grid[newRow][newCol] == dotColor ){
            
            if (vis[newRow][newCol] == 0){
                // explore all the 4 children and see if if not visited already and in any of the paths, if there is a trye path : return it
                if (dfs(newRow, newCol, row, col, grid , vis, dotColor)){
                    return true;
                };
            }
            else if( (vis[newRow][newCol] == 1) && (newRow != parentRow) && (newCol != parentCol) ){
                return true;
            }   
        }
    }
    return false;
}
int main(){

    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n,vector<char>(m));

    // grid storing dots of maximum 26 colors

    for(int i = 0; i < n ; i++){
        for(int j = 0; j < m; j++){
            char dot;
            cin >> dot;
            grid[i][j] = dot;
        }
    }

    bool ans = false;


    char initialColor = 'A';

    for( int l=0; l < 26; l ++){
        char newColor = initialColor + l;

        vector<vector<int>> vis(n, vector<int> (m,0));

        // in any of the connected components of some color 'C', if there is a cycle : retunr true;
        // else if in the entire connected component, you found no cycle, mark it visited : so no point in visiting other nodes of the same cycle.
        for(int i = 0; i < n ;i++ ){
            for(int j = 0; j < m;  j++){

                if( (grid[i][j] == newColor) && (vis[i][j] == 0) )  {

                    bool isCyclePresent = dfs(i,j, -1,-1, grid, vis, newColor);
                    if(isCyclePresent) {
                        ans = true;
                        break;
                    }
                }
            }
        }
    }

    if(ans) cout << "Yes \n";
    else cout << "No \n";

    return 0;
}