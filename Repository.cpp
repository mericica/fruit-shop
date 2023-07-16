#include "Repository.h"
#include <vector>
#include <iostream>
#include <memory>
#include <string>
#include <algorithm>
using namespace std;

namespace repository {
    Repository::Repository() {

    }

    void Repository::add(shared_ptr<Fruit> fruit_ptr) {

        bool gefunden = false;
        for (auto it = fruits.begin(); it != fruits.end(); it++) {
            //if the name and origin are already there, update thr quantity
            if ((*it)->get_name() == (*fruit_ptr).get_name() && (*it)->get_origin() == (*fruit_ptr).get_origin()) {
                (*it)->set_quantity((*it)->get_quantity() + (*fruit_ptr).get_quantity());
                gefunden = true;
            }
        }
        //if not, add the fruit
        if (!gefunden) {
            fruits.push_back(fruit_ptr);
        }

    }

    void Repository::remove(shared_ptr<Fruit> fruit_ptr) {
//any changes made to p within the lambda function should be reflected in the calling code.
        fruits.erase(remove_if(fruits.begin(), fruits.end(),
                               [&](const shared_ptr<Fruit> &p) {
                                   return p->get_name() == fruit_ptr->get_name() &&
                                          p->get_origin() == fruit_ptr->get_origin();
                               }), fruits.end());


    }


    shared_ptr<vector<shared_ptr<Fruit>>> Repository::get_all() {
        //getting all the fruits
        vector<shared_ptr<Fruit>> new_fruits(fruits.begin(), fruits.end());
        return make_shared<vector<shared_ptr<Fruit>>>(new_fruits);

    }
}

