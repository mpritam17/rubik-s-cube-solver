#include <bits/stdc++.h>
using namespace std;

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

        int diff(int) {
            int d = 0;
            for (vector <char> &i: colors) {
                for (char &c : i) {
                    if (c != colors[1][1]) d++;
                }
            }
            return d;
        }

        // need functions to declare such as - u->, u <-, l ^, l v, r ^, r v, b <-, b -> 
};

class cube {
    private:
        vector <face> a; // front, left, right, up, bottom, back;
    public:
        cube(vector <vector <vector<char>>> c) {
            for (int i = 0; i < 6; ++i) {
                a[i] = face(c[i]);
            }
        }

};