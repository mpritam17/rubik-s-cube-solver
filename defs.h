#ifndef DEFS_H
#define DEFS_H


#include <vector>
#include <map>
#include <algorithm>
using namespace std;
class face {
    private :
        vector <vector <char>> colors;
    public:
        face(vector <vector <char>> f);
        face(const face &f);
        face F();
        face F_prime();
        face U(vector <char> ser, bool rev = false);
        face D(vector <char> ser, bool rev = false);
        face L(vector <char> ser, bool rev = false);
        face R(vector <char> ser, bool rev = false);
        int diff();
        vector <char> top_row();
        vector <char> bottom_row();
        vector <char> left_column();
        vector <char> right_column();

        bool operator < (const face &f) const;
        bool operator == (const face &f) const;

        // vector <vector <char>> get_colors() const;
        // need functions to declare such as - u->, u <-, l ^, l v, r ^, r v, b <-, b -> 
};

class cube {
    private:
        vector <face> a; // front, left, right, up, bottom, back;
        int cost;

    public:
        cube(vector <vector <vector <char>>> c);

        cube (face f1, face f2, face f3, face f4, face f5, face f6);

        void calculate_cost();

        int get_cost();

        cube F();
        cube F_prime();
        cube U();
        cube U_prime();
        cube D();
        cube D_prime();
        cube L();
        cube L_prime();
        cube R();
        cube R_prime();
        cube B();
        cube B_prime();

        bool operator < (const cube &c) const;
        bool operator == (const cube &c) const;

        // vector <face> get_faces() const {
        //     return a;
        // }
};

#endif