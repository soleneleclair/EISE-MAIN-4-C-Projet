#include "jetable.hh"
#include <iostream>
#include <string>

Jetable::Jetable(const Protection &p):Protection(p){
//    res_an = new float [nb_annees];
//    res_cycle = new float [nb_annees];
    for(std::size_t i = 0; i < res_an.size(); i++)
    {
        res_an[i] = 0;
    }
    for(std::size_t i = 0; i < res_cycle.size(); i++)
    {
        res_cycle[i] = 0;
    }
}
//Cup(const Cup &c): Protection(c),_duree(c._duree), _prixuni(c._prixuni), _prixan(c._prixan), _prixcycle(c._prixcycle), res(c.res){};


void Jetable::calcul_prix(){
    for(std::size_t i = 0; i < res_an.size(); i++) //variation dans les années (0 = la premiere année d'utilisation)
    {
        res_an[i] = _prixan;// prix par an
        if (i != 0)
        {
            res_an[i] = res_an[i] + res_an[i-1]; // On additionne avec l'année précédente

        }
    }
    for(std::size_t i = 0; i < res_cycle.size(); i++)
    {
        res_cycle[i] = _prixcycle;// prix par cycle
        if (i != 0)
        {
            res_cycle[i] = res_cycle[i] + res_cycle[i-1]; // On additionne avec l'année précédente
        }
    }

}
void Jetable::print() const{
  std::cout << "En utilisant que des protections jetables : "<< std::endl;

    for(std::size_t i = 0; i < nb_cycle; i++){
        std::cout << "\nAu cycle " << i << " de la première année vous aurez dépensé : " << res_cycle[i] << " € \n";
    }

    for(std::size_t i = 0; i < nb_annees; i++){
        std::cout << "\nL'année " << i << " vous aurez dépensé : " << res_an[i] << " € en tout\n";
    }
}
