//
// Created by obrej on 4/10/2024.
//



#ifndef LAB6_7_CLION_REPO_H
#define LAB6_7_CLION_REPO_H

#include "../Headers/carte.h"
#include <ostream>
#include <vector>
#include <string>

using std::ostream;
using std::string;
using std::vector;

class repo {
private:
    vector< carte > carte_vec;
    int id = 0;
    bool carte_in_repo(const int& id ) const;
    void incrementare_id();
public:
    repo() = default;
    repo(const carte&) = delete; // pt a bloca copierea

    const int& get_id_for_next_book_to_be_added() const;

    void add(const carte& carte_obj);

    void delete_book(const int& id);

    void modify_book(const carte& obj_carte);

    const carte& find_book_by_id(const int& id) const;

    const vector<carte>& get_all() const noexcept;
};

class book_repo_exception : std::exception{
    string msg;
public:
    explicit book_repo_exception(string error_msg): msg{error_msg} {}
    friend ostream& operator<<(ostream& out, const book_repo_exception& ex);
};

ostream& operator<<(ostream& out, const book_repo_exception& ex);

#endif //LAB6_7_CLION_REPO_H
