#include <bits/stdc++.h>
using namespace std;
random_device rnd;

int main(){
    using table_t = vector<vector<bool>>;
    int m,n;
    // m = 29, n = 47
    cin >> m >> n;
    const int M = m;
    const int N = n;
    table_t table(M, vector<bool>(N));
    /*
    int d;
    cin >> d;
    
    for (int i=0; i<d; i++){
        table.at(rnd()%m).at(rnd()%n) = true;
    }
    */
    //Initialization for gun
    table.at(10).at(5) = true;
    table.at(11).at(5) = true;
    table.at(12).at(5) = true;
    table.at(12).at(6) = true;
    table.at(11).at(7) = true;
    table.at(14).at(7) = true;
    table.at(15).at(7) = true;
    table.at(14).at(8) = true;
    table.at(16).at(8) = true;
    table.at(14).at(9) = true;
    table.at(12).at(13) = true;
    table.at(13).at(13) = true;
    table.at(13).at(14) = true;
    table.at(14).at(14) = true;
    table.at(16).at(14) = true;
    table.at(17).at(14) = true;
    table.at(18).at(14) = true;
    table.at(12).at(15) = true;
    table.at(16).at(15) = true;
    table.at(17).at(16) = true;
    table.at(18).at(19) = true;
    table.at(19).at(19) = true;
    table.at(17).at(20) = true;
    table.at(18).at(20) = true;
    table.at(19).at(21) = true;
    table.at(18).at(25) = true;
    table.at(19).at(25) = true;
    table.at(20).at(25) = true;
    table.at(18).at(26) = true;
    table.at(19).at(27) = true;
    table.at(10).at(27) = true;
    table.at(11).at(27) = true;
    table.at(11).at(28) = true;
    table.at(12).at(28) = true;
    table.at(14).at(28) = true;
    table.at(15).at(28) = true;
    table.at(16).at(28) = true;
    table.at(10).at(29) = true;
    table.at(14).at(29) = true;
    table.at(15).at(30) = true;
    table.at(16).at(33) = true;
    table.at(17).at(33) = true;
    table.at(26).at(33) = true;
    table.at(27).at(33) = true;
    table.at(15).at(34) = true;
    table.at(16).at(34) = true;
    table.at(26).at(34) = true;
    table.at(28).at(34) = true;
    table.at(17).at(35) = true;
    table.at(26).at(35) = true;
    table.at(8).at(39) = true;
    table.at(9).at(39) = true;
    table.at(10).at(39) = true;
    table.at(10).at(40) = true;
    table.at(9).at(41) = true;
    table.at(12).at(41) = true;
    table.at(13).at(41) = true;
    table.at(12).at(42) = true;
    table.at(14).at(42) = true;
    table.at(12).at(43) = true;
    table.at(21).at(44) = true;
    table.at(22).at(44) = true;
    table.at(23).at(44) = true;
    table.at(21).at(45) = true;
    table.at(22).at(46) = true;

    auto at_cell= [&](auto const& table, auto x, auto y){
        return x < 0 || M <= x ? false
            :  y < 0 || N <= y ? false
            : table.at(x).at(y);
    };

    auto dead_or_alive = [&](auto table, auto x, auto y){
        auto cell = at_cell(table, x, y);
        auto count = at_cell(table, x - 1, y - 1)
                   + at_cell(table, x - 0, y - 1)
                   + at_cell(table, x + 1, y - 1)
                   + at_cell(table, x + 1, y - 0)
                   + at_cell(table, x + 1, y + 1)
                   + at_cell(table, x - 0, y + 1)
                   + at_cell(table, x - 1, y + 1)
                   + at_cell(table, x - 1, y - 0);
        return cell ? count == 3 || count == 2 : count == 3;
    };

    auto update = [&](auto const& table){
        table_t result = table;
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                result.at(i).at(j) = dead_or_alive(table, i, j);
            }
        }
        return result;
    };

    auto print = [&](auto const& table){
        system("clear");

        cout << string(N+2, '-') << "\n";
        bool death_flg = true;
        for(auto&& row : table){
            cout << "|";
            for(auto&& cell : row){
                if(death_flg && cell) death_flg = false;
                cout << (cell ? "*" : " ");
            } 
            cout << "|\n";
        }
        cout << string(N+2, '-') << "\n";
        cout << (death_flg ? "Life is dead" : "");
        cout << endl;
    };

    while(1){
        print(table);
        table = update(table);
        this_thread::sleep_for(chrono::milliseconds(50));
    }
    return 0;
}