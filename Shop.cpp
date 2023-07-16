#include <iostream>
#include<algorithm>
#include<vector>
#include "Domain.h"
#include "Repository.h"
#include "Controller.h"
#include <string>
#include <assert.h>
#include "UI.h"


void tests(){

    //test add

    Repository repo;
    controller::Controller ctrl(repo);
    ctrl.add("Banana","Africa","11/11/2022",3,3);
    ctrl.add("Mango","Africa","11/11/2022",2,1);

    assert(repo.fruits[0]->get_name() == "Banana");
    assert(repo.fruits[1]->get_name() == "Mango" );

    ctrl.add("Banana","Africa","11/11/2022",3,1);
    assert(repo.fruits[0]->get_quantity() == 6);
    cout << "test add done"<<endl;

    ctrl.add("Golden Apple", "Romania", "12/10/2025", 20, 4);
    ctrl.add("Green Apple", "Spain", "9/4/2024", 34, 3);
    ctrl.add ("Banana", "Africa", "2/4/2024", 22, 4);
    ctrl.add("Kiwi", "Bangladesh", "5/12/2030", 8, 8);
    assert(repo.fruits[3]->get_name()== "Green Apple");
    ctrl.remove("Green Apple", "Romania");
    assert(repo.fruits[3]->get_name()== "Green Apple");
    ctrl.remove("Green Apple", "Spain");
    assert(repo.fruits[3]->get_name() == "Kiwi");
    cout << "test remove done"<<"\n \n";

    ctrl.add("Grapes", "Romania", "12/3/2023", 2, 4);
    cout << "Produkte, gesucht nach string:"<<endl;
    ctrl.find("Romania");
    cout << endl << "Produkte mir einer kleinerer Quantitat als die vom User eingegebene Zahl:"<< endl;
    ctrl.find_by_quantity(10);







}



int main() {
   // tests();
    Repository repo;
    controller::Controller ctrl(repo);
    ui::UI u(ctrl) ;
   // u.menu();



    return 0;
}
