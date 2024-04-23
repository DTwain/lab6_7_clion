//
// Created by obrej on 4/23/2024.
//

#include "../Headers/cos_carti.h"
#include <algorithm>
#include <fstream>
#include <random>
void cos_carti::goleste_cos() {
    cos.goleste_repo();
}

void cos_carti::add_carte_in_cos(std::string titlu) {
    const vector<carte> &all{repo_carti.get_all()};
    auto itr = std::find_if(all.begin(), all.end(), [titlu](const carte &book) { return book.get_title() == titlu; });

    if (itr != all.end()) {
        cos.add_pt_cos(*itr);
    } else
        throw std::exception{};
}

void cos_carti::genereaza_cos(int nr_carti) {
    std::mt19937 mt{std::random_device{}()};
    std::uniform_int_distribution<> dist(0, repo_carti.get_all().size() - 1);

    for (int i = 0; i < nr_carti; ++i) {
        int random_nr = dist(mt);
        const carte &book = repo_carti.find_book_by_id(random_nr);
        cos.add_pt_cos(book);
    }
}

void cos_carti::export_cos(const string& nume_fisier, int nr_cos){
    const string HTML_BEGIN = "<!DOCTYPE html>\n<html  lang=\"ro\">\n<style>\n    table, th, td { \n        border:1px "
                              "\n        solid black; \n        text-align: center; \n    }"
                              "\n    table.center { \n        margin-left: auto; \n        margin-right: auto; \n    } "
                              "\n</style>\n<head>\n    <title>Cos</title>\n</head>\n<body>";
    const string HTML_END = "\n</body>\n</html>";
    const string HTML_TABLE_HEADER_BEGIN = "\n            <th>";
    const string HTML_TABLE_HEADER_END = "</th>";
    const string HTML_TABLE_ROW_BEGGIN = "\n        <tr>";
    const string HTML_TABLE_ROW_END = "\n        </tr>";
    const string HTML_TABLE_CELL_BEGIN = "\n            <td>";
    const string HTML_TABLE_CELL_END = "</td>";
    const string DOC_HEADER = "\n    <h2  style=\"text-align: center\">Cosul cu numarul " + std::to_string(nr_cos) + "</h2>";

    std::ofstream out_in_file(nume_fisier);

    // insert in file
    out_in_file << HTML_BEGIN;
    out_in_file << DOC_HEADER;

    // create table
    out_in_file << "\n    <table class=\"center\" style=\"width:75%\">";

    // create table header
    string TABLE_HEADER;
    TABLE_HEADER += HTML_TABLE_ROW_BEGGIN;
    TABLE_HEADER += HTML_TABLE_HEADER_BEGIN;
    TABLE_HEADER += "Numar carte";
    TABLE_HEADER += HTML_TABLE_HEADER_END;
    TABLE_HEADER += HTML_TABLE_HEADER_BEGIN;
    TABLE_HEADER += "Nume carte";
    TABLE_HEADER += HTML_TABLE_HEADER_END;
    TABLE_HEADER += HTML_TABLE_HEADER_BEGIN;
    TABLE_HEADER += "Autor";
    TABLE_HEADER += HTML_TABLE_HEADER_END;
    TABLE_HEADER += HTML_TABLE_HEADER_BEGIN;
    TABLE_HEADER += "Gen";
    TABLE_HEADER += HTML_TABLE_HEADER_END;
    TABLE_HEADER += HTML_TABLE_HEADER_BEGIN;
    TABLE_HEADER += "Anul publicatiei";
    TABLE_HEADER += HTML_TABLE_HEADER_END;
    TABLE_HEADER += HTML_TABLE_ROW_END;

    out_in_file << TABLE_HEADER;
    int cnt = 0;
    for(const carte& book: cos.get_all()){
        cnt += 1;
        string text;

        text += HTML_TABLE_ROW_BEGGIN;
        text += HTML_TABLE_CELL_BEGIN;
        text += std::to_string(cnt);
        text += HTML_TABLE_CELL_END;
        text += HTML_TABLE_CELL_BEGIN;
        text += book.get_title();
        text += HTML_TABLE_CELL_END;
        text += HTML_TABLE_CELL_BEGIN;
        text += book.get_author();
        text += HTML_TABLE_CELL_END;
        text += HTML_TABLE_CELL_BEGIN;
        text += book.get_genre();
        text += HTML_TABLE_CELL_END;
        text += HTML_TABLE_CELL_BEGIN;
        text += std::to_string(book.get_publication_year());
        text += HTML_TABLE_CELL_END;
        text += HTML_TABLE_ROW_END;

        out_in_file << text;
    }

    // close table
    out_in_file << "\n    </table>";

    // close html
    out_in_file << HTML_END;
    out_in_file.close();

    //return "Fisier creat cu succes!\nLocatia fisierului: D:/oop/lab06/cmake-build-debug/" + file_name;
}
