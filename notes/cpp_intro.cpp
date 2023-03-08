#include <iostream>
#include <vector> 

using namespace std;

int main() {

	cout << "Hello world!" << endl;
	return 0; 	
}



//string stuff
string s1 = "Hello";
string s2 = "World";
string s3 = s1 + " " + s2 + "!"; 
string s4 = s3.substring(6,5); 
s3.replace(6, 5, "planet"); 




//printing vector values in for loops
vector<int> arr {1,2,3,4,5,6,7,8,9};

for(int i = 0; i < v.size(); i++) {
  //fast but less safe
  cout << v[i] << "\n"; 
}

for(int i = 0; i < v.size(); i++) {
  //v.at() has error checking; throws an exception if index is out of range
  cout << v.at(i) << "\n"; 
}

for(vector<int>::iterator ii = v.begin(); ii != v.end(); ii++) {
  //uses iterators
  cout << *ii << "\n"; 
}

for(auto i:v) {
  //compuler will figure out the type
  cout << i << "\n"; 
}




//map class
#include <map> 

map <string, string> correction; 
correction["teh"] = "the"; 
correction["adn"] = "and"; 


/* c++ allows refrencse which is a second name for a variable;
can be thought of as a pointer that is automatically derefrenced each time it's accessed
permanently change the address of a variable passed o it*/

void increment(int &r) {
  r++; 
}


/* dynamic memory uses 'new' and 'delete' operators
like malloc and free in c but they throw exceptions */

//p1 points to memory holding the single integer 5
int *p1; 
p1 = new int(5); 

//p2 points to an array large enough to hold 5 ints
int *p2; 
p2 = new int[5]; 

//deleting the allocated memory
delete p1; 
delete p2[]; 

//after freeing the memory you should set each pointer to nullptr
p1 = nullptr; //<-- is "cleaner"
p2 = NULL;


/* error handling = exceptions, generally want to use try lock */

try {
  while (true) { cout << "."; cout.flush(); new char[1_000_000];}
}

//new operator throws a bad_alloc exception when program runs out of memory
catch(bad_alloc& b) {
  cerr << "Memory exhausted: " << b.what() << "\n"; 
}

catch(...); //<-- an "ellipsis" which catches any exception



//functions can have the same name but need different parameters
void display(int);
void display(const string);
void display(char);

/*these two lead to ambiguity as when passing a decimal through the program doesn't know
which one to run */
void display(double); 
void display(float); 

//can cast the parameter as a float or double to call specific one
display((double) 5); //will call the double function





//functions can provide default vlaues for missing arguments; should only be in prototype
int add (int x1 = 0, int x2 = 0, int x3 = 0); 

//if you provide default value, you have to also provide default values for all parameters to right

int add (int x1, int x2, int x3) {

  return x1 + x2 + x3; 
}

add(7); //will return 7
add(); //will return 0


/*---------------------------- CLASSES -----------------------------------*/

/* has become the main way to allow object oriented programming */ 
//encapsulation - everything relating to the date is encapsulated within the class

/*---------header file----------*/ 

class Date {

  //data members
  int d, m, y; 
  static Date default_date; //static means that all dates share a defualt date; not tied to object

  public: 
    /* member functions */ 

    //constructors
    Date(int dd = 0, int mm = 0, int yy = 0); 
    Date(const std::string &); //date in string representation
    
    //static member funcitons can be called without an object
    static void set_default(int dd, int mm, int yy); 

    Date& set_day(int); 
    Date& set_month(int); 
    Date& set_year(int); 

    int day() const {return d;}
    int month() const {return m;}
    int year() const {return y;}

    void display() const; //const makes it so that you can't change object using member function
}


/*-------- source code file ---------*/ 

//objects - a variable whos type is a class; an "instance of a class"

Date d1(30, 9, 2020); 
Date d2; 
Date d3("September 20, 2022"); 
Date d4 {d1};//copy constructor
Date d4 = d1; //copy constructor

Date d5 = d2; //assignment operator


//:: is the scope resolution operator which means default_date is within the scope of date
Date Date::default_date(1, 1, 2000); 

void Date::set_default(int d, int m, int y) {

  default_date = Date(m, d, y); 
}


Date::Date(int dd, int mm, int yy) {

  d = dd ? dd : default_date.d; //if dd is non-zero assign it to d otherwise go to default date
  m = mm ? mm : default_date.m; 
  y = yy ? yy : defualt_date.y; 
}


//this refers to pointer to object in which the member class has invoked
Date& Date::set_day(int dd) {
  d = dd; 
  return *this; 
}


Date& Date::set_month(int mm) {
  m = mm; 
  return *this; 
}


Date& Date::set_year(int yy) {
  y = yy; 
  return *this; 
}

//returning a refrence so that you can do things like
d1.set_day(1).set_month(1).set_year(2022);


//only use inline functions for short funcitons that are commonly used 
inline bool operator==(const Date &); 





//class inheritence

class Employee {

  string first_name, last_name; 

  protected:
    //derived classes can see this

  public: 
    Employee(const string&, const string&); 
    void print() const; 
}


class Manager:public Employee {

  list <Employee *> group; 
  int level; 

  public:
    Manager(const string&, const string&, int l = 0); 
    void print() const; 
}


void Manager::print() const {

  Employee::print();
  std::cout << "Level" << Manager.level << endl; 
}



//constructors in derived classes
Manager::Manager(const string &f, const string &l, int x) {

  :Employee(f, l) {
    
    level = x
  }
}


m1 != e1; 
e1 == m1; //this is a bad idea though as you lose the manager information

Employee *pe1 = new Employee(fn1, ln1); 
Employee *pe2 = new Manager(fn2, ln2, level); 

list<Employee *> elist; 
elist.push_back(pe1); 
elist.push_back(pe2); 


//by adding virtual in the base class member function, it will call the right version of print
virtual void print() const; 



//an abstract class: not going to implement in base class (you declare it but the base class not going to implement)

class Shape {

  public:
    virtual void rotate(int) = 0;
    virtual void draw() = 0;
    virtual bool is_closed(); //not a pure virtual function

}


class Circle : public Shape {

  int radius;
  Point center;

  public:
    void rotate(int);
    void draw(); 
    bool is_closed(); //optionally overridden

}



//function template examples

template <typename T>

T GetMax(T a, T b) {

  T result;
  result = (a > b) ? a : b; 
  return result; 
}

int main() {

  int i = 5, j = 6, k; 
  double l = 10.1, m = 5.2, n; 

  k = GetMax <int> (i, j); 
  n = GetMax <double> (1, m); 
}



template <typename T> 

class my_pair {

  T a, b; 

  public: 
    my_pair(const T &first, const T &second) { a = first, b = second; }

    T get_max(); 
}


template <typename T>
T my_pair<T>::get_max() {

  T ret_val; 
  ret_val = (a > b) ? a : b; 
  return ret_val; 
}




















