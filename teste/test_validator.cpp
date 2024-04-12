//
// Created by obrej on 4/11/2024.
//

#include <cassert>
#include <sstream>
#include "../Headers/teste.h"
#include "../Headers/validator.h"

void test_validator::tester_validator(){
    validator_carte validator;
    carte book1 = carte("Luis", "Jupanii", "epic", 1842, 0);
    carte book2 = carte("Kong", "", "liric", 1940, 1);
    carte book3 = carte("Luis", "", "", 1842, 2);
    carte book4 = carte("", "Maria", "", 1940, 3);
    carte book5 = carte("Luis", "Jupanii", "epic", 2034, 4);

    validator.validate(book1);

    try{
        validator.validate(book2);
    }
    catch(const book_validation_exception& ex){
        std::stringstream ss;
        ss << ex;
        auto mesaj = ss.str();
        assert(mesaj.find("Titlul") == 0);
        ss.clear();
    }

    try{
        validator.validate(book3);
    }
    catch(const book_validation_exception& ex){
        std::stringstream ss;
        ss << ex;
        auto mesaj = ss.str();
        assert(mesaj.find("Titlul") == 0);
        assert(mesaj.find("Genul") >= 0);
        ss.clear();
    }

    try{
        validator.validate(book4);
    }
    catch(const book_validation_exception& ex){
        std::stringstream ss;
        ss << ex;
        auto mesaj = ss.str();
        assert(mesaj.find("Autorul") == 0);
        assert(mesaj.find("Genul") >= 0);
        ss.clear();
    }

    try{
        validator.validate(book5);
    }
    catch(const book_validation_exception& ex){
        std::stringstream ss;
        ss << ex;
        auto mesaj = ss.str();
        assert(mesaj.find("Anul") == 0);
        ss.clear();
    }

}
