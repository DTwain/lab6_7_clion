//
// Created by obrej on 4/23/2024.
//

#ifndef LAB6_7_CLION_COS_CARTI_H
#define LAB6_7_CLION_COS_CARTI_H

#include "../Headers/repo.h"

class cos_carti {
private:
    repo_abs &repo_carti;
    repo_abs &cos;
public:
    cos_carti(repo_abs& all, repo_abs& cos): repo_carti{all}, cos{cos}{}

    int get_nr_carti_din_cos();
    void add_carte_in_cos(string titlu);
    void goleste_cos();
    void genereaza_cos(int nr_carti);
    void export_cos(const string& nume_fisier, int nr_cos);
};


#endif //LAB6_7_CLION_COS_CARTI_H
