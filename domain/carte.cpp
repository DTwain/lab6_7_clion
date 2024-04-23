#include "../Headers/carte.h"

string carte::get_author() const {
    return this->author;
}

string carte::get_genre()const {
    return this->genre;
}

string carte::get_title() const {
    return this->title;
}

int carte::get_publication_year() const {
    return this->publication_year;
}

int carte::get_book_id() const {
    return this->book_id;
}

bool carte::operator==(const carte &other) const {
    return this->get_book_id() == other.get_book_id();
}