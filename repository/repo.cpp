//
// Created by obrej on 4/10/2024.
//

#include "../Headers/repo.h"
#include "../Headers/vector_iterator.h"
#include <sstream>
#include <cstring>

using std::string;
using std::ostream;
using std::stringstream;
using std::to_string;

void repo::incrementare_id(){
    this->id += 1;
}
/*
 * Returneaza un id pentru cartea pe care dorim sa o adaugam
 * Return type: int
 */
const int& repo::get_id_for_next_book_to_be_added() const {
    return this->id;
}

const my_vector<carte>& repo::get_reference_from_vector() const {
    return carte_vec;
}

/*
 * Adauga cartea in repo
 * Arunca book_repo_exception daca mai exista o cartte cu acelasi Id
 */
void repo::add(const carte& obj_carte){
    if(carte_in_repo(obj_carte.get_book_id()))
        throw book_repo_exception("Cartea cu id - ul: " + to_string(obj_carte.get_book_id()) + "exista deja");
    this->carte_vec.add(obj_carte);
    this->incrementare_id();
}

/*
 * Verifica daca cartea cu id ul dat apare in repo
 * Return type:
 *      true: carta apare in repo
 *      false: nu apare in repo
 */
bool repo::carte_in_repo(const int& id_to_find ) const {
    try {
        find_book_by_id(id_to_find);
        return true;
    }
    catch(book_repo_exception&){
        return false;
    }
}
/*
 *  Returneaza cartea cu id ul dat sau ridica o exceptie daca nu exista
 *
 */
const carte& repo::find_book_by_id(const int& id) const{
    iterator_vector<carte> iter{carte_vec};
    iter.prim();
    while(iter.valid()){
        const carte& book{ iter.element() };
        if(book.get_book_id() == id)
            return book;
        iter.next();
    }
    throw book_repo_exception("Book with id: " + to_string(id) + " doesn't exist");
}
/*
 * Sterge cartea cu id ul dat sau ridica o exceptie daca nu gaseste cartea
 *
 */
void repo::delete_book(const int &id) {
    if(!carte_in_repo(id))
        throw book_repo_exception("Cartea cu id-ul " + to_string(id) + " nu exista!");

    int poz = 0;

    iterator_vector<carte> iter{carte_vec};
    iter.prim();
    while(iter.valid()){
        const carte& book{ iter.element() };
        if(book.get_book_id() == id){
            break;
        }
        iter.next();
        poz += 1;
    }
    carte_vec.erase(poz);
}
/*
 * Modifica cartea cu id ul egal cu cel al cartii care
 *
 */
void repo::modify_book(const carte& obj_carte) {
    int book_id = obj_carte.get_book_id();
    bool found = false;

    iterator_vector<carte> iter{carte_vec};
    iter.prim();
    while(iter.valid()){
        carte& book{ iter.element() };
        if(book.get_book_id() == book_id) {
            book = obj_carte; // Update the found book with obj_carte
            found = true;
            break; // Break out of the loop since we found the book
        }
        iter.next();
    }

    if(!found) {
        throw book_repo_exception("Doesn't exist book with id: " + to_string(book_id));
    }
}

const my_vector<carte>& repo::get_all() const noexcept{
    return carte_vec;
}

ostream& operator<<(ostream& out, const book_repo_exception& ex){
    out << ex.msg;
    return out;
}

// urmeaza cele trei functii de camparare a doua carti

// comparare dupa titlu
bool repo::sort_by_title(const carte &book1, const carte &book2) {
    return book1.get_title() > book2.get_title();
}

// comparare dupa autor
bool repo::sort_by_author(const carte &book1, const carte &book2) {
    return book1.get_author() > book2.get_author();
}

//comaparare dupa an si gen
bool repo::sort_by_publication_year_and_gen(const carte &book1, const carte &book2) {
    if(book1.get_publication_year() > book2.get_publication_year())
        return true;
    else if(book1.get_publication_year() == book2.get_publication_year())
        return book1.get_genre() > book2.get_genre();
    return false;
}