//
// Created by obrej on 4/23/2024.
//
#include "../Headers/teste.h"
#include "../Headers/repo.h"
#include "../Headers/cos_carti.h"
#include <cassert>

void test_service_cos::run_service_cos_tests() {
    test_add_cos();
    test_goleste_cos();
    test_genereaza_cos();
    test_export_cos();
}

void test_service_cos::test_add_cos() {
    repo book_repo;
    repo cos;
    cos_carti srv_cos{book_repo, cos};

    carte book1 = carte("Luis", "Jupanii", "Epic", 1842, 0);
    carte book2 = carte("Kong", "Maria", "Liric", 1940, 1);
    carte book3 = carte("aa", "bb", "liric", 2020, 2);
    carte book4 = carte("lala", "trala", "epic", 1234, 3);

    book_repo.add(book1);
    book_repo.add(book2);
    book_repo.add(book3);

    srv_cos.add_carte_in_cos("bb");
    srv_cos.add_carte_in_cos("Jupanii");

    assert(cos.get_all().size() == 2);
    assert(srv_cos.get_nr_carti_din_cos() == 2);

    try{
        srv_cos.add_carte_in_cos("tralala");
        assert(false);
    }
    catch(std::exception){
        assert(true);
    }

}

void test_service_cos::test_goleste_cos() {
    repo book_repo;
    repo cos;
    cos_carti srv_cos{book_repo, cos};

    carte book1 = carte("Luis", "Jupanii", "Epic", 1842, 0);
    carte book2 = carte("Kong", "Maria", "Liric", 1940, 1);
    carte book3 = carte("aa", "bb", "liric", 2020, 2);
    carte book4 = carte("lala", "trala", "epic", 1234, 3);

    book_repo.add(book1);
    book_repo.add(book2);
    book_repo.add(book3);

    srv_cos.add_carte_in_cos("bb");
    srv_cos.add_carte_in_cos("Jupanii");

    srv_cos.goleste_cos();

    assert(cos.get_all().size() == 0);
}

void test_service_cos::test_genereaza_cos() {
    repo book_repo;
    repo cos;
    cos_carti srv_cos{book_repo, cos};

    carte book1 = carte("Luis", "Jupanii", "Epic", 1842, 0);
    carte book2 = carte("Kong", "Maria", "Liric", 1940, 1);
    carte book3 = carte("aa", "bb", "liric", 2020, 2);
    carte book4 = carte("lala", "trala", "epic", 1234, 3);

    book_repo.add(book1);
    book_repo.add(book2);
    book_repo.add(book3);

    srv_cos.add_carte_in_cos("bb");
    srv_cos.add_carte_in_cos("Jupanii");

    srv_cos.genereaza_cos(3);

    assert(cos.get_all().size() == 5);
}

void test_service_cos::test_export_cos() {
    repo book_repo;
    repo cos;
    cos_carti srv_cos{book_repo, cos};

    carte book1 = carte("Luis", "Jupanii", "Epic", 1842, 0);
    carte book2 = carte("Kong", "Maria", "Liric", 1940, 1);
    carte book3 = carte("aa", "bb", "liric", 2020, 2);
    carte book4 = carte("lala", "trala", "epic", 1234, 3);

    book_repo.add(book1);
    book_repo.add(book2);
    book_repo.add(book3);

    srv_cos.add_carte_in_cos("bb");
    srv_cos.add_carte_in_cos("Jupanii");

    srv_cos.genereaza_cos(3);

    srv_cos.export_cos("ceva.html", 0);

    FILE *file;
    file = fopen("ceva.html", "r");
    if (file == NULL)
        assert(false);
    else {
        remove("ceva.html");
    }
}