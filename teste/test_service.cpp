//
// Created by obrej on 4/12/2024.
//

#include <cassert>
#include <sstream>
#include "../Headers/teste.h"
#include "../Headers/service_biblioteca.h"
#include "../Headers/validator.h"

using std::stringstream;
void test_service::run_service_tests() {
    test_add();
    test_delete();
    test_modify();
    test_get_all();
    //test_filter_an();
}

void test_service::test_add() {
    repo book_repo;
    validator_carte validator;
    service_biblioteca srv{book_repo, validator};

    srv.add_book_srv("Luis", "Jupanii", "Epic", 1842);
    srv.add_book_srv("Kong", "Maria", "Liric", 1940);

    try{
        srv.add_book_srv("", "Fabulos", "Liric", 1900);
        assert(false);
    }
    catch(const book_validation_exception&){
        assert(true);
    }

}

void test_service::test_delete() {
    repo book_repo;
    validator_carte validator;
    service_biblioteca srv{book_repo, validator};

    srv.add_book_srv("Luis", "Jupanii", "Epic", 1842);
    srv.add_book_srv("Kong", "Maria", "Liric", 1940);

    srv.delete_book_srv(0);
    assert(srv.get_all_srv().size() == 1);

    try{
        srv.delete_book_srv(0);
        assert(false);
    }
    catch(const book_repo_exception&){
        assert(true);
    }

    try{
        srv.delete_book_srv(2);
        assert(false);
    }
    catch(const book_repo_exception& ex){
        stringstream ss;
        ss << ex;
        assert(ss.str().find("Cartea cu id-ul") == 0);
        ss.clear();
    }

}

void test_service::test_modify() {
    repo book_repo;
    validator_carte validator;
    service_biblioteca srv{book_repo, validator};

    srv.add_book_srv("Luis", "Jupanii", "Epic", 1842);
    srv.add_book_srv("Kong", "Maria", "Liric", 1940);

    try{
        srv.modify_book_srv("", "Fabulos", "Liric", 1900, 0);
        assert(false);
    }
    catch(const book_validation_exception&){
        assert(true);
    }

    try{
        srv.modify_book_srv("Justin", "Fabulos", "Liric", 1900, 2);
        assert(false);
    }
    catch(const book_repo_exception& ex){
        stringstream ss;
        ss << ex;
        assert(ss.str().find("Doesn't exist book with id:") == 0);
        ss.clear();
    }
}

void test_service::test_get_all() {
    repo book_repo;
    validator_carte validator;
    service_biblioteca srv{book_repo, validator};

    srv.add_book_srv("Luis", "Jupanii", "Epic", 1842);
    srv.add_book_srv("Kong", "Maria", "Liric", 1940);

    vector<carte> vec_carti = book_repo.get_all();

    assert(vec_carti.size() == 2);

    assert(vec_carti[0].get_author() == "Luis");
    assert(vec_carti[0].get_title() == "Jupanii");
    assert(vec_carti[0].get_genre() == "Epic");
    assert(vec_carti[0].get_publication_year() == 1842);
    assert(vec_carti[0].get_book_id() == 0);
}

/*
void test_service::test_filter_an(){
    repo book_repo;
    validator_carte validator;
    service_biblioteca srv{book_repo, validator};

    srv.add_book_srv("Luis", "Jupanii", "Epic", 1842);
    srv.add_book_srv("Kong", "Maria", "Liric", 1940);

    vector<carte> crt = srv.filter_srv_an_aparitie(1900);
    assert(crt.size() == 1);
}*/
