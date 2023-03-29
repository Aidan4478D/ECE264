#include "foo.h"

using namespace std; 

//foo class constructor inheriting from the base class foobar
foo::foo(string f_name = "", int f_pos = 0) 

  :foobar(f_name, f_pos) {
}

//function to calculate a foo type's strength
int foo::get_strength() {

  return pos * 3; 
}
