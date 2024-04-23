//
// Created by obrej on 4/10/2024.
//

#include "../Headers/ui_biblioteca.h"
#include "../Headers/carte.h"
#include "../Headers/my_vector.h"
#include "../Headers/vector_iterator.h"
#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;

void ui_biblioteca::afiseaza(const my_vector<carte>& books) {
    if(books.size() == 0){
        cout << "Nu sunt carti de afisat\n";
        return;
    }
    cout << "\nCartile sunt:\n";
    iterator_vector<carte> iter{books};
    iter.prim();
    while(iter.valid()) {
        const carte &book = iter.element();

        cout << "Author: " << book.get_author() << '\n';
        cout << "Title: " << book.get_title() << '\n';
        cout << "Genre: " << book.get_genre() << '\n';
        cout << "Publication Year: " << book.get_publication_year() << '\n';
        cout << "Book ID: " << book.get_book_id() << '\n';

        iter.next();
        cout << '\n';
    }
}

void ui_biblioteca::meniu(){
    cout<< "< 1 > Adaugare carte\n< 2 > Sterge carte\n< 3 > Modifica carte\n< 4 > Afiseaza cartile\n< 5 > Cautare\n< 6 > Filtrare: \n< 7 > Sortare\n< 8 > EXIT\nOption: ";
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
    cout<<"Id carte pentru a fi modificata: "; cin>> id_carte_to_be_modified;
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

    carte carte{ srv.search_for_book(autor, titlu, gen, an_pub) };

    cout << "Author: " << carte.get_author() << '\n';
    cout << "Title: " << carte.get_title() << '\n';
    cout << "Genre: " << carte.get_genre() << '\n';
    cout << "Publication Year: " << carte.get_publication_year() << '\n';
    cout << "Book ID: " << carte.get_book_id() << '\n';
}
void ui_biblioteca::filtare() {
    cout<<"\nFiltrare dupa an si titlu:\n";
    int an;
    string titlu;
    cout << "an: "; cin >> an;
    cout << "titlu: "; cin >> titlu;

    const my_vector<carte>& filtered_books{ srv.filter_srv(an,titlu) };

    afiseaza(filtered_books);
}
void ui_biblioteca::sortare() {
    cout << "\nSortare dupa titlu / autor / anul aparitiei + gen\n";
    int optiune = 0;
    cout<<"Alege:\n";
    cout<<"< 1 > Dupa titlu:\n";
    cout<<"< 2 > Dupa autor:\n";
    cout<<"< 3 > Dupa anul aparitiei + gen:\n";
    while(!(optiune == 1 || optiune == 2 || optiune == 3)){
        std::cout<<"Optiune: "; cin >> optiune;
    }
    const my_vector<carte>& sorted_books = srv.sorter_based_on_option(optiune);
    afiseaza(sorted_books);
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
                    break;
                case 6:
                    filtare();
                    break;
                case 7:
                    sortare();
                    break;
                case 8:
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
        catch (const std::exception){
            cout<< "Alta eroare!!\n";
        }
    }
}

