#ifndef FOOBAR_H
#define FOOBAR_H

#include <iostream>

//foobar class defintion
class foobar {

  //each foobar has a name and position
  std::string   name;
  int           cur_pos; 

  //the position is able to be accessed from child classes
  protected:
    int pos;  

  public:
    
    //constructor
    foobar(std::string fb_name, int fb_pos); 

    //public member functions
    foobar&       set_position(int position);
    std::string   get_name(void); 

    //virtual function
    virtual int  get_strength();
};

#endif //FOOBAR_H
