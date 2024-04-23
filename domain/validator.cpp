//
// Created by obrej on 4/11/2024.
//

#include "../Headers/validator.h"
#include <vector>
#include <string>

using std::string;
using std::vector;
using std::tolower;

/* verifica ca genul sa fie "liric" / "epic" / "dramatic"
 * return true , daca genul curespunde
 * return false, altfel
*/
bool is_good_gen(string& gen){
    for(auto& c: gen){
        c = tolower(c);
    }
    if(gen == "epic" || gen == "liric" || gen == "dramatic")
        return true;
    return false;
}
/*
 * Valideaza cartea, arunca un custom_exception daca e cazul
 * autor : string nevid
 * titlu : string nevid
 * gen : string egal cu "liric" / "epic" / "dramatic"
 * anul publicatiei: Mai mic decat 2025
 */
void validator_carte::validate(const carte &book) {
    vector<string> errors;
    if(book.get_author().length() == 0)
        errors.push_back("Autorul introdus este vid");
    if(book.get_title().length() == 0)
        errors.push_back("Titlul introdus este vid");
    if(book.get_publication_year() > 2025)
        errors.push_back("Anul introdus nu poate fi din viitor");

    string gen = book.get_genre();
    if(!is_good_gen(gen))
        errors.push_back("Genul introdus nu este epic / liric / dramatic");


    if(errors.size() > 0){
        throw book_validation_exception(errors);
    }
}

ostream& operator << (ostream& out, const book_validation_exception& ex){
    for(const auto& mesaj : ex.msgs){
        out << mesaj << " ";
    }
    return out;
}
