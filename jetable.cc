#include "jetable.hh"
#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


Jetable::Jetable(const Protection &p):Protection(p){ // initialisation à 0 des différents résultats

    for(std::size_t i = 0; i < res_an.size(); i++)
    {
        res_an[i] = 0;
    }
    for(std::size_t i = 0; i < res_cycle.size(); i++)
    {
        res_cycle[i] = 0;
    }
}

//calcul du prix pour les cycle sur 1 an et calcul sur 10 ans
void Jetable::calcul_prix(){
    for(std::size_t i = 0; i < res_an.size(); i++) //variation dans les années (0 = la premiere année d'utilisation)
    {
        res_an[i] = _prixan;// prix par an
        if (i != 0)
        {
            res_an[i] = res_an[i] + res_an[i-1]; // On additionne avec l'année précédente

        }
    }
    for(std::size_t i = 0; i < res_cycle.size(); i++)// on parcourt selon les cycle ( 0 = le premier cycle )
    {
        res_cycle[i] = _prixcycle;// prix par cycle
        if (i != 0)
        {
            res_cycle[i] = res_cycle[i] + res_cycle[i-1]; // On additionne avec l'année précédente
        }
    }

}

void Jetable::print(){
//affichage dans le terminal des diiférentes résultats pour les serviettes jetables  selon les cycles et les années
  std::cout << "En utilisant que des protections jetables :\n";

    for(std::size_t i = 0; i < nb_cycle; i++){
         std::cout << "Au cycle " << i << " de la première année vous aurez dépensé : " << res_cycle[i] << " € \n";
    }

    for(std::size_t i = 0; i < nb_annees; i++){
        std::cout << "L'année " << i << " vous aurez dépensé : " << res_an[i] << " € en tout\n";
    }
}
