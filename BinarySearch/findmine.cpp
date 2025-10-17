#include<bits/stdc++.h>
using namespace std;

int findManhattenDistance(int x, int y){
    cout << "? " << x << " " << y << endl;
    int d;
    cin >> d;
    return d;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        int m;
        cin >> n >> m;
        int x = 1;
        int y = 1;
        int d = findManhattenDistance(x, y);
        if(d == 0){
            cout << "! " << x << " " << y << endl;
            continue;
        }
        int x1 = min(1+d, n);
        int y1 = 2 + d-x1;
        int y2 = min(1+d,m);
        int x2 = 2+d-y2;
        int d1 = findManhattenDistance(x1, y1);

        int d2 = findManhattenDistance(x2, y2);

        if( d1 == 0) {
            cout << "! " << x1 << " " << y1 << endl;
            continue;
        }

        if( d2 == 0){
            cout << "! " << x2 << " " << y2 << endl;
            continue;
        }
        if(d1 % 2 == 0){
            int x3 = x1 - d1/2;
            int y3 = y1 + d1/2;
            int d3 = findManhattenDistance(x3, y3);
            if(d3 == 0){
                cout << "! " << x3 << " " << y3 << endl;
                continue;
            }
        }

        cout << "! " << x2+d2/2 << " " << y2 - d2/2 << endl;
    }
    return 0;

}