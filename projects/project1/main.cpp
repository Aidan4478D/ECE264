#include <iostream>
#include <vector>

#include <fstream>
#include <sstream>
#include <vector> 

#include <stdio.h> 

using namespace std; 


class foobar {

  string  name;
  int     cur_pos; 

  protected:
    int pos;  

  public:
    
    //constructor
    foobar(string fb_name, int fb_pos); 

    //public member functions
    foobar&  set_position(int position);
    string   get_name(void); 
    int      get_pos() { return pos; } 

    //virtual function   
    virtual int  get_strength();
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




foobar *pack_vector(string fb_type, string name) {

  if(fb_type.compare("foobar") == 0) {

    foobar *fb = new foobar(name, 0);
    return fb;  
  }
  if(fb_type.compare("foo") == 0) {

    foo *f = new foo(name, 0); 
    return f;
  }
  if(fb_type.compare("bar") == 0) {
    
    bar *b = new bar(name, 0);
    return b;  
  }

  return NULL; 
}




void parse_file(string file_name, vector<foobar *> *fb_vector) {

  ifstream f (file_name); 
  string line = ""; 

  if(f.is_open()) {
    
    while(!f.eof()) {

      getline(f, line);
      if(line.compare("") == 0) { return; }
      
      stringstream s(line);
      string word = "", fb_type = "", name = ""; 
   
      int count = 0;    
      while(s >> word) {

        count == 0 ? fb_type = word : name = word; 
        //cout << "the word is " << fb_type << " and name is " << name << "\n";  
        count++; 

       //cout << word << "\n"; 
      }

      foobar *fb = new foobar(); 
      fb = pack_vector(fb_type, word);  

      /*fb_vector->push_back(fb);*/
      fb_vector->push_back(pack_vector(fb_type, word));
      //cout << "successfully pushed element back" << "\n"; 
      cout << "name is " << fb->get_name() << " type is " << fb_type << " size of vector is " << fb_vector->size()  << "\n"; 
    }
  }
}



void assign_positions(vector<foobar *> fb_vector) {
  
  cout << "vector size is " << fb_vector.size() << "\n";

  for(size_t i = 0; i < fb_vector.size(); i++) {
    
    fb_vector[i]->set_position(fb_vector.size() - i); 
    cout << "successfully set position to " << i + 1 << "\n"; 
  }
}



void write_file(vector<foobar *> fb_vector) {

  printf("%ld is the size\n", fb_vector.size()); 
  
  ofstream f; 
  f.open("output.txt");

   
  for(int i = 0; i < fb_vector.size(); i++) {

   cout  << fb_vector[i]->get_name() << " " << fb_vector[i]->get_strength() << " " << fb_vector[i]->get_pos() << "\n"; 
  }
  
  for(size_t i = 0; i < fb_vector.size(); i++) {

    f << fb_vector[i]->get_name() << " " << fb_vector[i]->get_strength() << "\n"; 
  }

  f.close(); 
}







int main() {
  
  /*
  string n1 = "Mushu"; 
  int pos = 1; 

  foobar *fb1 = new foobar(n1, pos);   

  cout << "name is " << fb1->get_name() << "\n";  
  cout << "strenght is " << fb1->get_strength() << "\n"; 

  fb1->set_position(5); 

  cout << "strenght is " << fb1->get_strength() << "\n"; 


  foo *f1 = new foo("george", pos); 
  bar *b1 = new bar("ming", pos); 

  f1->set_position(3); 
  b1->set_position(5); foobar R2D2
foo Carl
foo Algorithms
bar IAmABar
bar xyz
foo 123q456
foo CooperUnion
bar DataStructures
foobar xyz
foo CooperUnion

  cout << "name is " << f1->get_name() << "\n";  
  cout << "strenght is " << f1->get_strength() << "\n"; 

  cout << "name is " << b1->get_name() << "\n";  
  cout << "strenght is " << b1->get_strength() << "\n"; 
  */
  vector<foobar *> fb_vector; 

  parse_file("sample_input.txt", &fb_vector); 
  assign_positions(fb_vector); 
  write_file(fb_vector);  

  return 0; 
}









