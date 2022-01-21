#include "lavable.hh"
#include <iostream>
#include <string>

Lavable::Lavable(const Protection &p):Protection(p){

    for(std::size_t i = 0; i < nb_annees; i++)
    {
        res_an[i] = 0;
    }
    for(std::size_t i = 0; i < nb_cycle; i++)
    {
        res_cycle[i] = 0;
    }

}



void Lavable::calcul_prix(){
    for(std::size_t i = 0; i < nb_annees; i++) //variation dans les années (0 = la premiere année d'utilisation)
    {
        res_an[i] = _prixan;// prix par an

        if (i != 0)
        {
            res_an[i] = res_an[i] + res_an[i-1]; // On additionne avec l'année précédente
        }
    }
    for(std::size_t i = 0; i < nb_cycle; i++)
    {
        res_cycle[i] = _prixcycle;// prix par cycle
        if (i != 0)
        {
            res_cycle[i] = res_cycle[i] + res_cycle[i-1]; // On additionne avec l'année précédente
        }
    }

}
void Lavable::print(){

    for(std::size_t i = 0; i < nb_cycle; i++){
        std::cout << "En utilisant que des protections lavables : \nAu cycle " << i << " de la première année vous aurez dépensé : " << res_cycle[i] << " € \n";
    }

    for(std::size_t i = 0; i < nb_annees; i++){
        std::cout << "En utilisant que des protections lavables : \nL'année " << i << " vous aurez dépensé : " << res_an[i] << " € en tout\n";
    }

}
