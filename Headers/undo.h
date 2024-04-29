//
// Created by obrej on 4/24/2024.
//

#ifndef LAB6_7_CLION_UNDO_H
#define LAB6_7_CLION_UNDO_H

#include "carte.h"
#include "repo.h"

class undo{
public:
    virtual void do_undo() = 0;
    virtual ~undo() = default;
};

class undo_add : public undo {
private:
    carte book;
    repo_abs& repo_carti;
public:
    undo_add(repo_abs& repo_obj, const carte& book): book{book}, repo_carti{repo_obj} {}

    void do_undo() override{
        repo_carti.delete_book(book.get_book_id());
    }
};

class undo_delete : public undo {
private:
    carte book;
    repo_abs& repo_carti;
public:
    undo_delete(repo_abs& repo_obj, const carte& book) : book{book}, repo_carti{repo_obj} {}

    void do_undo() override{
        repo_carti.add(book);
    }
};

class undo_modify : public undo {
private:
    carte book;
    repo_abs& repo_carti;
public:
    undo_modify(repo_abs& repo_obj, const carte& book) : book{book}, repo_carti{repo_obj} {}

    void do_undo() override{
        repo_carti.modify_book(book);
    }
};


#endif //LAB6_7_CLION_UNDO_H
