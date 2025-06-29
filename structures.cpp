#include <bits/stdc++.h>
using namespace std;

// There can be 12 cube operations : 
// Namely - U, U', D, D', L, L', R, R', F, F', B, B'
// and for each face, I have to define 10 operations

class face {
    private :
        vector <vector <char>> colors;
    public:
        face(vector <vector <char>> f) {
            colors = f;
        }

        void rotate_right() {
            vector <vector <char>> temp;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    int x = j, y = 2 - i;
                    temp[x][y] = colors[i][j];
                }
            }
            colors = temp;
        }

        void rotate_left() {
            vector <vector <char>> temp;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    int x = j, y = 2 - i;
                    temp[i][j] = colors[x][y];
                }
            }
            colors = temp;
        }

        int diff() {
            int d = 0;
            map <char, int> m;
            for (vector <char> &i: colors) {
                for (char &c : i) {
                    m[c]++;
                }
            }
            for (auto &p : m) {
                if (p.first != colors[1][1]) d++;
            }
            return d;
        }

        // need functions to declare such as - u->, u <-, l ^, l v, r ^, r v, b <-, b -> 
};

class cube {
    private:
        vector <face> a; // front, left, right, up, bottom, back;
        string seq;
        int cost = 0;
    public:
        cube(vector <vector <vector<char>>> c, string s) : seq(s) {
            for (int i = 0; i < 6; ++i) {
                a[i] = face(c[i]);
            }
        }
        void calculate_cost() {
            cost = seq.length();
            for (face &f : a) {
                cost += f.diff();
            }
            cost -= 6;
        }
        int get_cost() {
            return cost;
        }
        string get_seq() {
            return seq;
        }
};