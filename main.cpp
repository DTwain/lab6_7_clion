#include <iostream>
#include "Headers/teste.h"
#include "Headers/repo.h"
#include "Headers/validator.h"
#include "Headers/service_biblioteca.h"
#include "Headers/cos_carti.h"
#include "Headers/ui_biblioteca.h"


int main() {
    /*tests tester;
    tester.run_all_tests();
    std::cout<<"ok boss\n";*/

    repo book_repo;
    repo cos;
    validator_carte validator;
    service_biblioteca srv{book_repo, validator};
    cos_carti cos_srv{book_repo, cos};
    ui_biblioteca service{srv, cos_srv};
    service.run();

    return 0;
}
