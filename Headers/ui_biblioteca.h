//
// Created by obrej on 4/10/2024.
//

#ifndef LAB6_7_CLION_UI_BIBLIOTECA_H
#define LAB6_7_CLION_UI_BIBLIOTECA_H

#include <vector>
#include "service_biblioteca.h"
#include "cos_carti.h"
using std::vector;

class ui_biblioteca {
private:
    service_biblioteca& srv;
    cos_carti &service_cos;
    void meniu();

    void add_book();
    void delete_book();
    void modify_book();
    void afiseaza(const vector<carte>& books);
    void cautare();
    void filtare();
    void sortare();

    void add_cos();
    void goleste_cos();
    void genereaza_cos();
    void export_cos();

    void raport();
    void undo();
public:
    ui_biblioteca(service_biblioteca &srv_obj, cos_carti &srv): srv{srv_obj}, service_cos{srv}{}
    ui_biblioteca(const ui_biblioteca& other_ui) = delete;

    void run();
};


#endif //LAB6_7_CLION_UI_BIBLIOTECA_H
