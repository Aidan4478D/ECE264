#ifndef BAR_H
#define BAR_H

#include "foobar.h"

class bar : public foobar {

  public:
    bar(std::string b_name, int b_pos); 
    int get_strength();
};


#endif //BAR_H
