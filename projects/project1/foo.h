#ifndef FOO_H
#define FOO_H

#include "foobar.h"

class foo : public foobar {

  public:
    foo(std::string f_name, int f_pos); 
    int get_strength(); 
};

#endif //FOO_H
