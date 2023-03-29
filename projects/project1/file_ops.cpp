#include <fstream>
#include <sstream>
#include <vector>

#include "file_ops.h"
#include "foobar.h"
#include "foo.h"
#include "bar.h"


using namespace std;


//function to create objects based off of the first word in the each line of the input file
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



//function to parse through the input file
void parse_file(string file_name, vector<foobar *> *fb_vector) {

  ifstream f (file_name); 
  string line = ""; 

  if(f.is_open()) {
    
    while(!f.eof()) {

      getline(f, line);
      if(line.empty()) { return; }
      
      stringstream s(line);
      string word = "", fb_type = "", name = ""; 
   
      int count = 0;    
      while(s >> word) {

        count == 0 ? fb_type = word : name = word; 
        count++; 
      }

      fb_vector->push_back(pack_vector(fb_type, word));
    }
  }
}



//function to assign the position to each foobar object
void assign_positions(vector<foobar *> fb_vector) {
  
  for(size_t i = 0; i < fb_vector.size(); i++) {
    
    fb_vector[i]->set_position(fb_vector.size() - i); 
  }
}


//function to write to the name and strength to the output file
void write_file(vector<foobar *> fb_vector) {
  
  ofstream f; 
  f.open("output.txt");
   
  for(size_t i = 0; i < fb_vector.size(); i++) {

    f << fb_vector[i]->get_name() << " " << fb_vector[i]->get_strength() << "\n"; 
  }

  f.close(); 
}


