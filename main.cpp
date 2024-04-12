#include <iostream>
#include "Headers/teste.h"
#include "Headers/repo.h"
#include "Headers/validator.h"
#include "Headers/service_biblioteca.h"
#include "Headers/ui_biblioteca.h"
#include <algorithm>
int main() {
    //tests tester;
    //tester.run_all_tests();
    std::cout<<"ok boss\n";

    repo book_repo;
    validator_carte validator;
    service_biblioteca srv{book_repo, validator};
    ui_biblioteca service{srv};
    service.run();
    return 0;
}
