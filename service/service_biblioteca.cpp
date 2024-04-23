//
// Created by obrej on 4/10/2024.
//

#include "../Headers/service_biblioteca.h"
#include "../Headers/vector_iterator.h"
#include <string>

// return a reference to a my_vector class obj, used for printing
const my_vector<carte>& service_biblioteca::get_reference_from_vector_srv() const noexcept {
    return repo_carti.get_reference_from_vector();
}

/*
 * Adauga carte in repo, daca exista
 */
void service_biblioteca::add_book_srv(const std::string &autor, const std::string &titlu, const std::string &genre,
                                      const int &an) {
    carte book_to_be_added{autor, titlu, genre, an, repo_carti.get_id_for_next_book_to_be_added()};
    validator.validate(book_to_be_added);
    repo_carti.add(book_to_be_added);
}

/*
 * Sterge carte din repo
 */
void service_biblioteca::delete_book_srv(const int &id) {
    repo_carti.delete_book(id);
}

/*
 * Modifica carte din repo, daca exista.
 */
void service_biblioteca::modify_book_srv(const std::string &autor, const std::string &titlu, const std::string &genre,
                                         const int &an, const int &id) {
    carte modified_book{autor, titlu, genre, an, id};
    validator.validate(modified_book);
    repo_carti.modify_book(modified_book);
}

/*
 * Returneaza o referinta catre obiectul de tip my_vector, care stocheaza cartile
 */
const my_vector<carte>& service_biblioteca::get_all_srv() noexcept{
    return repo_carti.get_all();
}

const carte& service_biblioteca:: search_for_book(const std::string &autor, const std::string &titlu, const std::string &genre,
                                                  const int &an){
    iterator_vector<carte> iter{repo_carti.get_reference_from_vector()};
    iter.prim();
    while(iter.valid()){
        const carte& book = iter.element();
        if(book.get_author() == autor ||
           book.get_title() == titlu ||
           book.get_genre() == genre ||
           book.get_publication_year() == an
                )
            return book;
        iter.next();
    }
    throw std::exception{};
}

/*
 * Filtreaza cartile dupa an si titlu
 * Daca gaseste o carte cu un camp egal cu $an sau $titlu o adauga in lista
 */
const my_vector<carte> service_biblioteca::filter_srv(int an, string titlu) const {
    my_vector<carte> filtered_books;
    const my_vector<carte>& all{ repo_carti.get_all() };
    for(const auto& book: all){
        if(book.get_publication_year() == an || book.get_title() == titlu)
            filtered_books.add(book);
    }
    return filtered_books;
}

/*
 * Executa sortarea propriu siza
 * all : referinta catre un my_vector care stocheaza cartile
 * func : functia retureaza true in cazul in care cele doua obiecte trebuie interschimbate
 */
void service_biblioteca::my_sort(const my_vector<carte>& all, bool(*func)(const carte&, const carte&)) const{
    for(int i = 0; i < all.size() - 1; ++i)
        for(int j = i + 1; j < all.size(); ++j)
            if(func(all[i], all[j])) {
                carte book = all[i];
                all[i] = all[j];
                all[j] = book;
            }
}

/*
 * Determina functia care va compara doua carti si va decide daca ele se interschimba
 * option : 1 / 2 / 3
 * Return type: referinta catre obiectul sortat
 */
const my_vector<carte> service_biblioteca::sorter_based_on_option(int option) const{
    const my_vector<carte> all{ repo_carti.get_all() };
    if(option == 1)
        my_sort(all, repo_carti.sort_by_title);
    else if(option == 2)
        my_sort(all, repo_carti.sort_by_author);
    else
        my_sort(all, repo_carti.sort_by_publication_year_and_gen);
    return all;
}


