#include <iostream>
#include <vector>
#include <array>
#include <typeinfo>
#include "DataHandler.h"



int main() {

    DataHandler parser{};
    const auto& vertices = parser.parse();


    return 0;
}