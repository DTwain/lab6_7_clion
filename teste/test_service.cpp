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
    test_filter();
    test_sort();
    test_search_book();
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

    my_vector<carte> vec_carti{ book_repo.get_all() };

    assert(vec_carti.size() == 2);

    assert(vec_carti[0].get_author() == "Luis");
    assert(vec_carti[0].get_title() == "Jupanii");
    assert(vec_carti[0].get_genre() == "Epic");
    assert(vec_carti[0].get_publication_year() == 1842);
    assert(vec_carti[0].get_book_id() == 0);
}

void test_service::test_search_book() {
    repo books_repo;
    validator_carte validator;
    service_biblioteca srv(books_repo, validator);

    srv.add_book_srv("Luis", "Jupanii", "Epic", 1842);
    srv.add_book_srv("Kong", "Maria", "Liric", 1940);
    srv.add_book_srv("I.L.C", "O scrisoare pierduta", "Dramatic", 2000);
    srv.add_book_srv("Mihai Eminescu", "Luceafar", "Liric", 1883);

    carte book_found { srv.search_for_book("Mihai Eminescu", "/" , "p", 12)};

    assert(book_found.get_book_id() == 3);

    try{
        carte book_found { srv.search_for_book("d", "s", "k", 1700) };
        assert(false);
    }
    catch(std::exception){
        assert(true);
    }

    // testez cu get_reference_from_vector_srv
    my_vector<carte> books_vec { srv.get_reference_from_vector_srv() };
    assert(books_vec.size() == 4);
}

void test_service::test_filter() {
    repo books_repo;
    validator_carte validator;
    service_biblioteca srv(books_repo, validator);

    srv.add_book_srv("Luis", "Jupanii", "Epic", 1842);
    srv.add_book_srv("Kong", "Maria", "Liric", 1940);
    srv.add_book_srv("I.L.C", "O scrisoare pierduta", "Dramatic", 2000);
    srv.add_book_srv("Mihai Eminescu", "Luceafar", "Liric", 1883);

    my_vector<carte> vec_carti{ srv.filter_srv(2000, "Maria") };
    assert(vec_carti.size() == 2);

    assert(vec_carti[0].get_book_id() == 1);
    assert(vec_carti[0].get_genre() == "Liric");
    assert(vec_carti[0].get_publication_year() == 1940);
    assert(vec_carti[0].get_author() == "Kong");
    assert(vec_carti[0].get_title() == "Maria");

    assert(vec_carti[1].get_book_id() == 2);
    assert(vec_carti[1].get_genre() == "Dramatic");
    assert(vec_carti[1].get_publication_year() == 2000);
    assert(vec_carti[1].get_author() == "I.L.C");
    assert(vec_carti[1].get_title() == "O scrisoare pierduta");

    my_vector<carte> vec_carti_2{ srv.filter_srv(1941, "Corola de minini a lumii") };
    assert(vec_carti_2.size() == 0);
}

void test_service::test_sort() {
    repo books_repo;
    validator_carte validator;
    service_biblioteca srv(books_repo, validator);

    srv.add_book_srv("Luis", "Jupanii", "Epic", 1842);
    srv.add_book_srv("Kong", "Maria", "Liric", 2000);
    srv.add_book_srv("I.L.C", "O scrisoare pierduta", "Dramatic", 2000);
    srv.add_book_srv("Mihai Eminescu", "Luceafar", "Liric", 1883);

    my_vector<carte> books_vec{ srv.sorter_based_on_option(1) };

    assert(books_vec.size() == 4);
    assert(books_vec[0].get_book_id() == 0);
    assert(books_vec[1].get_book_id() == 3);
    assert(books_vec[2].get_book_id() == 1);
    assert(books_vec[3].get_book_id() == 2);

    my_vector<carte> books_vec_2{ srv.sorter_based_on_option(2) };

    assert(books_vec_2.size() == 4);
    assert(books_vec_2[0].get_book_id() == 2);
    assert(books_vec_2[1].get_book_id() == 1);
    assert(books_vec_2[2].get_book_id() == 0);
    assert(books_vec_2[3].get_book_id() == 3);

    my_vector<carte> books_vec_3{ srv.sorter_based_on_option(3) };

    assert(books_vec_3.size() == 4);
    assert(books_vec_3[0].get_book_id() == 0);
    assert(books_vec_3[1].get_book_id() == 3);
    assert(books_vec_3[2].get_book_id() == 2);
    assert(books_vec_3[3].get_book_id() == 1);

    srv.delete_book_srv(1);
    srv.delete_book_srv(2);
    srv.delete_book_srv(0);
    srv.delete_book_srv(3);

    my_vector<carte> books_vec_4{ srv.sorter_based_on_option(3) };

    assert(books_vec_4.size() == 0);
}
