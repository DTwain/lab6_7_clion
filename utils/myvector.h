//
// Created by obrej on 4/18/2024.
//

#ifndef LAB6_7_CLION_MYVECTOR_H
#define LAB6_7_CLION_MYVECTOR_H

#include "../Headers/carte.h"
#include "iterator.h"
typedef carte Telem;
typedef struct{
    Telem book;
    nod *urm;
    nod *prec;
}nod;

class myvector {
private:
    friend class iterator;
    nod *primul;
    nod *ultimul;
    int dimensiune;
public:
    myvector();

    myvector(const myvector& other); //copy constructor

    ~myvector(); // destroy constructor

    myvector& operator=(const myvector& other); // assignment overload

    void add(const Telem& elem);

    Telem& get(int poz) const;

    void

};


#endif //LAB6_7_CLION_MYVECTOR_H
