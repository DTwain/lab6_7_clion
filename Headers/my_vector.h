#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#define CAPACITY 20

template<typename TElem> class iterator_vector;

template<typename TElem> class my_vector{
private:
    int capacity,
        nr_elemente;
    TElem* vec;
    void redimensionare_vec();
public:
    my_vector();

    ~my_vector();

    // copy constructor
    my_vector(const my_vector& other);

    // assigment overload
    my_vector& operator=(my_vector& other);

    //move constructor
    my_vector(my_vector&& other);

    //move assigment
    my_vector& operator=(my_vector&& other) noexcept;

    // pentru a accesa my_vec_obj[poz]
    TElem& operator[](int poz) const;

    void add(const TElem& elem);

    void erase(int poz);

    void modify(const TElem& modified_elem);

    const TElem& get_elem(int poz) const noexcept;

    int size() const noexcept;

    friend class iterator_vector<TElem>;
    iterator_vector<TElem> begin() const;
    iterator_vector<TElem> end() const;

};

template<typename TElem>
void my_vector<TElem>::redimensionare_vec() {
    capacity *= 2;
    TElem *new_vec = new TElem[capacity];
    for(int i = 0; i < nr_elemente; ++i)
        new_vec[i] = vec[i];
    delete[] vec;
    vec = new_vec;
}

template<typename TElem>
my_vector<TElem>::my_vector() {
    this->vec = new TElem[CAPACITY];
    this->capacity = CAPACITY;
    this->nr_elemente = 0;
}

template<typename TElem>
my_vector<TElem>::~my_vector() {
    delete[]vec;
}

template<typename TElem>
my_vector<TElem>::my_vector(const my_vector<TElem> &other) {
    this->vec = new TElem[other.capacity];
    for(int i = 0; i < other.nr_elemente; ++i)
        vec[i] = other.vec[i];

    this->nr_elemente = other.nr_elemente;
    this->capacity = other.capacity;
}

template<typename TElem>
my_vector<TElem>& my_vector<TElem>::operator=(my_vector<TElem> &other) {
    if(this == &other)
        return *this;
    delete[] this->vec;

    this->capacity = other.capacity;
    this->nr_elemente = other.nr_elemente;
    this->vec = other.vec;

    other.vec = nullptr;
    other.capacity = 0;
    other.nr_elemente = 0;
    return *this;
}

template<typename TElem>
my_vector<TElem>::my_vector(my_vector<TElem> &&other) {
    this->vec = other.vec;
    this->nr_elemente = other.nr_elemente;
    this->capacity = other.capacity;

    other.vec = nullptr;
    other.nr_elemente = 0;
    other.capacity = 0;
}

template<typename TElem>
my_vector<TElem>& my_vector<TElem>::operator=(my_vector<TElem> &&other) noexcept {
    if(this == &other)
        return *this;
    delete[] this->vec;

    this->capacity = other.capacity;
    this->nr_elemente = other.nr_elemente;
    this->vec = other.vec;

    other.vec = nullptr;
    other.capacity = 0;
    other.nr_elemente = 0;
    return *this;
}

template<typename TElem>
TElem& my_vector<TElem>::operator[](int poz) const {
    return vec[poz];
}

template<typename TElem>
void my_vector<TElem>::add(const TElem &elem) {
    if(capacity == nr_elemente)
        redimensionare_vec();
    this->vec[nr_elemente] = elem;
    nr_elemente += 1;
}

template<typename TElem>
void my_vector<TElem>::erase(int poz) {
    for(int i = poz; i < nr_elemente - 1; ++i){
        this->vec[i] = this->vec[i + 1];
    }
    this->nr_elemente -= 1;
}

template<typename TElem>
void my_vector<TElem>::modify(const TElem &modified_elem) {
    int poz = 0;
    for(int i = 0; i < nr_elemente; ++i)
        if(this->vec[i] == modified_elem)
            this->vec[i] = modified_elem;
}

template<typename TElem>
int my_vector<TElem>::size() const noexcept{
    return nr_elemente;
}

template<typename TElem>
const TElem& my_vector<TElem>::get_elem(int poz) const noexcept {
    return vec[poz];
}

template<typename TElem>
iterator_vector<TElem> my_vector<TElem>::begin() const{
    return iterator_vector<TElem>(*this);
}

template<typename TElem>
iterator_vector<TElem> my_vector<TElem>::end() const{
    return iterator_vector<TElem>(*this, nr_elemente);
}

#endif