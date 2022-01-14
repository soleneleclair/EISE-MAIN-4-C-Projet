#include "lavable.hh"
#include <iostream>
#include <string>

Lavable::Lavable(const Protection &p):Protection(p){
    res_an = new float [nb_annees];
    res_cycle = new float [nb_annees];
    for(std::size_t i = 0; i < nb_annees; i++)
    {
        res_an[i] = 0;
        res_cycle[i] = 0;
    }
}



void Lavable::calcul_prix(){
    for(std::size_t i = 0; i < nb_annees; i++) //variation dans les années (0 = la premiere année d'utilisation)
    {
        res_an[i] = _prixan;// prix par an
        res_cycle[i] = _prixcycle;
        if (i != 0)
        {
            res_an[i] = res_an[i] + res_an[i-1]; // On additionne avec l'année précédente
            res_cycle[i] = res_cycle[i] + res_cycle[i-1]; // On additionne avec l'année précédente
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
void Lavable::print() const{
    for(std::size_t i = 0; i < nb_annees; i++){
        std::cout << "En utilisant que des protections lavables : \nL'année " << i << "v ous aurez dépensé : " << res_an[i] << " € pour l'année et au : "<< i << "ème cycle de l'année vous aurez dépensé : "<<res_cycle[i]<<" €\n" ;
    }
}



