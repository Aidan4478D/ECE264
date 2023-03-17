#include "file_ops.h"

using namespace std; 

int main() {
  
  vector<foobar *> fb_vector; 
  string file_name;

  cout << "Please enter in an input file: " << "\n"; 
  cin >> file_name; 

  parse_file(file_name, &fb_vector); 
  assign_positions(fb_vector); 
  write_file(fb_vector);  

  return 0; 
}









