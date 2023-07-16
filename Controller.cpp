#include "Domain.h"
#include "Repository.h"
#include <iostream>
#include <string>
#include <memory>
#include "Controller.h"
#include <sstream>

namespace controller{

    Controller::Controller(Repository &r) : repo(r){}

    void Controller::add(string name, string origin, string expiration_date, int quantity, int price) {
        shared_ptr<Fruit> new_fruit_ptr = make_shared<Fruit>(name,origin,expiration_date,quantity,price);
        repo.add(new_fruit_ptr);

    }

    void Controller::remove(string name, string origin) {
        shared_ptr<Fruit> new_fruit_ptr = make_shared<Fruit>(name,origin,"123",-1,-1);
        repo.remove(new_fruit_ptr);
    }

    void Controller::find(string substring) {
        shared_ptr<vector<shared_ptr<Fruit>>> new_fruits = repo.get_all();
//find if there are any fruits that match the string. the quantity of the fruits should be lower than the user input
        vector<shared_ptr<Fruit>> matching_fruits;
        for (auto &fruit: *new_fruits) {
            if (fruit->get_name().find(substring) != string::npos || fruit->get_origin().find(substring) != string::npos)
                matching_fruits.push_back(fruit);
            }
//if yes, sort all matching fruits and display them
        if (!matching_fruits.empty() or substring!= "\n") {
            sort(matching_fruits.begin(), matching_fruits.end(),
                 [](const shared_ptr<Fruit> &a, const shared_ptr<Fruit> &b) {
                     return a->get_name() < b->get_name();
                 }

            );
            for (const auto &element: matching_fruits) {
                cout << element->get_name() << ": from " << element->get_origin() << ", in quantity of " << element->get_quantity()
                     << ", expire "
                     << element->get_exp_date() << ", and cost " << element->get_price() << endl;
            }
        } else {
            cout << "The fruit does not exist. Only these are available:" << "\n";
            sort(new_fruits->begin(), new_fruits->end(),
                 [](const shared_ptr<Fruit> &a, const shared_ptr<Fruit> &b) {
                     return a->get_name() < b->get_name();
                 });

            // Display the fruits
            for (const auto &element: *new_fruits) {
                cout << element->get_name() << ": from " << element->get_origin() << ", in quantity of " << element->get_quantity()
                     << ", expire "
                     << element->get_exp_date() << ", and cost " << element->get_price() << endl;
            }
        }


        }

        void Controller::find_by_quantity(int max_quantity){
            shared_ptr<vector<shared_ptr<Fruit>>> new_fruits = repo.get_all();
            vector<shared_ptr<Fruit>> matching_fruits;
            //if the quantity of the fruits are less than the users given quantity, display all the fruits
            for (auto &fruit: *new_fruits) {
                if (fruit->get_quantity() < max_quantity)
                    matching_fruits.push_back(fruit);
            }
            for (const auto &element: matching_fruits) {
                cout << element->get_name() << ": from " << element->get_origin() << ", in quantity of " << element->get_quantity()
                     << ", expire "
                     << element->get_exp_date() << ", and cost " << element->get_price() << endl;
            }


    }
    void Controller::sort_by_expiration_date(){
        shared_ptr<vector<shared_ptr<Fruit>>> new_fruits = repo.get_all();
        int day, month, year;
        string output_string;
        for (auto &element: *new_fruits) {
            //change eahc string to int
            stringstream ss(element->get_exp_date());
            string store_substring;
            getline(ss, store_substring, '/');
            day = stoi(store_substring);

            getline(ss, store_substring, '/');
            month = stoi(store_substring);

            getline(ss, store_substring);
            year = stoi(store_substring);
            //change the date format to accurately compare it
            output_string = to_string(year) + to_string(month) + to_string(day);
            element->set_exp_date(output_string);
        }

        sort(new_fruits->begin(), new_fruits->end(),
             [](const shared_ptr<Fruit> &a, const shared_ptr<Fruit> &b) {
                 return a->get_exp_date() < b->get_exp_date();
             });


        for (const auto &element: *new_fruits) {
            cout << element->get_name() << ", ";
        }
cout << endl;

    }
    void Controller::print_fruits(){
        shared_ptr<vector<shared_ptr<Fruit>>> new_fruits = repo.get_all();
        for (const auto &element: *new_fruits) {
            cout << element->get_name() << ": from " << element->get_origin() << ", in quantity of " << element->get_quantity()
                 << ", expire "
                 << element->get_exp_date() << ", and cost " << element->get_price() << endl;
        }
    }


}