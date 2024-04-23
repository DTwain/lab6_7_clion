//
// Created by obrej on 4/10/2024.
//

#ifndef LAB6_7_CLION_UI_BIBLIOTECA_H
#define LAB6_7_CLION_UI_BIBLIOTECA_H

#include "service_biblioteca.h"

class ui_biblioteca {
private:
    service_biblioteca& srv;
    void meniu();

    void add_book();
    void delete_book();
    void modify_book();
    void afiseaza(const my_vector<carte>& books);
    void cautare();
    void filtare();
    void sortare();
public:
    ui_biblioteca(service_biblioteca &srv_obj): srv{srv_obj}{}
    ui_biblioteca(const ui_biblioteca& other_ui) = delete;

    void run();
};


#endif //LAB6_7_CLION_UI_BIBLIOTECA_H
