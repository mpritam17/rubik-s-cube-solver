#include "algo.h"
#include "defs.h"
#include <iostream>
#include <string>

int main() {
    vector <vector <vector <char>>> initial_state = { // front, left, right, up, bottom, back;
        {{'G', 'G', 'G'}, {'R', 'R', 'R'}, {'R', 'R', 'R'}},
        {{'O', 'O', 'O'}, {'G', 'G', 'G'}, {'G', 'G', 'G'}},
        {{'R', 'R', 'R'}, {'B', 'B', 'B'}, {'B', 'B', 'B'}},
        {{'Y', 'Y', 'Y'}, {'Y', 'Y', 'Y'}, {'Y', 'Y', 'Y'}},
        {{'B', 'B', 'B'}, {'O', 'O', 'O'}, {'O', 'O', 'O'}},
        {{'W', 'W', 'W'}, {'W', 'W', 'W'}, {'W', 'W', 'W'}}
    };
    cube c(initial_state);
    string ans = solve(c);
    cout << "Solution: " << ans << '\n';
    cout << "Number of moves: " << ans.length() << '\n';
    // cout << ans << '\n';
    return 0;
}