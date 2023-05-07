// THIS IS THE PROVIDED CODE FOR PROGRAM #3, DSA 1, SPRING 2023
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cctype>
#include <cstdlib>

using namespace std;

// A simple class; each object holds four public fields
class Data {
public:
  string lastName;
  string firstName;
  string ssn;
};

// Load the data from a specified input file
void loadDataList(list<Data *> &l, const string &filename) {

  ifstream input(filename);
  if (!input) {
    cerr << "Error: could not open " << filename << "\n";
    exit(1);
  } // The first line indicates the size string line;
  getline(input, line);
  stringstream ss(line);
  int size;
  ss >> size;

  // Load the data
  for (int i = 0; i < size; i++) {
    getline(input, line);
    stringstream ss2(line);
    Data *pData = new Data();
    ss2 >> pData->lastName >> pData->firstName >> pData->ssn;
    l.push_back(pData);
  }

  input.close();
}

// Output the data to a specified output file
void writeDataList(const list<Data *> &l, const string &filename) {

  ofstream output(filename);
  if (!output) {
    cerr << "Error: could not open " << filename << "\n";
    exit(1);
  }

  // Write the size first
  int size = l.size();
  output << size << "\n";

  // Write the data
  for (auto pData:l) {
    output << pData->lastName << " " 
	   << pData->firstName << " " 
	   << pData->ssn << "\n";
  }

  output.close();
}

// Sort the data according to a specified field
// (Implementation of this function will be later in this file)
void sortDataList(list<Data *> &);

// The main function calls routines to get the data, sort the data,
// and output the data. The sort is timed according to CPU time.
int main() {
  string filename;
  cout << "Enter name of input file: ";
  cin >> filename;
  list<Data *> theList;
  loadDataList(theList, filename);

  cout << "Data loaded.\n";

  cout << "Executing sort...\n";
  clock_t t1 = clock();
  sortDataList(theList);
  clock_t t2 = clock();
  double timeDiff = ((double) (t2 - t1)) / CLOCKS_PER_SEC;

  cout << "Sort finished. CPU time was " << timeDiff << " seconds.\n";

  cout << "Enter name of output file: ";
  cin >> filename;
  writeDataList(theList, filename);

  return 0;
}

// -------------------------------------------------
// YOU MAY NOT CHANGE OR ADD ANY CODE ABOVE HERE !!!
// -------------------------------------------------

// You may add global variables, functions, and/or
// class defintions here if you wish.

void sortDataList(list<Data *> &l) {
	
	// Fill this in
  	Node* head = l->head;
	// code to populate the linked list...
	head = sortList(head);
}


// Define a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to swap two nodes in a linked list
void swapNodes(Node* a, Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// Function to partition the linked list and return the pivot node
Node* partition(Node* head, Node* end, Node** newHead, Node** newEnd) {
    Node* pivot = end;
    Node* prev = NULL, *current = head, *tail = pivot;

    while (current != pivot) {
        if (current->data < pivot->data) {
            if (*newHead == NULL) {
                *newHead = current;
            }
            prev = current;
            current = current->next;
        }
        else {
            if (prev != NULL) {
                prev->next = current->next;
            }
            Node* temp = current->next;
            current->next = NULL;
            tail->next = current;
            tail = current;
            current = temp;
        }
    }

    if (*newHead == NULL) {
        *newHead = pivot;
    }
    *newEnd = tail;

    return pivot;
}

// Function to implement Quick Sort on a linked list
Node* quickSort(Node* head, Node* end) {
    if (head == NULL || head == end) {
        return head;
    }

    Node* newHead = NULL, *newEnd = NULL;
    Node* pivot = partition(head, end, &newHead, &newEnd);

    if (newHead != pivot) {
        Node* temp = newHead;
        while (temp->next != pivot) {
            temp = temp->next;
        }
        temp->next = NULL;
        newHead = quickSort(newHead, temp);
        temp = getTail(newHead);
        temp->next = pivot;
    }
    pivot->next = quickSort(pivot->next, newEnd);

    return newHead;
}

// Function to sort a linked list using Quick Sort
Node* sortList(Node* head) {
    head = quickSort(head, getTail(head));
    return head;
}
