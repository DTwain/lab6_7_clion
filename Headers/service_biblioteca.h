//
// Created by obrej on 4/10/2024.
//


#ifndef LAB6_7_CLION_SERVICE_BIBLIOTECA_H
#define LAB6_7_CLION_SERVICE_BIBLIOTECA_H

#include <string>
#include <vector>
#include "carte.h"
#include "repo.h"
#include "validator.h"

using std::vector;

class service_biblioteca {
private:
    repo& repo_carti;
    validator_carte& validator;
public:
    service_biblioteca(repo &repo_carti_obj, validator_carte& validator_obj):
        repo_carti{repo_carti_obj}, validator{validator_obj}{}

        service_biblioteca(const service_biblioteca& other) = delete; // blocam copierea service lui

        void add_book_srv(const string& autor, const string& titlu, const string& genre, const int& an);

        void delete_book_srv(const int& id);

        void modify_book_srv(const string& autor, const string& titlu, const string& genre, const int& an, const int& id);

        const vector<carte>& get_all_srv() noexcept;

        //const vector<carte>&filter_srv_an_aparitie(const int& an) const;

        const carte& search_for_book(const std::string &autor, const std::string &titlu, const std::string &genre,
                                     const int &an);

};


#endif //LAB6_7_CLION_SERVICE_BIBLIOTECA_H
