#ifndef BAR_H
#define BAR_H

#include "foobar.h"

//bar class inherits from foobar class, has its own get_strength function
class bar : public foobar {

  public:
    bar(std::string b_name, int b_pos); 
    int get_strength();
};


#endif //BAR_H
