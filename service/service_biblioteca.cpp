//
// Created by obrej on 4/10/2024.
//

#include "../Headers/service_biblioteca.h"
#include <string>

void service_biblioteca::add_book_srv(const std::string &autor, const std::string &titlu, const std::string &genre,
                                      const int &an) {
    carte book_to_be_added{autor, titlu, genre, an, repo_carti.get_id_for_next_book_to_be_added()};
    validator.validate(book_to_be_added);
    repo_carti.add(book_to_be_added);
}

void service_biblioteca::delete_book_srv(const int &id) {
    repo_carti.delete_book(id);
}

void service_biblioteca::modify_book_srv(const std::string &autor, const std::string &titlu, const std::string &genre,
                                         const int &an, const int &id) {
    carte modified_book{autor, titlu, genre, an, id};
    validator.validate(modified_book);
    repo_carti.modify_book(modified_book);
}

const vector<carte>& service_biblioteca::get_all_srv() noexcept{
    return repo_carti.get_all();
}
//this maekes a new list with books that have bulication_year lower than 'an'
/*
const vector<carte>& service_biblioteca::filter_srv_an_aparitie(const int &an) const {
    vector<carte> filtered_books;
    const vector<carte>& all = repo_carti.get_all();
    for(const auto& book: all){
        if(book.get_publication_year() < an)
            filtered_books.push_back(book);
    }
    return filtered_books;
}*/

const carte& service_biblioteca:: search_for_book(const std::string &autor, const std::string &titlu, const std::string &genre,
                             const int &an){
    const vector<carte>& all = repo_carti.get_all();
    for(const auto& carte: all){
        if(carte.get_author() == autor ||
            carte.get_title() == titlu ||
            carte.get_genre() == genre ||
            carte.get_publication_year() == an
                )
            return carte;
    }
    throw std::exception{};
}
