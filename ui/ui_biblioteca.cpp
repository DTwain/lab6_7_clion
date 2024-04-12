//
// Created by obrej on 4/10/2024.
//

#include "../Headers/ui_biblioteca.h"
#include <iostream>
#include <string>
#include "../Headers/carte.h"

using std::string;
using std::cin;
using std::cout;

void ui_biblioteca::afiseaza(const std::vector<carte> &books) {
    cout << "\nCartile sunt:\n";
    for(const auto& carte: books){
        cout << "Author: " << carte.get_author() << '\n';
        cout << "Title: " << carte.get_title() << '\n';
        cout << "Genre: " << carte.get_genre() << '\n';
        cout << "Publication Year: " << carte.get_publication_year() << '\n';
        cout << "Book ID: " << carte.get_book_id() << '\n';

        cout << '\n';
    }
}

void ui_biblioteca::meniu(){
    cout<< "< 1 > Adaugare carte\n< 2 > Sterge carte\n< 3 > Modifica carte\n< 4 > Afiseaza cartile\n< 5 > Cautare\n< 6 > EXIT\nOption: ";
}
void ui_biblioteca::add_book() {
    string autor, titlu, gen;
    int an_pub;
    cout<<"autor: "; cin>>autor;

    cout<<"titlu: "; cin>>titlu;

    cout<<"gen: "; cin>>gen;

    cout<<"an: "; cin >> an_pub;

    srv.add_book_srv(autor, titlu, gen, an_pub);
}

void ui_biblioteca::delete_book() {
    int id_carte_to_be_deleted;
    afiseaza(srv.get_all_srv());
    cout<<"\nId carte pentru a fi stearsa: "; cin>> id_carte_to_be_deleted;

    srv.delete_book_srv(id_carte_to_be_deleted);
}

void ui_biblioteca::modify_book() {
    int id_carte_to_be_modified;
    afiseaza(srv.get_all_srv());
    cout<<"Id carte pentru a fi stearsa: "; cin>> id_carte_to_be_modified;
    string autor, titlu, gen;
    int an_pub;
    cout<<"autor: "; cin>>autor;

    cout<<"titlu: "; cin>>titlu;

    cout<<"gen: "; cin>>gen;

    cout<<"an: "; cin >> an_pub;

    srv.modify_book_srv(autor, titlu, gen, an_pub, id_carte_to_be_modified);
}
void ui_biblioteca::cautare(){
    cout << "Pentru autor / titlu / gen : string pt cautarea campului altfel <ENTER>\n Pentru an_pub : c > 0 pt pass";
    string autor, titlu, gen;
    int an_pub;
    cout<<"\nautor: "; cin>>autor;

    cout<<"titlu: "; cin>>titlu;

    cout<<"gen: "; cin>>gen;

    cout<<"an: "; cin >> an_pub;

    carte carte = srv.search_for_book(autor, titlu, gen, an_pub);

    cout << "Author: " << carte.get_author() << '\n';
    cout << "Title: " << carte.get_title() << '\n';
    cout << "Genre: " << carte.get_genre() << '\n';
    cout << "Publication Year: " << carte.get_publication_year() << '\n';
    cout << "Book ID: " << carte.get_book_id() << '\n';
}
void ui_biblioteca::run(){
    srv.add_book_srv("Luis", "Jupanii", "Epic", 1842);
    srv.add_book_srv("Kong", "Maria", "Liric", 1940);
    srv.add_book_srv("I.L.C", "O scrisoare pierduta", "Dramatic", 2000);
    while(true){
        meniu();
        int option;
        cin>>option;
        try{
            switch(option) {
                case 1:
                    add_book();
                    break;
                case 2:
                    delete_book();
                    break;
                case 3:
                    modify_book();
                    break;
                case 4:
                    afiseaza(srv.get_all_srv());
                    break;
                case 5:
                    cautare();
                case 6:
                    return;
                default:
                    cout << "Optiunea nu exista!\n";
            }
        }
        catch (const book_validation_exception& ex){
            cout << ex << '\n';
        }
        catch (const book_repo_exception& ex){
            cout << ex << '\n';
        }
        catch (const std::exception){}
    }
}

