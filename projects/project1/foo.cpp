#include "foo.h"

using namespace std; 


foo::foo(string f_name = "", int f_pos = 0) 

  :foobar(f_name, f_pos) {
}


int foo::get_strength() {

  return pos * 3; 
}
