#include<bits/stdc++.h>
using namespace std;

// base con x 
bool compare1(pair<int,int> &a, pair<int,int> & b){
    return a.first < b.first;
}

// basd on y

bool compare2(pair<int,int> & a, pair<int,int> &b){
    return a.second < b.second;
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;

    cin >> n;
    // points can be from 1 to n 
    //  1<= xi, y1 <= 2e5

    // mp[x][y] => telling the nearest point
    // vis[x][y] for telling if seen or not in bfs

    set<pair<int,int>> st;

    map<int, pair<int,int>> idxToPoint;
    // idx -> {x,y}

    vector<pair<int,int>> points(n);
    for(int i = 0; i < n; i ++){

        int x, y;
        cin >> x >> y;
        points[i] = {x,y};
        st.insert({x,y});
        idxToPoint[i] = {x,y};
    }

    // {x,y} -> {nearestX, nesrtestY}
    map<pair<int,int>, pair<int,int>> nearestPoint;


    map<pair<int,int>, int> vis;

    queue<pair<int,int>> q;

    // sort(points.begin(), points.end(), compare1);

    // int prevVal = -1;
    // int next = 1;

    // for(int i = 0; i < n; i ++){

    //     int curr = points[i].first;
    //     //cout << points[i].first << " " << points[i].second << endl;

    //     if( i > 0 && curr != points[i-1].first){
    //         prevVal = points[i-1].first;
    //     }

    //     // next index
    //     while( next < n && (points[next].first == curr) ){
    //         next++;
    //     }

    //     if( i > 0 && next != n && (points[next].first == curr + 1) && (prevVal == curr - 1) ) continue;

    //     if( vis[points[i]] == 0) {
    //         q.push(points[i]);
    //         vis[points[i]] = 1;
    //     }
    // }

    // sort(points.begin(), points.end(), compare2);
    
    // prevVal = -1;
    // next = 1;

    // for(int i = 0; i < n; i ++){

    //     int curr = points[i].second;

    //     if( i > 0 && curr != points[i-1].second){
    //         prevVal = points[i-1].second;
    //     }

    //     // next index
    //     while( next < n && (points[next].second == curr)){
    //         next++;
    //     }

    //     if( i > 0 && next < n && (points[next].second == curr + 1) && (prevVal == curr - 1) ) continue;

    //     if( vis[points[i]] == 0) {
    //         q.push(points[i]);
    //         vis[points[i]] = 1;
    //     }
       
    // }

    
    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1};

    // STEP 1: Find actual boundary nodes explicitly
    for(int i = 0; i < n; i++){
        pair<int,int> p = points[i];
        
        for(int j = 0; j < 4; j++){
            int nRow = p.first + dx[j];
            int nCol = p.second + dy[j];
            pair<int,int> nNode = {nRow, nCol};

            // If a neighbor is NOT in the input set, 'p' is a boundary node
            if(st.count(nNode) == 0){
                if(vis[p] == 0) {
                    q.push(p);
                    vis[p] = 1;
                }
                // Record this empty coordinate as its closest excluded point
                nearestPoint[p] = nNode; 
            }
        }
    }
    
    // pushed all the nodes whcih have nearest exlused point just outside: not in centre at corner
    // 0,1 0,3, .. 3,4... 


    // q containing all the outer non surrounded nodes which will have atleasr one free neighbour which wil be their nearest neighbour
    while(!q.empty()){

        auto p = q.front(); 
        q.pop();

        int row = p.first;
        int col = p.second;

        // // for(int i = 0; i < 4; i ++){
        //     int nRow = row + dx[i];
        //     int nCol = col + dy[i];

        //     pair<int,int> nNode = {nRow, nCol};
        //     // nNode is the neigbours for a node in queue

        //     if( (st.count(nNode) == 0) ){
        //         // nNode is not in the list , hene a free node : can mark as the anser
        //         nearestPoint[p] = nNode;
        //     }
        //     // get the nearestPoint if not in set as that and set it once
        // }

        for(int i = 0; i < 4; i ++){
            int nRow = row + dx[i];
            int nCol = col + dy[i];

            pair<int,int> nNode = {nRow, nCol};
            // nNode is the neigbours for a node in queue

            // not in the queue or visited as outer/ boubdary node or already touched
            if(st.count(nNode) == 1 && vis[nNode] == 0){
                q.push(nNode);
                vis[nNode] = 1;
                nearestPoint[nNode] = nearestPoint[p];
            }
        }
    }

    for(int i = 0; i < n; i ++){
        pair<int,int> p = idxToPoint[i];

        auto nearest = nearestPoint[p];
        cout << nearest.first << " " << nearest.second << "\n";
    }
    return 0;
}
