#ifndef FOO_H
#define FOO_H

#include "foobar.h"

//foo class that inherits from foobar class, has its own get_strength function
class foo : public foobar {

  public:
    foo(std::string f_name, int f_pos); 
    int get_strength(); 
};

#endif //FOO_H
