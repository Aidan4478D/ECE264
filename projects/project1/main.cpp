#include "file_ops.h"

using namespace std; 

int main() {
  
  //creating a vector of foobar pointers
  vector<foobar *> fb_vector; 
  string file_name;

  //asking for input file
  cout << "Please enter in an input file: " << "\n"; 
  cin >> file_name; 
  
  //function to parse through the input file
  parse_file(file_name, &fb_vector); 

  //assigning positions of content in file
  assign_positions(fb_vector); 

  //writing to output file
  write_file(fb_vector);  

  return 0; 
}









