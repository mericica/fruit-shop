using namespace std;
#include <string>
#include <vector>
#include <iostream>
#include <memory>
#pragma once
#include <string>

namespace domain {

    class Fruit {

    private:
        string name;
        string origin;
        string expiration_date;
        int quantity;
        int price;


    public:
        Fruit(string name, string origin, string expiration_date, int quantity, int price);

        string get_name();

        string get_origin();

        string get_exp_date();

        int get_price();

        int get_quantity();


        void set_quantity(int quantity_);

        void set_exp_date(string exp_date);


    };
}