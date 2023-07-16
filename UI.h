#pragma once
#include <iostream>
#include <string>
using namespace std;

namespace ui{
    class UI{
    private:
        controller::Controller &ctrl;


    public:
        UI(controller::Controller &ctrl);
    void menu();

    };

}