#include "foobar.h"

using namespace std; 

//foobar class constructor
foobar::foobar(string fb_name = "", int fb_pos = 0) {

  name = fb_name; 
  cur_pos = fb_pos; 
}

//foobar class fucntion to set the position of the foobar
foobar &foobar::set_position(int position) {

  cur_pos = position;
  pos = cur_pos; 

  return *this; 
}

//function that returns a foobar type's strength
int foobar::get_strength() {

  return pos;  
}

//function that returns the foobar's name
string foobar::get_name() {

  return name; 
}
