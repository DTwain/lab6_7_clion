//
// Created by obrej on 4/11/2024.
//
#include <cassert>
#include "../Headers/teste.h"
#include "../Headers/carte.h"

void test_domain::run_domain_tests() {
    test_get_author();
    test_get_title();
    test_get_genre();
    test_get_publication_year();
    test_get_book_id();
}
void test_domain::test_get_author() {
    carte book1 = carte("Luis", "Jupanii", "Epic", 1842, 0);
    assert(book1.get_author() == "Luis");
}

void test_domain::test_get_title() {
    carte book1 = carte("Luis", "Jupanii", "Epic", 1842, 0);
    assert(book1.get_title() == "Jupanii");
}

void test_domain::test_get_book_id() {
    carte book1 = carte("Luis", "Jupanii", "Epic", 1842, 0);
    assert(book1.get_book_id() == 0);
}

void test_domain::test_get_genre() {
    carte book1 = carte("Luis", "Jupanii", "Epic", 1842, 0);
    assert(book1.get_genre() == "Epic");
}

void test_domain::test_get_publication_year() {
    carte book1 = carte("Luis", "Jupanii", "Epic", 1842, 0);
    assert(book1.get_publication_year() == 1842);
}