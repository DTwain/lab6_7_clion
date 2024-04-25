//
// Created by obrej on 4/10/2024.
//

#ifndef LAB6_7_CLION_TEST_REPO_H
#define LAB6_7_CLION_TEST_REPO_H


class test_repo {
private:
    void test_repo_add();
    void test_repo_delete();
    void test_repo_modify();
    void test_repo_get_all();
    void test_repo_find_book_by_id();
    void test_get_id_for_next_book_to_be_added();
    void test_increment_id();

    void test_repo_file_write();
    void test_repo_file_load();

    void test_repo_probability_add();
    void test_repo_probability_delete();
    void test_repo_probability_modify();
    void test_repo_probability_get_all();
public:
    void run_repo_tests();
};

class test_domain{
private:
    void test_get_author();
    void test_get_title();
    void test_get_genre();
    void test_get_publication_year();
    void test_get_book_id();
    void test_equal();
public:
    void run_domain_tests();
};

class test_validator{
public:
    void tester_validator();
};

class test_service{
private:
    void test_add();
    void test_delete();
    void test_modify();
    void test_get_all();
    void test_filter();
    void test_sort();
    void test_search_book();
    void test_raport();
    void test_undo();
public:
    void run_service_tests();
};

class test_service_cos{
private:
    void test_add_cos();
    void test_goleste_cos();
    void test_genereaza_cos();
    void test_export_cos();

public:
    void run_service_cos_tests();
};

class tests{
private:
    test_domain tester_domain;
    test_repo tester_repo;
    test_validator t_validator;
    test_service tester_service;
    test_service_cos tester_cos;
public:
    void run_all_tests(){
        tester_domain.run_domain_tests();
        tester_repo.run_repo_tests();
        t_validator.tester_validator();
        tester_service.run_service_tests();
        tester_cos.run_service_cos_tests();
    }
};
#endif //LAB6_7_CLION_TEST_REPO_H
