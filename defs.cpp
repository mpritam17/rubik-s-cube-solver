#include "defs.h"
using namespace std;
face::face(vector <vector <char>> f) {
    colors = f;
}

face::face(const face &f){
    colors = f.colors;
}

face face::F() {
    vector <vector <char>> temp(3, vector <char>(3));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            int x = j, y = 2 - i;
            temp[x][y] = colors[i][j];
        }
    }
    face new_face(temp);
    return new_face;
}

face face::F_prime() {
    vector <vector <char>> temp(3, vector <char>(3));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            int x = j, y = 2 - i;
            temp[i][j] = colors[x][y];
        }
    }
    face new_face(temp);
    return new_face;
}

face face::U(vector <char> ser, bool rev) {
    if (rev) {
        reverse(ser.begin(), ser.end());
    }
    vector <vector <char>> temp;
    temp = colors;
    for (int i = 0; i < 3; ++i) temp[0][i] = ser[i];
    return face(temp);
}

face face::D(vector <char> ser, bool rev) {
    if (rev) {
        reverse(ser.begin(), ser.end());
    }
    vector <vector <char>> temp;
    temp = colors;
    for (int i = 0; i < 3; ++i) temp[2][i] = ser[i];
    return face(temp);
}

face face::L(vector <char> ser, bool rev) {
    if (rev) {
        reverse(ser.begin(), ser.end());
    }
    vector <vector <char>> temp;
    temp = colors;
    for (int i = 0; i < 3; ++i) temp[i][0] = ser[i];
    return face(temp);
}

face face::R(vector <char> ser, bool rev) {
    if (rev) {
        reverse(ser.begin(), ser.end());
    }
    vector <vector <char>> temp;
    temp = colors;
    for (int i = 0; i < 3; ++i) temp[i][2] = ser[i];
    return face(temp);
}

int face::diff() {
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

vector <char> face::top_row() {
    return colors[0];
}
vector <char> face::bottom_row() {
    return colors[2];
}
vector <char> face::left_column() {
    vector <char> col;
    for (int i = 0; i < 3; ++i) {
        col.push_back(colors[i][0]);
    }
    return col;
}
vector <char> face::right_column() {
    vector <char> col;
    for (int i = 0; i < 3; ++i) {
        col.push_back(colors[i][2]);
    }
    return col;
}

cube::cube(vector <vector <vector<char>>> c) {
    for (int i = 0; i < 6; ++i) {
        a.push_back(face(c[i]));
    }
}

cube::cube (face f1, face f2, face f3, face f4, face f5, face f6) {
    a.push_back(f1);
    a.push_back(f2);
    a.push_back(f3);
    a.push_back(f4);
    a.push_back(f5);
    a.push_back(f6);
}

void cube::calculate_cost() {
    cost = 0;
    for (face &f : a) {
        cost = max(cost, f.diff());
    }
}

int cube::get_cost() {
    return cost;
}

cube cube::F() {
    face temp0 = a[0].F();
    face temp1 = a[1].R(a[4].top_row());
    face temp2 = a[2].L(a[3].bottom_row());
    face temp3 = a[3].D(a[1].right_column(), true);
    face temp4 = a[4].U(a[2].left_column(), true);
    face temp5 = a[5];
    cube new_cube(temp0, temp1, temp2, temp3, temp4, temp5);
    new_cube.calculate_cost();
    return new_cube;
}

cube cube::F_prime() {
    face temp0 = a[0].F_prime();
    face temp1 = a[1].R(a[3].bottom_row(), true);
    face temp2 = a[2].L(a[4].top_row(), true);
    face temp3 = a[3].D(a[2].left_column());
    face temp4 = a[4].U(a[1].right_column());
    face temp5 = a[5];
    cube new_cube(temp0, temp1, temp2, temp3, temp4, temp5);
    new_cube.calculate_cost();
    return new_cube;
}

cube cube::U() {
    face temp0 = a[0].U(a[2].top_row());
    face temp1 = a[1].U(a[0].top_row());
    face temp2 = a[2].U(a[5].top_row(), true);
    face temp3 = a[3].F();
    face temp4 = a[4];
    face temp5 = a[5].D(a[1].top_row(), true);
    cube new_cube(temp0, temp1, temp2, temp3, temp4, temp5);
    new_cube.calculate_cost();
    return new_cube;
}

cube cube::U_prime() {
    face temp0 = a[0].U(a[1].top_row());
    face temp1 = a[1].U(a[5].top_row(), true);
    face temp2 = a[2].U(a[0].top_row());
    face temp3 = a[3].F_prime();
    face temp4 = a[4];
    face temp5 = a[5].D(a[2].top_row(), true);
    cube new_cube(temp0, temp1, temp2, temp3, temp4, temp5);
    new_cube.calculate_cost();
    return new_cube;
}

cube cube::D() {
    face temp0 = a[0].D(a[1].bottom_row());
    face temp1 = a[1].D(a[5].bottom_row(), true);
    face temp2 = a[2].D(a[0].bottom_row());
    face temp3 = a[3];
    face temp4 = a[4].F();
    face temp5 = a[5].D(a[2].bottom_row(), true);
    cube new_cube(temp0, temp1, temp2, temp3, temp4, temp5);
    new_cube.calculate_cost();
    return new_cube;
}

cube cube::D_prime() {
    face temp0 = a[0].D(a[2].bottom_row());
    face temp1 = a[1].D(a[0].bottom_row());
    face temp2 = a[2].D(a[5].bottom_row(), true);
    face temp3 = a[3];
    face temp4 = a[4].F_prime();
    face temp5 = a[5].D(a[1].bottom_row(), true);
    cube new_cube(temp0, temp1, temp2, temp3, temp4, temp5);
    new_cube.calculate_cost();
    return new_cube;
}

cube cube::L() {
    face temp0 = a[0].L(a[3].left_column());
    face temp1 = a[1].F();
    face temp2 = a[2];
    face temp3 = a[3].L(a[5].left_column(), true);
    face temp4 = a[4].L(a[0].left_column());
    face temp5 = a[5].R(a[1].left_column(), true);
    cube new_cube(temp0, temp1, temp2, temp3, temp4, temp5);
    new_cube.calculate_cost();
    return new_cube;
}

cube cube::L_prime() {
    face temp0 = a[0].L(a[4].left_column());
    face temp1 = a[1].F_prime();
    face temp2 = a[2];
    face temp3 = a[3].L(a[0].left_column());
    face temp4 = a[4].L(a[5].left_column(), true);
    face temp5 = a[5].R(a[3].left_column(), true);
    cube new_cube(temp0, temp1, temp2, temp3, temp4, temp5);
    new_cube.calculate_cost();
    return new_cube;    
}

cube cube::R() {
    face temp0 = a[0].R(a[4].right_column());
    face temp1 = a[1];
    face temp2 = a[2].F();
    face temp3 = a[3].R(a[0].right_column());
    face temp4 = a[4].R(a[5].right_column(), true);
    face temp5 = a[5].L(a[3].right_column(), true);
    cube new_cube(temp0, temp1, temp2, temp3, temp4, temp5);
    new_cube.calculate_cost();
    return new_cube;
}

cube cube::R_prime() {
    face temp0 = a[0].R(a[3].right_column());
    face temp1 = a[1];
    face temp2 = a[2].F_prime();
    face temp3 = a[3].R(a[5].right_column(), true);
    face temp4 = a[4].R(a[0].right_column());
    face temp5 = a[5].L(a[4].right_column(), true);
    cube new_cube(temp0, temp1, temp2, temp3, temp4, temp5);
    new_cube.calculate_cost();
    return new_cube;
}

cube cube::B() {
    face temp0 = a[0];
    face temp1 = a[1].L(a[4].bottom_row());
    face temp2 = a[2].R(a[3].top_row());
    face temp3 = a[3].U(a[1].left_column(), true);
    face temp4 = a[4].D(a[2].right_column(), true);
    face temp5 = a[5].F();
    cube new_cube(temp0, temp1, temp2, temp3, temp4, temp5);
    new_cube.calculate_cost();
    return new_cube;
}

cube cube::B_prime() {
    face temp0 = a[0];
    face temp1 = a[1].L(a[3].top_row(), true);
    face temp2 = a[2].R(a[4].bottom_row(), true);
    face temp3 = a[3].U(a[2].right_column());
    face temp4 = a[4].D(a[1].left_column());
    face temp5 = a[5].F_prime();
    cube new_cube(temp0, temp1, temp2, temp3, temp4, temp5);
    new_cube.calculate_cost();
    return new_cube;
}

bool face::operator < (const face &f) const {
    return colors < f.colors;
}

bool face::operator == (const face &f) const {
    return colors == f.colors;
}

bool cube::operator < (const cube &c) const {
    return a < c.a;
}

bool cube::operator == (const cube &c) const {
    return a == c.a;
}
