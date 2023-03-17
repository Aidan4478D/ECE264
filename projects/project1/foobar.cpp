#include "foobar.h"

using namespace std; 

foobar::foobar(string fb_name = "", int fb_pos = 0) {

  name = fb_name; 
  cur_pos = fb_pos; 
}

foobar &foobar::set_position(int position) {

  cur_pos = position;
  pos = cur_pos; 

  return *this; 
}

int foobar::get_strength() {

  return pos;  
}


string foobar::get_name() {

  return name; 
}
