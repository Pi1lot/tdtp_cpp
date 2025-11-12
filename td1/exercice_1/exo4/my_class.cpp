#include <iostream>
#include "my_class.h"

my_class::my_class() : my_string("Default") {}

my_class::my_class(const std::string& str) : my_string(str) {}

void my_class::print_my_element() const {
    std::cout << my_string << std::endl;
}
