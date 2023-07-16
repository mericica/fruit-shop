//
// Created by Maria on 4/19/2023.
//

#pragma once
#include <vector>
#include <iostream>
#include <memory>
#include <string>
#include "Domain.h"
using namespace std;
using namespace domain;

namespace repository {
    class Repository {

    private:
        //vector<shared_ptr<Fruit>> fruits;

    public:
        vector<shared_ptr<Fruit>> fruits;

        Repository();

        void add(shared_ptr<Fruit>);

        void remove(shared_ptr<Fruit> fruit_ptr);

        shared_ptr<vector<shared_ptr<Fruit>>> get_all();


    };
}
