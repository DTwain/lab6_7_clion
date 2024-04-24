//
// Created by obrej on 4/10/2024.
//


#ifndef LAB6_7_CLION_SERVICE_BIBLIOTECA_H
#define LAB6_7_CLION_SERVICE_BIBLIOTECA_H

#include <map>
#include <memory>
#include <string>
#include "carte.h"
#include "repo.h"
#include "validator.h"
#include "undo.h"

using std::map;

class service_biblioteca {
private:
    repo& repo_carti;
    validator_carte& validator;
    vector<std::unique_ptr<undo>> undo_actions_list;
public:
    service_biblioteca(repo &repo_carti_obj, validator_carte& validator_obj):
        repo_carti{repo_carti_obj}, validator{validator_obj}{}

    service_biblioteca(const service_biblioteca& other) = delete; // blocam copierea service lui

    const vector<carte>& get_reference_from_vector_srv() const noexcept;

    void add_book_srv(const string& autor, const string& titlu, const string& genre, const int& an);

    void delete_book_srv(const int& id);

    void modify_book_srv(const string& autor, const string& titlu, const string& genre, const int& an, const int& id);

    map<string, DTO_carte> raport();

    void do_undo();

    const vector<carte>& get_all_srv() noexcept;

    const vector<carte> filter_srv(const int an, const string titlu) const;

    const vector<carte> sorter_based_on_option(int option) const;

    const carte& search_for_book(const std::string &autor, const std::string &titlu, const std::string &genre,
                                 const int &an);

};

class books_service_exception : std::exception{
    string msg;
public:
    explicit books_service_exception(string error_msg): msg{error_msg} {}
    friend ostream& operator<<(ostream& out, const books_service_exception& ex);
};

ostream& operator<<(ostream& out, const books_service_exception& ex);

#endif //LAB6_7_CLION_SERVICE_BIBLIOTECA_H
