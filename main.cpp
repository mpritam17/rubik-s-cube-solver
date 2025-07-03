#include "algo.h"
#include "defs.h"
#include <iostream>
#include <string>

int main() {
    vector <vector <vector <char>>> initial_state = { // front, left, right, up, bottom, back;
        {{'R', 'W', 'R'}, {'W', 'W', 'W'}, {'W', 'W', 'W'}},
        {{'G', 'G', 'W'}, {'G', 'G', 'G'}, {'G', 'G', 'G'}},
        {{'W', 'B', 'B'}, {'B', 'B', 'B'}, {'B', 'B', 'B'}},
        {{'R', 'R', 'R'}, {'R', 'R', 'R'}, {'G', 'R', 'B'}},
        {{'O', 'O', 'O'}, {'O', 'O', 'O'}, {'O', 'O', 'O'}},
        {{'Y', 'Y', 'Y'}, {'Y', 'Y', 'Y'}, {'Y', 'Y', 'Y'}}
    };
    cube c(initial_state);
    string ans = solve(c);
    cout << "Solution: " << ans << '\n';
    cout << "Number of moves: " << ans.length() << '\n';
    // cout << ans << '\n';
    return 0;
}