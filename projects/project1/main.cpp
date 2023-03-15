#include <iostream>
#include <vector>

using namespace std; 


class foobar {

  string  name;
  int     cur_pos; 

  protected:
    int pos = cur_pos;  

  public:
    
    //constructor
    foobar(string fb_name, int fb_pos); 

    //public member functions
    foobar&  set_position(int position);
    string   get_name(void); 

    //virtual function   
    virtual int  get_strength() {return 0;};
};


class foo : public foobar {

  public:
    foo(string f_name, int f_pos); 
    int get_strength(); 
};


class bar : public foobar {

  public:
    bar(string b_name, int b_pos); 
    int get_strength();
};


foobar::foobar(string fb_name = "", int fb_pos = 0) {

  name = fb_name; 
  cur_pos = fb_pos; 
}


string foobar::get_name() {

  return name; 
}


foo::foo(string f_name = "", int f_pos = 0) 

  :foobar(f_name, f_pos) {
}



int foo::get_strength() {

  return pos * 3; 
}


bar::bar(string b_name = "", int b_pos = 0)

  :foobar(b_name, b_pos) {
}


int bar::get_strength() {

  return pos + 15; 
}




int main() {

  string n1 = "Mushu"; 
  int pos = 1; 

  foobar *fb1 = new foobar(n1, pos);   

  cout << "name is " << fb1->get_name() << "\n";  


  return 0; 
}









