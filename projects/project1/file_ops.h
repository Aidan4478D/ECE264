#ifndef FILE_OPS_H
#define FILE_OPS_H

#include <vector>
#include "foobar.h"

using namespace std; 

foobar *pack_vector (string fb_type, string name); 
void parse_file (string file_name, vector<foobar *> *fb_vector);
void assign_positions (vector<foobar *> fb_vector); 
void write_file (vector<foobar *> fb_vector); 

#endif //FILE_OPS_H
