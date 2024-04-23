//
// Created by obrej on 4/20/2024.
//

#ifndef LAB6_7_CLION_VECTOR_ITERATOR_H
#define LAB6_7_CLION_VECTOR_ITERATOR_H


template<typename TElem>
class iterator_vector{
private:
    const my_vector<TElem>& vec_obj;
    int pozitie;
public:
    iterator_vector(const my_vector<TElem>& obj): vec_obj{ obj }, pozitie{ 0 }{}

    iterator_vector(const my_vector<TElem>& vec, int poz): vec_obj{ vec }, pozitie{ poz }{}

    bool valid() const;

    void next() noexcept;

    TElem& element() noexcept;

    void prim() noexcept;

    TElem& operator*();
    iterator_vector& operator++();
    bool operator==(const iterator_vector& iter) noexcept;
    bool operator!=(const iterator_vector& iter) noexcept;
};

template<typename TElem>
bool iterator_vector<TElem>::valid() const{
    return pozitie < vec_obj.size();
}

template<typename TElem>
void iterator_vector<TElem>::next() noexcept {
    this->pozitie += 1;
}

template<typename TElem>
TElem& iterator_vector<TElem>::element() noexcept {
    return this->vec_obj[pozitie];
}

template<typename TElem>
void iterator_vector<TElem>::prim() noexcept {
    this->pozitie = 0;
}

template<typename TElem>
TElem& iterator_vector<TElem>::operator*() {
    return vec_obj[pozitie];
}

template<typename TElem>
iterator_vector<TElem>& iterator_vector<TElem>::operator++() {
    next();
    return *this;
}

template<typename TElem>
bool iterator_vector<TElem>::operator==(const iterator_vector<TElem> &iter) noexcept{
     return pozitie == iter.pozitie;
}

template<typename TElem>
bool iterator_vector<TElem>::operator!=(const iterator_vector<TElem> &iter) noexcept {
    return !(*this == iter); //trebuie lasat asa pentru ca se "apeleaza" operatorul == definit mai sus
}

#endif //LAB6_7_CLION_VECTOR_ITERATOR_H
