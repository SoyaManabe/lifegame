#include <bits/stdc++.h>
using namespace std;
random_device rnd;

int main(){
    using table_t = vector<vector<bool>>;
    int m,n;
    cin >> m >> n;
    const int M = m;
    const int N = n;
    table_t table(M, vector<bool>(N));

    int d;
    cin >> d;

    for (int i=0; i<d; i++){
        table.at(rnd()%m).at(rnd()%n) = true;
    }

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
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    return 0;
}