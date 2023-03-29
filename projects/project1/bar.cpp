#include "bar.h"

using namespace std; 

//bar class constructor inheriting from foobar base class
bar::bar(string b_name = "", int b_pos = 0)

  :foobar(b_name, b_pos) {
}

//calculating the bar strength
int bar::get_strength() {

  return pos + 15; 
}
