#pragma once
#include <iostream>
#include "Repository.h"
#include <string>

using namespace std;
using namespace repository;

namespace controller {
    class Controller {
    private:
        Repository &repo;


    public:
        Controller(Repository &r);

        void add(string name, string origin, string expiration_date, int quantity, int price);

        void remove(string name, string origin);

        void find(string substring);

        void find_by_quantity(int max_quantity);

        void sort_by_expiration_date();

        void print_fruits();


    };
}