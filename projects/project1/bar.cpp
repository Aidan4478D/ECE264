#include "bar.h"

using namespace std; 


bar::bar(string b_name = "", int b_pos = 0)

  :foobar(b_name, b_pos) {
}


int bar::get_strength() {

  return pos + 15; 
}
