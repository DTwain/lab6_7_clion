//
// Created by obrej on 4/10/2024.
//
#include <cassert>
#include <sstream>
#include "../Headers/teste.h"
#include "../Headers/repo.h"

using std::stringstream;
void test_repo::run_repo_tests() {
    test_repo_add();
    test_repo_delete();
    test_repo_modify();
    test_repo_get_all();
    test_repo_find_book_by_id();
    test_increment_id();
    test_get_id_for_next_book_to_be_added();

}

void test_repo::test_repo_add() {
    repo book_repo;
    carte book1 = carte("Luis", "Jupanii", "Epic", 1842, 0);
    carte book2 = carte("Kong", "Maria", "Liric", 1940, 1);

    book_repo.add(book1);
    book_repo.add(book2);

    assert(book_repo.get_all().size() == 2);
    assert(book_repo.find_book_by_id(0).get_title() == "Jupanii");

    try{
        book_repo.add(book2);
        assert(false);
    }
    catch(const book_repo_exception&){
        assert(true);
    }

    try{
        book_repo.find_book_by_id(2);
        assert(false);
    }
    catch(const book_repo_exception& ex){
        stringstream ss;
        ss << ex;
        assert(ss.str().find("Doesn't exist book with id:") > 0);
    }

}

void test_repo::test_repo_delete() {
    repo book_repo;
    carte book1 = carte("Luis", "Jupanii", "Epic", 1842, 0);
    carte book2 = carte("Kong", "Maria", "Liric", 1940, 1);

    book_repo.add(book1);
    book_repo.add(book2);

    book_repo.delete_book(0);

    assert(book_repo.get_all().size() == 1);

    try{
        book_repo.delete_book(0);
        assert(false);
    }
    catch(const book_repo_exception& ex){
        stringstream ss;
        ss << ex;
        assert(ss.str().find("nu exista!") > 0);
    }

}

void test_repo::test_repo_modify() {
    repo book_repo;
    carte book1 = carte("Luis", "Jupanii", "Epic", 1842, 0);
    carte book2 = carte("Kong", "Maria", "Liric", 1940, 1);
    carte new_book = carte("Ottmar", "Comandant la auschwitz", "Epic", 1960, 1);
    carte bad_new_book = carte("Julia", "Luiza", "Dramatic", 1940, 2);
    book_repo.add(book1);
    book_repo.add(book2);

    book_repo.modify_book(new_book);

    assert(book_repo.find_book_by_id(1).get_author() == "Ottmar");
    assert(book_repo.find_book_by_id(1).get_title() == "Comandant la auschwitz");
    assert(book_repo.find_book_by_id(1).get_genre() == "Epic");
    assert(book_repo.find_book_by_id(1).get_publication_year() == 1960);

    try{
        book_repo.modify_book(bad_new_book);
        assert(false);
    }
    catch(const book_repo_exception& ex){
        stringstream ss;
        ss << ex;
        assert(ss.str().find("Doesn't exist book with id:") == 0);
    }
}

void test_repo::test_repo_get_all() {
    repo book_repo;
    carte book1 = carte("Luis", "Jupanii", "Epic", 1842, 0);
    carte book2 = carte("Kong", "Maria", "Liric", 1940, 1);
    book_repo.add(book1);
    book_repo.add(book2);

    vector<carte> vec_carti = book_repo.get_all();

    assert(vec_carti.size() == 2);

    assert(vec_carti[0].get_author() == "Luis");
    assert(vec_carti[0].get_title() == "Jupanii");
    assert(vec_carti[0].get_genre() == "Epic");
    assert(vec_carti[0].get_publication_year() == 1842);
    assert(vec_carti[0].get_book_id() == 0);

}

void test_repo::test_repo_find_book_by_id() {
    repo book_repo;
    carte book1 = carte("Luis", "Jupanii", "Epic", 1842, 0);
    carte book2 = carte("Kong", "Maria", "Liric", 1940, 1);
    book_repo.add(book1);
    book_repo.add(book2);

    carte book_found = book_repo.find_book_by_id(1);

    assert(book_found.get_author() == "Kong");
    assert(book_found.get_title() == "Maria");
    assert(book_found.get_genre() == "Liric");
    assert(book_found.get_publication_year() == 1940);
    assert(book_found.get_book_id() == 1);
}

void test_repo::test_increment_id() {
    repo book_repo;
    carte book1 = carte("Luis", "Jupanii", "Epic", 1842, 0);
    carte book2 = carte("Kong", "Maria", "Liric", 1940, 1);
    book_repo.add(book1);

    assert(book_repo.get_id_for_next_book_to_be_added() == 1);

    book_repo.add(book2);

    assert(book_repo.get_id_for_next_book_to_be_added() == 2);

}

void test_repo::test_get_id_for_next_book_to_be_added(){
    test_increment_id();
}
