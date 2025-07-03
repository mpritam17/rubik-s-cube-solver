#include "algo.h"
// #include "defs.h"
using namespace std;
// what I want to do is create a priotity queue which will provide me the next set to visit
// Until I reach the solved state, I can mark the visited states is std::map
// I also need to store the strings, Can I do that using a map?
// Ofcourse, I can use the same map as visited to store the strings as well


string solve (cube c) {
    c.calculate_cost();
    c.print();
    vector <string> moves = {"F", "F'", "U", "U'", "D", "D'", "L", "L'", "R", "R'", "B", "B'"};
    priority_queue <pair <int, cube>> pq;
    map <cube, string> path;
    map <cube, bool> visited;
    path[c] = "";
    pq.push({-c.get_cost(), c});
    while (!pq.empty()) {
        cube curr = pq.top().second;
        pq.pop();
        if (visited[curr]) {
            continue;
        }
        visited[curr] = true;
        // cout << path[curr] << '\n';
        if (curr.get_cost() == 0) return path[curr];
        cube next = curr.F();
        if (!visited[next]) {
            string s = path[curr] + "1";
            if (path[next].size() == 0 || path[next].size() > s.size()) {
                path[next] = s;
                pq.push({-(next.get_cost()+s.size()), next});
            }
        }
        next = curr.F_prime();
        if (!visited[next]) {
            string s = path[curr] + "2";
            if (path[next].size() == 0 || path[next].size() > s.size()) {
                path[next] = s;
                pq.push({-(next.get_cost()+s.size()), next});
            }
        }
        next = curr.U();
        if (!visited[next]) {
            string s = path[curr] + "3";
            if (path[next].size() == 0 || path[next].size() > s.size()) {
                path[next] = s;
                pq.push({-(next.get_cost()+s.size()), next});
            }
        }
        next = curr.U_prime();
        if (!visited[next]) {
            string s = path[curr] + "4";
            if (path[next].size() == 0 || path[next].size() > s.size()) {
                path[next] = s;
                pq.push({-(next.get_cost()+s.size()), next});
            }
        }
        next = curr.D();
        if (!visited[next]) {
            string s = path[curr] + "5";
            if (path[next].size() == 0 || path[next].size() > s.size()) {
                path[next] = s;
                pq.push({-(next.get_cost()+s.size()), next});
            }
        }
        next = curr.D_prime();
        if (!visited[next]) {
            string s = path[curr] + "6";
            if (path[next].size() == 0 || path[next].size() > s.size()) {
                path[next] = s;
                pq.push({-(next.get_cost()+s.size()), next});
            }
        }
        next = curr.L();
        if (!visited[next]) {
            string s = path[curr] + "7";
            if (path[next].size() == 0 || path[next].size() > s.size()) {
                path[next] = s;
                pq.push({-(next.get_cost()+s.size()), next});
            }
        }
        next = curr.L_prime();
        if (!visited[next]) {
            string s = path[curr] + "8";
            if (path[next].size() == 0 || path[next].size() > s.size()) {
                path[next] = s;
                pq.push({-(next.get_cost()+s.size()), next});
            }
        }
        next = curr.R();
        if (!visited[next]) {
            string s = path[curr] + "9";
            if (path[next].size() == 0 || path[next].size() > s.size()) {
                path[next] = s;
                pq.push({-(next.get_cost()+s.size()), next});
            }
        }
        next = curr.R_prime();
        if (!visited[next]) {
            string s = path[curr] + "A";
            if (path[next].size() == 0 || path[next].size() > s.size()) {
                path[next] = s;
                pq.push({-(next.get_cost()+s.size()), next});
            }
        }
        next = curr.B();
        if (!visited[next]) {
            string s = path[curr] + "B";
            if (path[next].size() == 0 || path[next].size() > s.size()) {
                path[next] = s;
                pq.push({-(next.get_cost()+s.size()), next});
            }
        }
        next = curr.B_prime();
        if (!visited[next]) {
            string s = path[curr] + "C";
            if (path[next].size() == 0 || path[next].size() > s.size()) {
                path[next] = s;
                pq.push({-(next.get_cost()+s.size()), next});
            }
        }
    }
    return "No solution found";
}