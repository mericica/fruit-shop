#include "Domain.h"
#include <string>
using namespace std;

namespace domain {
    Fruit::Fruit(string name, string origin, string expiration_date, int quantity, int price) {
        this->name = name;
        this->origin = origin;
        this->expiration_date = expiration_date;
        this->quantity = quantity;
        this->price = price;
}
    string Fruit::get_name() { return name; }

    string Fruit::get_origin() { return origin; }

    string Fruit::get_exp_date() { return expiration_date; }

    int Fruit::get_price() {return price;}

    int Fruit::get_quantity() { return quantity; }

    void Fruit::set_quantity(int quantity_) { quantity = quantity_; }

    void Fruit::set_exp_date(string exp_date) { expiration_date = exp_date;}






}