//
// Created by obrej on 4/10/2024.
//

#include "../Headers/repo.h"
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdlib.h>

using std::string;
using std::ostream;
using std::stringstream;
using std::to_string;
using std::vector;

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

const vector<carte>& repo::get_reference_from_storage() {
    return carte_vec;
}

/*
 * Adauga cartea in repo
 * Arunca book_repo_exception daca mai exista o cartte cu acelasi Id
 */
void repo::add(const carte& obj_carte){
    if(carte_in_repo(obj_carte.get_book_id()))
        throw book_repo_exception("Cartea cu id - ul: " + to_string(obj_carte.get_book_id()) + "exista deja");
    this->carte_vec.push_back(obj_carte);
    this->incrementare_id();
}

void repo::add_pt_cos(const carte& obj_carte){
    this->carte_vec.push_back(obj_carte);
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
    for(const carte& book : this->carte_vec)
        if(book.get_book_id() == id)
            return book;
    throw book_repo_exception("Book with id: " + to_string(id) + " doesn't exist");
}
/*
 * Sterge cartea cu id ul dat sau ridica o exceptie daca nu gaseste cartea
 *
 */
void repo::delete_book(const int &id) {
    if(!carte_in_repo(id))
        throw book_repo_exception("Cartea cu id-ul " + to_string(id) + " nu exista!");
    auto remove_begin = std::remove_if(carte_vec.begin(), carte_vec.end(),
                                       [id](const carte& obj_carte) { return obj_carte.get_book_id() == id; });
    carte_vec.erase(remove_begin, carte_vec.end());
}
/*
 * Sterge toate cartile din repo
 */
void repo::goleste_repo() {
    carte_vec.clear();
}

/*
 * Modifica cartea cu id ul egal cu cel al cartii care
 *
 */
void repo::modify_book(const carte& obj_carte) {
    int book_id = obj_carte.get_book_id();
    bool found = false;

    for(carte& book: this->carte_vec)
        if(book.get_book_id() == obj_carte.get_book_id()){
            book = obj_carte;
            found = true;
            break;
        }

    if(!found) {
        throw book_repo_exception("Doesn't exist book with id: " + to_string(book_id));
    }
}

const vector<carte>& repo::get_all() {
    return carte_vec;
}

ostream& operator<<(ostream& out, const book_repo_exception& ex){
    out << ex.msg;
    return out;
}

// urmeaza cele trei functii de camparare a doua carti

// comparare dupa titlu
bool repo_abs::comp_by_title(const carte &book1, const carte &book2) const noexcept{
    return book1.get_title() < book2.get_title();
}

// comparare dupa autor
bool repo_abs::comp_by_author(const carte &book1, const carte &book2) const noexcept {
    return book1.get_author() < book2.get_author();
}

//comaparare dupa an si gen
bool repo_abs::comp_by_publication_year_and_gen(const carte &book1, const carte &book2) const noexcept{
    if(book1.get_publication_year()< book2.get_publication_year())
        return true;
    else if(book1.get_publication_year() == book2.get_publication_year())
        return book1.get_genre() < book2.get_genre();
    return false;
}

void repo_file::write_to_file() {
    std::ofstream cout(filename);
    if(!cout.is_open())
        throw book_repo_exception("Nu s-a deschis fisierul pentru scriere");

    for(const carte& book : get_all()){
        cout<<book.get_book_id()<<";"<<book.get_author()<<";"<<book.get_title()<<";"<<book.get_genre()<<";"<<book.get_publication_year()<<'\n';
    }

    cout.close();
}

void repo_file::load_from_file() {
    std::ifstream fin(filename, std::ios::in);
    if(fin.fail())
        throw book_repo_exception("Nu s-a deschis fisierul pentru citire");

    fin.seekg(0, std::ios::end);
    if (fin.tellg() == 0) {
        fin.close();
        return;
    }
    fin.seekg(0, std::ios::beg);
    while(!fin.eof()){
        string linie;
        getline(fin,linie);

        if(linie.size() == 0){
            break;
        }
        std::vector<std::string> tokens;
        std::istringstream iss(linie);
        std::string token;

        while (std::getline(iss, token, ';')) {
            tokens.push_back(token);
        }

        if(tokens.size() >= 6)
            throw book_repo_exception("Fisierul in care se stocheaza cartile contile o line cu mai mult de 5 date");
        // Print the tokens
        int id = std::stoi(tokens[0]);
        string autor = tokens[1];
        string titlu = tokens[2];
        string gen = tokens[3];
        int an = std::stoi(tokens[4]);

        carte book{autor, titlu, gen, an, id};
        repo::add(book);
    }
    fin.close();
}

void probability_repo::cat_de_norocos_esti() const{
    int prob_din_doua_cifre = probability * 100;
    int val_random = rand() % 100;
    if(val_random < prob_din_doua_cifre)
        throw book_repo_exception("Ai ghinion azi John");
}

void probability_repo::add(const carte &carte_obj) {
    cat_de_norocos_esti();
    if(lista_carti.find(carte_obj.get_book_id()) != lista_carti.end())
        throw book_repo_exception("Exista cartea deja");
    lista_carti[carte_obj.get_book_id()].push_back(carte_obj);
    write_to_file_probability_repo();
    incrementare_id();
}

void probability_repo::add_without_writing_to_file(const carte &carte_obj) {
    cat_de_norocos_esti();
    if(lista_carti.find(carte_obj.get_book_id()) != lista_carti.end())
        throw book_repo_exception("Exista cartea deja");
    lista_carti[carte_obj.get_book_id()].push_back(carte_obj);
    incrementare_id();
}

void probability_repo::incrementare_id() {
    this->id += 1;
}
void probability_repo::delete_book(const int &id) {
    cat_de_norocos_esti();
    auto iter = lista_carti.find(id);
    if(iter != lista_carti.end()) {
        lista_carti.erase(iter);
        write_to_file_probability_repo();
    }
    else
        throw book_repo_exception("Nu exista cartea cu id-ul dat");
}

void probability_repo::modify_book(const carte &modified_book) {
    cat_de_norocos_esti();
    auto iter = lista_carti.find(modified_book.get_book_id());
    if(iter != lista_carti.end()) {
        lista_carti[modified_book.get_book_id()].clear();
        lista_carti[modified_book.get_book_id()].push_back(modified_book);
        write_to_file_probability_repo();
    }
    else
        throw book_repo_exception("Nu exista cartea pentru modificare");
}

const vector<carte>& probability_repo::get_all() {
    cat_de_norocos_esti();
    lista.clear();
    for(const auto& itr: lista_carti)
        lista.push_back(itr.second.back());

    return lista;
}

const int& probability_repo::get_id_for_next_book_to_be_added() const {
    return this->id;
}

const vector<carte>& probability_repo::get_reference_from_storage() {
    cat_de_norocos_esti();
    lista.clear();
    for(const auto& itr: lista_carti)
        lista.push_back(itr.second.back());

    return lista;
}

const carte& probability_repo::find_book_by_id(const int& id) const {
    cat_de_norocos_esti();
    const auto& itr = lista_carti.find(id);
    if(itr != lista_carti.end()){
        return itr->second.back();
    }
    else
        throw book_repo_exception("Book with id: " + to_string(id) + " doesn't exist");
}

void probability_repo::add_pt_cos(const carte& obj_carte) {
    cat_de_norocos_esti();
    lista_carti[obj_carte.get_book_id()].push_back(obj_carte);
}

void probability_repo::goleste_repo() {
    cat_de_norocos_esti();
    lista.clear();
    lista_carti.clear();
}

void probability_repo::write_to_file_probability_repo() {
    std::ofstream cout(filename);
    if(!cout.is_open())
        throw book_repo_exception("Nu s-a deschis fisierul pentru scriere");

    for(const auto& itr: lista_carti){
        const carte& book = itr.second.back();
        cout<<book.get_book_id()<<";"<<book.get_author()<<";"<<book.get_title()<<";"<<book.get_genre()<<";"<<book.get_publication_year()<<'\n';
    }

    cout.close();

}
void probability_repo::load_from_file_probability_repo() {
    std::ifstream fin(filename, std::ios::in);
    if(fin.fail())
        throw book_repo_exception("Nu s-a deschis fisierul pentru citire");

    fin.seekg(0, std::ios::end);
    if (fin.tellg() == 0) {
        fin.close();
        return;
    }
    fin.seekg(0, std::ios::beg);
    while(!fin.eof()){
        string linie;
        getline(fin,linie);

        if(linie.size() == 0){
            break;
        }
        std::vector<std::string> tokens;
        std::istringstream iss(linie);
        std::string token;

        while (std::getline(iss, token, ';')) {
            tokens.push_back(token);
        }

        if(tokens.size() >= 6)
            throw book_repo_exception("Fisierul in care se stocheaza cartile contile o line cu mai mult de 5 date");
        // Print the tokens
        int id = std::stoi(tokens[0]);
        string autor = tokens[1];
        string titlu = tokens[2];
        string gen = tokens[3];
        int an = std::stoi(tokens[4]);

        carte book{autor, titlu, gen, an, id};
        while(1) {
            try {
                add_without_writing_to_file(book);
                break;
            }
            catch (book_repo_exception) {

            }
        }
    }
    fin.close();
}







