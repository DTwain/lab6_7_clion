//
// Created by obrej on 4/23/2024.
//
#include "../Headers/teste.h"
#include "../Headers/repo.h"

void test_service_cos::run_service_cos_tests() {
    test_add_cos();
    test_goleste_cos();
    test_genereaza_cos();
    test_export_cos();
}

void test_service_cos::test_add_cos() {
    repo book_repo;
    carte book1 = carte("Luis", "Jupanii", "Epic", 1842, 0);
    carte book2 = carte("Kong", "Maria", "Liric", 1940, 1);
    carte book3 = carte("aa", "bb", "liric", 2020, 3);

    book_repo.add(book1);
    book_repo.add(book2);
    book_repo.add(book3);


}