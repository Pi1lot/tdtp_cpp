#ifndef MY_CLASS_H
#define MY_CLASS_H

#include <string>

class my_class {
private:
    std::string my_string;

public:
    my_class();
    my_class(const std::string& str);

    void print_my_element() const;
};

#endif
