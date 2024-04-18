#pragma once
#include <iostream>
#define INITIAL_CAPACITY 20
template <typename Telem>
class Iterator;

template <typename Telem>
class my_vector{
private:
    Telem* elemente;
    int lg;
    int cap;
    void redimensionare();

public:
    my_vector();

    //copy constructor
    my_vector(const my_vector& ot); //rule of 3

    ~my_vector();//rule of 3

    //operator assignment
    my_vector& operator=(const my_vector& ot);//rule of 3


    //move constructor
    my_vector(my_vector&& ot); //rule of 5

    //move assignment
    my_vector& operator=(my_vector&& ot); //rule of 5


    //Adauga in vector
    void push_back(const Telem& el);

    //sterge de pe pozitia poz
    void erase(int position);

    Telem& get(int poz) const;

    void set(int poz, const Telem& el);

    int size() const noexcept;

    bool empty() const noexcept;

    friend class Iterator<Telem>;
    //functii care creaza iteratori
    Iterator<Telem> begin();
    Iterator<Telem> end();

    Telem& operator[](int poz) const;

};

template<typename Telem>
Telem& my_vector<Telem>::operator[](int poz) const {
    return elemente[poz];
}

template<typename Telem>
my_vector<Telem>::my_vector() :elemente{ new Telem[INITIAL_CAPACITY] }, cap{ INITIAL_CAPACITY }, lg{ 0 } {}


template<typename Telem>
my_vector<Telem>::my_vector(const my_vector<Telem>& ot) {
    elemente = new Telem[ot.cap];
    //copiez elementele
    for (int i = 0; i < ot.lg; i++) {
        elemente[i] = ot.elemente[i];  //assignment din Pet
    }
    lg = ot.lg;
    cap = ot.cap;
}

template<typename Telem>
my_vector<Telem>& my_vector<Telem>::operator=(const my_vector<Telem>& ot) {
    if (this == &ot) {
        return *this;
    }
    delete[] elemente;
    elemente = new Telem[ot.cap];
    for (int i = 0; i < ot.lg; i++) {
        elemente[i] = ot.elemente[i];
    }
    lg = ot.lg;
    cap = ot.cap;
    return *this;
}

template<typename Telem>
my_vector<Telem>::~my_vector() {
    delete[] elemente;
}


template<typename Telem>
my_vector<Telem>::my_vector(my_vector&& ot) {
    // Copy the data pointer from other
    elemente = ot.elemente;
    lg = ot.lg;
    cap = ot.cap;

    ot.elemente = nullptr;
    ot.lg = 0;
    ot.cap = 0;
}

template<typename Telem>
my_vector<Telem>& my_vector<Telem>::operator=(my_vector<Telem>&& ot) {
    if (this == &ot) {
        return *this;
    }
    delete[] elemente;
    // Copy the data pointer from other
    elemente = ot.elemente;
    lg = ot.lg;
    cap = ot.cap;

    ot.elemente = nullptr;
    ot.lg = 0;
    ot.cap = 0;
    return *this;
}
template<typename Telem>
void my_vector<Telem>::redimensionare() {
    if (lg < cap) {
        return;
    }
    cap *= 2;
    auto* aux = new Telem[cap];
    for (int i = 0; i < lg; i++) {
        aux[i] = elemente[i];
    }
    delete[] elemente;
    elemente = aux;
}

template<typename Telem>
void my_vector<Telem>::push_back(const Telem& el) {
    if (lg == cap)
        redimensionare();
    elemente[lg++] = el;
}

template<typename Telem>
void my_vector<Telem>::erase(int position) {
    this->lg--;
    for (int i = position; i < this->lg; i++) {
        this->elemente[i] = this->elemente[i + 1];
    }
}

template<typename Telem>
Telem& my_vector<Telem>::get(int poz) const {
    return elemente[poz];
}

template<typename Telem>
void my_vector<Telem>::set(int poz, const Telem& el) {
    elemente[poz] = el;
}

template<typename Telem>
int my_vector<Telem>::size() const noexcept {
    return lg;
}

template<typename Telem>
bool my_vector<Telem>::empty() const noexcept {
    return lg == 0;
}

template<typename Telem>
Iterator<Telem> my_vector<Telem>::begin()
{
    return Iterator<Telem>(*this);
}

template<typename Telem>
Iterator<Telem> my_vector<Telem>::end()
{
    return Iterator<Telem>(*this, lg);
}

template<typename Telem>
class Iterator {
private:
    const my_vector<Telem>& vec; // ref la vectorul dinamic
    int poz = 0; // prima poz o sa fie 0
public:
    //constructor iterator
    Iterator(const my_vector<Telem>& v);

    Iterator(const my_vector<Telem>& v, int poz) noexcept;

    //veridica daca iteratorul e valid
    bool valid() const;

    //get element
    Telem& element() const;

    //trece la urmatorul element din vector
    void next();

    //suprascriu pointerul
    Telem& operator* ();

    //suprascriu operatorul de incrementare
    Iterator& operator++();

    //verific egalitatea
    bool operator==(const Iterator& ot) noexcept;
    bool operator!=(const Iterator& ot) noexcept;

};

template<typename Telem>
Iterator<Telem>::Iterator(const my_vector<Telem>& v) : vec{ v } {}


template<typename Telem>
Iterator<Telem>::Iterator(const my_vector<Telem>& v, int poz) noexcept :vec{ v }, poz{ poz } {}

template<typename Telem>
bool Iterator<Telem>::valid()const {
    return poz < vec.lg;
}

template<typename Telem>
Telem& Iterator<Telem>::element() const {
    return vec.elemente[poz];
}

template<typename Telem>
void Iterator<Telem>::next() {
    poz++;
}

template<typename Telem>
Telem& Iterator<Telem>::operator*() {
    return element();
}

template<typename Telem>
Iterator<Telem>& Iterator<Telem>::operator++() {
    next();
    return *this;
}

template<typename Telem>
bool Iterator<Telem>::operator==(const Iterator<Telem>& ot) noexcept {
    return ot.poz == poz;
}

template<typename Telem>
bool Iterator<Telem>::operator!=(const Iterator<Telem>& ot) noexcept {
    return !(*this == ot);
}

