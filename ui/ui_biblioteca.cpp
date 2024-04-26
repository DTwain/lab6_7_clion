//
// Created by obrej on 4/10/2024.
//

#include "../Headers/ui_biblioteca.h"
#include "../Headers/carte.h"
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::cin;
using std::cout;
using std::vector;

int nr_cos;

void ui_biblioteca::afiseaza(const vector<carte>& books) {
    if(books.size() == 0){
        cout << "Nu sunt carti de afisat\n";
        return;
    }
    cout << "\nCartile sunt:\n";
    for(const carte& book: books){
        cout << "Author: " << book.get_author() << '\n';
        cout << "Title: " << book.get_title() << '\n';
        cout << "Genre: " << book.get_genre() << '\n';
        cout << "Publication Year: " << book.get_publication_year() << '\n';
        cout << "Book ID: " << book.get_book_id() << '\n';

        cout << '\n';
    }
}

void ui_biblioteca::meniu(){
    cout<< "\n< 1 > Adaugare carte\n< 2 > Sterge carte\n< 3 > Modifica carte\n< 4 > Afiseaza cartile\n< 5 > Cautare\n< 6 > Filtrare: \n< 7 > Sortare\n< 8 > Adauga carte in cos\n< 9 > Goleste cos\n< 10 > Genereaza cos\n< 11 > Export\n< 12 > Raport\n< 13 > Undo\n< 14 > EXIT\nOption: ";
}
void ui_biblioteca::add_book() {
    string autor, titlu, gen;
    int an_pub;
    cout<<"autor: "; getline(cin, autor);

    cout<<"titlu: "; getline(cin, titlu);

    cout<<"gen: "; getline(cin, gen);

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
    std::cin.ignore(1, '\n');
    string autor, titlu, gen;
    int an_pub;
    cout<<"autor: "; getline(cin, autor);

    cout<<"titlu: "; getline(cin, titlu);

    cout<<"gen: "; getline(cin, gen);

    cout<<"an: "; cin >> an_pub;

    srv.modify_book_srv(autor, titlu, gen, an_pub, id_carte_to_be_modified);
}
void ui_biblioteca::cautare(){
    cout << "Pentru autor / titlu / gen : string pt cautarea campului altfel <ENTER>\n Pentru an_pub : c > 0 pt pass\n";
    string autor, titlu, gen;
    int an_pub;
    cout<<"autor: "; getline(cin, autor);

    cout<<"titlu: "; getline(cin, titlu);

    cout<<"gen: "; getline(cin, gen);

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
    std::cin.ignore(1, '\n');
    cout << "titlu: "; getline(cin, titlu);

    const vector<carte>& filtered_books{ srv.filter_srv(an,titlu) };

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
    const vector<carte>& sorted_books = srv.sorter_based_on_option(optiune);
    afiseaza(sorted_books);
}

void ui_biblioteca::add_cos(){
    afiseaza(srv.get_all_srv());
    string titlu;
    cout << "Introdu titlul cartii pe care doresti sa o adaugi in cos: ";
    getline(cin, titlu);

    service_cos.add_carte_in_cos(titlu);

    cout<< "NR carti din cos: " << service_cos.get_nr_carti_din_cos() << "\n\n";
}

void ui_biblioteca::goleste_cos() {
    service_cos.goleste_cos();

    cout<< "NR carti din cos: " << service_cos.get_nr_carti_din_cos() << "\n\n";
}

void ui_biblioteca::genereaza_cos() {
    int nr_carti_de_adaugat;
    cout << "Introdu cate carti doresti sa fie in cos: ";
    cin >> nr_carti_de_adaugat;
    std::cin.ignore(1, '\n');
    service_cos.genereaza_cos(nr_carti_de_adaugat);

    cout<< "NR carti din cos: " << service_cos.get_nr_carti_din_cos() << "\n\n";
}

void ui_biblioteca::export_cos() {
    string nume_fisier;
    cout << "Nume fisier pentru export cos: ";
    cin >> nume_fisier;

    service_cos.export_cos(nume_fisier, nr_cos);
    nr_cos += 1;
    cout << "NR carti din cos: " << service_cos.get_nr_carti_din_cos() << "\n\n";
}

void ui_biblioteca::raport() {
    map<string, DTO_carte> raport = srv.raport();
    for(auto it = raport.begin(); it != raport.end(); ++it){
        std::cout << "Gen: " << it -> second.genre << " nr_entitati: " << it->second.numar_entitati << "\n";
    }
}

void ui_biblioteca::undo() {
    srv.do_undo();
    cout << "Undo succesful\n";
}
void ui_biblioteca::add_elems(){
    srv.add_book_srv("I.L.C", "O scrisoare pierduta", "dramatic", 1884);
    srv.add_book_srv("Albert Camus", "Strainul", "dramatic", 1942);
    srv.add_book_srv("Frank Kafka", "Procesul", "dramatic", 1925);
    srv.add_book_srv("Jane Austen", "Mandrie si prejudecata", "dramatic", 1813);
    srv.add_book_srv("Dante Alighieri", "Divina Comedie", "epic", 1320);
    srv.add_book_srv("John Milton", "Paradisul pierdut", "epic", 1667);
    srv.add_book_srv("Torquato Tasso", "Ierusalimul eliberat", "epic", 1581);
    srv.add_book_srv("William Shakespeare", "Sonetul 18", "liric", 1609);
    srv.add_book_srv("Emily Dickinson", "Hope is the Thing with Feathers", "liric", 1861);
    srv.add_book_srv("Langston Hughes", "Harlem", "liric", 1951);
}
void ui_biblioteca::run(){
    //add_elems();
    while(true){
        meniu();
        int option;
        cin>>option;
        std::cin.ignore(1, '\n');
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
                    add_cos();
                    break;
                case 9:
                    goleste_cos();
                    break;
                case 10:
                    genereaza_cos();
                    break;
                case 11:
                    export_cos();
                    break;
                case 12:
                    raport();
                    break;
                case 13:
                    undo();
                    break;
                case 14:
                    return;
                default:
                    cout << "Optiunea nu exista!\n";
            }
        }
        catch (const book_validation_exception& ex){
            cout << "< A CRAPAT > " << ex << '\n';
        }
        catch (const book_repo_exception& ex){
            cout << "< A CRAPAT > " << ex << '\n';
        }
        catch (const books_service_exception& ex){
            cout << "< A CRAPAT > " << ex << '\n';
        }
        catch (const std::exception){
            cout<< "Alta eroare!!\n";
        }
    }
}

