#include<bits/stdc++.h>
using namespace std;

void solve(){

    int n, x, s;

    cin >> n >> x >> s;

    vector<int> tables(x,0);
    // 0 to x-1 tables are there

    string friends;
    cin >> friends;

    int cnt = 0;

    vector<int> ambivertsAsExtroverts;
    // tableNOs where thr e ambiverts are rpesent as exporoverts
    for(int i = 0; i < n; i++){

        if(cnt >= (x*s)) continue;

        // for ambivert give him any table , but possible not empty

        if(friends[i] == 'A'){

            // look for non emptty

            int emptyTable = -1;
            int occupiedTable = -1;
           // bool match = false;

            for(int j = 0; j < x; j++){

                if(tables[j] > 0 && tables[j] < s){
                   
                    if(occupiedTable == -1) occupiedTable = j;

                    else if(tables[j] < tables[occupiedTable]) occupiedTable = j;
                    // cnt++;
                    // break;
                }

                // found some empty table
                else if(tables[j] == 0){
                    if(emptyTable == -1) emptyTable = j;
                }
            }

           
            // place at a non empty table as extrovert which we can always swap if there is space
            if(occupiedTable != -1){
                tables[occupiedTable]++;
                ambivertsAsExtroverts.push_back(occupiedTable);
                cnt++;
            }

            // placed as an introvert : they wont be moved now, once seated th are fixed now, tough to move
            else {
                tables[emptyTable]++;
                cnt++;
            }

        }

        // for an introvert givw him the empty table only
        else if(friends[i] == 'I') {

            // look for an empty table
             for(int j = 0; j < x; j++){
                // space but not fully empty
                if(tables[j] == 0){
                    tables[j]++;
                    cnt++;
                    break;
                }
            }
        }

        else {
            // Extrvoert
            int occupiedTable = -1;
            int emptyTable = -1;
            for(int j = 0; j < x; j++){
                // space but not fully empty
                if(tables[j] > 0 && (tables[j] < s)){

                    if(occupiedTable == -1) occupiedTable = j;

                    else if(tables[j] < tables[occupiedTable]) occupiedTable = j;
                }

                else if( tables[j] == 0){
                    emptyTable = j;
                }
            }

            if(occupiedTable != -1 ){
                tables[occupiedTable]++;
                cnt++;
            }
            // 1,4,5,6 .. these are ambiverts as extroverts in occupid tables
            // we want to try opening a new table using this extrovert
            else if( (ambivertsAsExtroverts.size() > 0) && (emptyTable != -1) ){

                // There is some empty table whcih is present and some ambiverts in full tables
                int tableNo = ambivertsAsExtroverts.back();
                ambivertsAsExtroverts.pop_back();
                //tables[tableNo]--;
                // put extrovert in that table where ambivert was there 
                tables[emptyTable] = 1; // AE
                cnt++;
            }
        }
    }

    cout << cnt << "\n";
    return;
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}