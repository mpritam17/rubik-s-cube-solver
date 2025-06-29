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

        face(face &f) {
            colors = f.colors;
        }

        face F() {
            vector <vector <char>> temp;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    int x = j, y = 2 - i;
                    temp[x][y] = colors[i][j];
                }
            }
            face new_face(temp);
            return new_face;
        }

        face F_prime() {
            vector <vector <char>> temp;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    int x = j, y = 2 - i;
                    temp[i][j] = colors[x][y];
                }
            }
            face new_face(temp);
            return new_face;
        }

        face U(vector <char> ser) {
            vector <vector <char>> temp;
            temp = colors;
            for (int i = 0; i < 3; ++i) temp[0][i] = ser[i];
            return face(temp);
        }

        face U_prime(vector <char> ser) {
            vector <vector <char>> temp;
            temp = colors;
            for (int i = 0; i < 3; ++i) temp[0][i] = ser[i];
            return face(temp);
        }

        face D(vector <char> ser) {
            vector <vector <char>> temp;
            temp = colors;
            for (int i = 0; i < 3; ++i) temp[2][i] = ser[i];
            return face(temp);
        }

        face D_prime(vector <char> ser) {
            vector <vector <char>> temp;
            temp = colors;
            for (int i = 0; i < 3; ++i) temp[2][i] = ser[i];
            return face(temp);
        }

        face L(vector <char> ser) {
            vector <vector <char>> temp;
            temp = colors;
            for (int i = 0; i < 3; ++i) temp[i][0] = ser[i];
            return face(temp);
        }

        face L_prime(vector <char> ser) {
            vector <vector <char>> temp;
            temp = colors;
            for (int i = 0; i < 3; ++i) temp[i][0] = ser[i];
            return face(temp);
        }
        
        face R(vector <char> ser) {
            vector <vector <char>> temp;
            temp = colors;
            for (int i = 0; i < 3; ++i) temp[i][2] = ser[i];
            return face(temp);
        }

        face R_prime(vector <char> ser) {
            vector <vector <char>> temp;
            temp = colors;
            for (int i = 0; i < 3; ++i) temp[i][2] = ser[i];
            return face(temp);
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
        int cost = 0;
    public:
        cube(vector <vector <vector<char>>> c) {
            for (int i = 0; i < 6; ++i) {
                a[i] = face(c[i]);
            }
        }

        cube (face f1, face f2, face f3, face f4, face f5, face f6) {
            a.push_back(f1);
            a.push_back(f2);
            a.push_back(f3);
            a.push_back(f4);
            a.push_back(f5);
            a.push_back(f6);
        }

        void calculate_cost() {
            cost = 0;
            for (face &f : a) {
                cost += f.diff();
            }
            cost -= 6;
        }
        int get_cost() {
            return cost;
        }
};