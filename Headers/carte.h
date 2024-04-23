//
// Created by obrej on 4/10/2024.
//


#ifndef LAB6_7_CLION_CARTE_H
#define LAB6_7_CLION_CARTE_H

#include <string>
#include <vector>
#include <ostream>
#include <iostream>

using std::vector;
using std::string;
using std::ostream;

class carte
{
private:
    string author,
            title,
            genre;
    int publication_year,
            book_id;

public:
    carte() = default;

    carte(const string author, const string title, const string genre, const int year, const int id)
            :author{ author }, title{ title }, genre{ genre }, publication_year{ year }, book_id{ id }{}
    carte(const carte& ceva): author{ceva.author}, title{ceva.title}, genre{ceva.genre}, book_id{ceva.book_id}, publication_year{ceva.publication_year}{
            std::cout<<"hi\n";
    }

    bool operator==(const carte& other) const;

    string get_author() const;
    string get_title() const;
    string get_genre() const;
    int get_publication_year() const;
    int get_book_id() const;

};

class DTO_carte{
public:
    string genre;
    int numar_entitati;

    DTO_carte() = default;
    DTO_carte(const string& gen, int nr_entitati): genre{gen}, numar_entitati{nr_entitati}{};

};

#endif
