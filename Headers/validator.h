//
// Created by obrej on 4/11/2024.
//

#ifndef LAB6_7_CLION_VALIDATOR_H
#define LAB6_7_CLION_VALIDATOR_H

#include "carte.h"

class book_validation_exception{
private:
    vector<string> msgs;
public:
    book_validation_exception(const vector<string>& errors): msgs{errors}{}
    friend ostream& operator << (ostream &out, const book_validation_exception& ex);
};

ostream& operator << (ostream& out, const book_validation_exception& ex);

class validator_carte{
public:
    validator_carte() = default;
    void validate(const carte& book);
};



#endif //LAB6_7_CLION_VALIDATOR_H
