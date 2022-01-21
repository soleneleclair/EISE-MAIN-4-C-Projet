#include "cup.hh"
#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


Cup::Cup(const Protection &p):Protection(p){
    for(std::size_t i = 0; i < nb_annees; i++)
    {
        res_an[i] = 0;
    }
    for(std::size_t i = 0; i < nb_cycle; i++)
    {
        res_cycle[i] = 0;
    }
}


void Cup::calcul_prix(){
    for(std::size_t i = 0; i < nb_annees; i++) //variation dans les années (0 = la premiere année d'utilisation)
    {
        res_an[i] = _prixan;// prix par an
        if (i != 0)
            res_an[i] = res_an[i] + res_an[i-1]; // On additionne avec l'année précédente
    }
    for(std::size_t i = 0; i < nb_cycle; i++)// parcourt les cycles ( 0 = le premier cycle)
    {
        res_cycle[i] = _prixcycle;// prix par cycle
        if (i != 0)
        {
            res_cycle[i] = res_cycle[i] + res_cycle[i-1]; // On additionne avec l'année précédente
        }
    }

}

void Cup::print(){
//affichage dans le terminal des différents couts selon les cycles et les années
  std::cout << "En utilisant que la cup:\n";

    for(std::size_t i = 0; i < nb_cycle; i++){
         std::cout << "Au cycle " << i << " de la première année vous aurez dépensé : " << res_cycle[i] << " € \n";
    }

    for(std::size_t i = 0; i < nb_annees; i++){
        std::cout << "L'année " << i << " vous aurez dépensé : " << res_an[i] << " € en tout\n";
    }
}
