#include <iostream> 
#include <stdint.h>
#include <string.h>

#include <sstream>
#include <fstream>
#include <vector>
#include <list>

using namespace std; 

template <typename T> class SimpleList {

  private:
    struct Node { 
      T data;
      Node *next;

      Node(const T &d, Node *n = nullptr ) {

        data = d;
        next = n; 
      }
      //Node( Object && d, Node * p = nullptr, Node * n = nullptr ) : data { std::move( d ) }, prev{ p }, next{ n}{}
    };

    int list_size; 
    string list_name; 
    Node *tail; 
    Node *head; 
   
  public:
    SimpleList(){tail = nullptr; head = nullptr; list_size = 0; list_name = "test";} 
    string get_list_name();
    int get_list_size(); 
    virtual int push_list(T d); 
    virtual T pop_list(T d); 

  protected:
    int append_list(T d);  //add to end
    int prepend_list(T d); //add to start
    T dequeue_list(); //take away from start
  
}; 


template <typename T> int SimpleList<T>::append_list(T d) {

  Node *new_node = new Node(d);
  if(new_node == nullptr) { return -1; } 

  if(list_size == 0) { new_node->next = new_node; }
  else { new_node->next = nullptr; tail->next = new_node; }

  tail = new_node; 
  list_size++; 

  return 0; 
}


template <typename T> int SimpleList<T>::prepend_list(T d) {

  Node *new_node = new Node(d);
  if(new_node == nullptr) { return -1; } 

  if(list_size == 0) { new_node->next = new_node; }
  else { new_node->next = head; }

  head = new_node;  
  list_size++; 

  return 0; 
}


template <typename T> T SimpleList<T>::dequeue_list() {
  
  if(list_size == 0) { return -1; } 
  Node *temp_node = head->next; 
  T value = head->data; 

  delete head;        //deletes current head
  head = temp_node;   //sets the new head ptr to the next node
  
  return value; 
}


template <typename T> string SimpleList<T>::get_list_name() {

  return this->list_name; 
}
template <typename T> int SimpleList<T>::get_list_size() {

  return this->list_size; 
}





template <typename T> class Stack : public SimpleList<T> {
  
  public:
    Stack(string l_name);
    int push_list(T d);
    T pop_list(); 
};

template <typename T> Stack<T>::Stack(string l_name) {

  this->list_name = l_name;
  this->head = this->tail = nullptr;
}
template <typename T> int Stack<T>::push_list(T d) {

  return append_list(d); 
}
template <typename T> T Stack<T>::pop_list() {

  //i think need new funciton to take off the end
  return this->dequeue_list();
}





template <typename T> class Queue : public SimpleList<T> {

  public:
    Queue(string l_name); 
    int push_list(T d); 
    T pop_list(); 
};

template <typename T> Queue<T>::Queue(string l_name) {

  this->list_name = l_name; 
  this->head = this->tail = nullptr;
}
template <typename T> int Queue<T>::push_list(T d) {
  
  return prepend_list(d); 
}
template <typename T> T Queue<T>::pop_list() {

  //i think need new funciton to take off the end
  return this->dequeue_list();
}


template <typename T> bool check_names(list<SimpleList<T> *> l, string new_name) {

  for (auto itr : l) {
    
    if(itr->get_list_name().compare(new_name) == 0) {
      
      return false; 
    }
  }

  return true; 
}

template <typename T> SimpleList<T> *get_list(list<SimpleList<T> *> l, string name) {
  
  for (auto itr : l) {

    if(itr->get_list_name().compare(name) == 0) {
      
      return itr; 
    }
  }
}



//function to parse through the input file
template <typename T>
void parse_file(string file_name) {

  ifstream f (file_name); 
  string line = "";

  list<SimpleList<int> *> listSLi; // all integer stacks and queues
  list<SimpleList<double> *> listSLd; // all double stacks and queues
  list<SimpleList<string> *> listSLs; // all string stacks and queues

  if(f.is_open()) {
    
    while(!f.eof()) {

      vector<string> buffer; 
      
      getline(f, line);
      if(line.empty()) { return; }
      
      stringstream s(line);
      int counter = 0; string itr = "";    
      
      while(s >> itr) {

        buffer.push_back(itr); 
      }
      string command = buffer[0], name = buffer[1], word  = buffer[2]; 
      char type = name[0]; 


      //creating lists
      if(command.compare("create") == 0) {
        
        if(type == 'i') {
          
          if(!check_names(listSLi, name)) goto already_exists; 
          listSLi.push_back(word.compare("stack") == 0 ?
            (SimpleList<int>*) new Stack<int>(name) : 
            (SimpleList<int>*) new Queue<int>(name));
        }
        if(type == 'd') {
          
          if(!check_names(listSLd, name)) goto already_exists; 
          listSLd.push_back(word.compare("stack") == 0 ?
            (SimpleList<double>*) new Stack<double>(name) : 
            (SimpleList<double>*) new Queue<double>(name));
        }
        if(type == 's') {
          
          if(!check_names(listSLs, name)) goto already_exists; 
          listSLs.push_back(word.compare("stack") == 0 ?
            (SimpleList<string>*) new Stack<string>(name) : 
            (SimpleList<string>*) new Queue<string>(name));
        }
      }

      //pushing elements onto lists
      else if(command.compare("push") == 0) {

        // int stack/queue
        if (type == 'i') {
          if (check_names(listSLi, name)) goto doesnt_exist;
          get_list(listSLi, name)->push_list(stoi(word)); 
        }
        // double stack/queue
        if (type == 'd') {
      
          if (check_names(listSLd, name)) goto doesnt_exist;
          get_list(listSLd, name)->push_list(stod(word)); 
        }
        // string stack/queue
        if (type == 's') {
        
          if (check_names(listSLs, name)) goto doesnt_exist;
          get_list(listSLs, name)->push_list(word); 
        }
      }

      //popping elements from lists
      else {

        // int stack/queue
        if (type == 'i') {

          SimpleList<T> my_list = get_list(listSLi, name); 
          if (check_names(listSLi, name)) goto doesnt_exist;
          if (!my_list->get_list_size()) goto empty;
          cout << "Value popped: " << my_list->pop_list() << '\n';
        }

        // double stack/queue
        if (type == 'd') {
        
          SimpleList<T> my_list = get_list(listSLd, name); 
          if (check_names(listSLd, name)) goto doesnt_exist;
          if (!my_list->get_list_size()) goto empty;
          cout << "Value popped: " << my_list->pop_list() << '\n';
        }
        // string stack/queue
        if (type == 's') {
        
          SimpleList<T> my_list = get_list(listSLs, name); 
          if (check_names(listSLs, name)) goto doesnt_exist;
          if (!my_list->get_list_size()) goto empty;
          cout << "Value popped: " << my_list->pop_list() << '\n';
        }
      }
    } 
  }

  already_exists:
    cout << "ERROR: This name already exists!" << "\n"; 

  doesnt_exist:
    cout << "ERROR: This name does not exist!" << "\n";
  
  empty:
    cout << "ERROR: This list is empty!" << "\n"; 
}



int main() {
/*
  string input_file;
  cout << "input file name: " << "\n"; 
  cin >> input_file; 

  string output_file; 
  cout << "output file name: " << "\n"; 
  cin >> input_file; 
*/



  return 0; 
}

