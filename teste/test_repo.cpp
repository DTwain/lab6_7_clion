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
    carte book0 = carte("Luis", "Jupanii", "Epic", 1842, 0);
    carte book1 = carte("Kong", "Maria", "Liric", 1940, 1);
    carte book2 = carte("Kong", "Maria", "Liric", 1940, 2);
    carte book3 = carte("Kong", "Maria", "Liric", 1940, 3);
    carte book4 = carte("Kong", "Maria", "Liric", 1940, 4);
    carte book5 = carte("Kong", "Maria", "Liric", 1940, 5);
    carte book6 = carte("Kong", "Maria", "Liric", 1940, 6);
    carte book7 = carte("Kong", "Maria", "Liric", 1940, 7);
    carte book8 = carte("Kong", "Maria", "Liric", 1940, 8);
    carte book9 = carte("Kong", "Maria", "Liric", 1940, 9);
    carte book10 = carte("Kong", "Maria", "Liric", 1940, 10);
    carte book11 = carte("Kong", "Maria", "Liric", 1940, 11);
    carte book12 = carte("Kong", "Maria", "Liric", 1940, 12);
    carte book13 = carte("Kong", "Maria", "Liric", 1940, 13);
    carte book14 = carte("Kong", "Maria", "Liric", 1940, 14);
    carte book15 = carte("Kong", "Maria", "Liric", 1940, 15);
    carte book16 = carte("Kong", "Maria", "Liric", 1940, 16);
    carte book17 = carte("Kong", "Maria", "Liric", 1940, 17);
    carte book18 = carte("Kong", "Maria", "Liric", 1940, 18);
    carte book19 = carte("Kong", "Maria", "Liric", 1940, 19);
    carte book20 = carte("Kong", "Maria", "Liric", 1940, 20);
    carte book21 = carte("Kong", "Maria", "Liric", 1940, 21);


    book_repo.add(book0);
    book_repo.add(book1);book_repo.add(book2);book_repo.add(book3);
    book_repo.add(book4);book_repo.add(book5);book_repo.add(book6);
    book_repo.add(book7);book_repo.add(book8);book_repo.add(book9);
    book_repo.add(book10);book_repo.add(book11);book_repo.add(book12);
    book_repo.add(book13);book_repo.add(book14);book_repo.add(book15);
    book_repo.add(book16);book_repo.add(book17);book_repo.add(book18);
    book_repo.add(book19);book_repo.add(book20);book_repo.add(book21);

    assert(book_repo.get_reference_from_vector().size() == 22); // echivalent cu get_all()
    assert(book_repo.find_book_by_id(0).get_title() == "Jupanii");

    assert(book_repo.find_book_by_id(20) == book20);

    try{
        book_repo.add(book2);
        assert(false);
    }
    catch(const book_repo_exception&){
        assert(true);
    }

    try{
        book_repo.find_book_by_id(23);
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

    book_repo.delete_book(1);

    assert(book_repo.get_all().size() == 1);

    try{
        book_repo.delete_book(1);
        assert(false);
    }
    catch(const book_repo_exception& ex){
        stringstream ss;
        ss << ex;
        assert(ss.str().find("nu exista!") > 0);
    }

    book_repo.goleste_repo();
    assert(book_repo.get_all().size() == 0);

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
