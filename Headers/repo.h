//
// Created by obrej on 4/10/2024.
//



#ifndef LAB6_7_CLION_REPO_H
#define LAB6_7_CLION_REPO_H

#include "carte.h"
#include <ostream>
#include <vector>
#include <string>

using std::ostream;
using std::string;
using std::vector;

class repo {
private:
    vector<carte> carte_vec;
    int id = 0;
    bool carte_in_repo(const int& id ) const;
    void incrementare_id();
public:
    repo() = default;

    repo(const repo& other) = delete; // pt a bloca copierea

    virtual ~repo() = default;

    const int& get_id_for_next_book_to_be_added() const;

    const vector<carte>& get_reference_from_vector() const;

    virtual void add(const carte& carte_obj);

    void add_pt_cos(const carte& obj_carte);

    virtual void delete_book(const int& id);

    virtual void modify_book(const carte& obj_carte);

    void goleste_repo();

    const carte& find_book_by_id(const int& id) const;

    const vector<carte>& get_all() const noexcept;


    static bool sort_by_title(const carte& book1, const carte& book2);
    static bool sort_by_author(const carte& book1, const carte& book2);
    static bool sort_by_publication_year_and_gen(const carte& book1, const carte& book2);

};

class repo_file : public repo {
private:
    string filename;
    void write_to_file();
    void load_from_file();
public:
    repo_file(const string &filename): repo(), filename{ filename } {
        load_from_file();
    }
    void add(const carte& carte_obj) override{
        repo::add(carte_obj);
        write_to_file();
    }
    void delete_book(const int& id) override{
        repo::delete_book(id);
        write_to_file();
    }
    void modify_book(const carte& obj_carte) override{
        repo::add(obj_carte);
        write_to_file();
    }
};


class book_repo_exception : std::exception{
    string msg;
public:
    explicit book_repo_exception(string error_msg): msg{error_msg} {}
    friend ostream& operator<<(ostream& out, const book_repo_exception& ex);
};

ostream& operator<<(ostream& out, const book_repo_exception& ex);

#endif //LAB6_7_CLION_REPO_H
