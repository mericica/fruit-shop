using namespace std;
#include <iostream>
#include "Controller.h"
#include "UI.h"
#include <string>

namespace ui{
    UI::UI(controller::Controller &c) : ctrl(c){}

void UI::menu(){
    ctrl.add("Banana","Africa","11/11/2022",3,3);
    ctrl.add("Mango","Africa","11/11/2022",2,1);
    ctrl.add("Golden Apple", "Romania", "12/10/2025", 20, 4);
    ctrl.add("Green Apple", "Spain", "9/4/2024", 34, 3);
    ctrl.add("Kiwi", "Bangladesh", "5/12/2030", 8, 8);
    ctrl.add("Grapes", "Romania", "12/3/2023", 2, 4);
    ctrl.add("Strawberry", "Spain", "5/3/2024", 45, 8);
    ctrl.add("Cherries", "Portugal", "10/8/2023", 33, 7);
    ctrl.add("Papaya", "Peru", "1/6/2025", 12, 5);
    ctrl.add("Orange", "Marok", "4/10/2030", 123, 3);
    int action;

    while(action!=0){
    cout << "Please choose an action: ";
    cout << "\n";
    cout << "1. Add a fruit" << "\n";
    cout << "2. Remove a fruit" << "\n";
    cout << "3. Find a fruit" << "\n";
    cout << "4. Display only the fruits which have a lower quantity than:" << "\n";
    cout << "5. Sort the fruits by expiration date \n";
    cout << "0. End actions, exit programm" << "\n";
    cin >> action;

    if (action==1) {
        string name, origin, expiration_date;
        int quantity, price;
        cout << "Enter product name: ";
        cin >> name;
        cout << "Enter product origin: ";
        cin >> origin;
        cout << "Enter product expiry date (Day/Month/Year): ";
        cin >> expiration_date;
        cout << "Enter product quantity: ";
        cin >> quantity;
        cout << "Enter product price: ";
        cin >> price;

        ctrl.add(name, origin, expiration_date, quantity, price);
        ctrl.print_fruits();
    }
    else if(action == 2){
        string name, origin;
        cout << "These are the available fruits: \n";
        ctrl.print_fruits();
        cout << "\n";
        cout<< "What fruit do you wish to remove?";
        cin >> name;
        cout << "What's the origin of the fruit?";
        cin >> origin;
        ctrl.remove(name, origin);
        ctrl.print_fruits();
    }
    else if (action == 3){
        string substring = " ";
        cout << "I want to get the fruit: " << endl;
        cin >> substring;
        ctrl.find(substring);
    }
    else if (action == 4){
        int max_quantity = 0;
        cout << " Maxim quantity should be: "<< endl;
        cin >> max_quantity;
        ctrl.find_by_quantity(max_quantity);
    }
    else if(action == 5){
        ctrl.sort_by_expiration_date();
    }
    else if(action<0 or action>5){
        cout << "The action doesn't exist. Please choose an action from below: \n";
    }
    }


}}