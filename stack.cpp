#include <iostream>
#include <stdlib.h>

 /*
    the node is a type of abstract data
    we can declare the nodes as a structure
 */ 

template <typename N>
struct Node
{ 
    N value;  // the value store in the node
    Node *next;  // the pointer to next node
};


// the stack is type of abstract data too so we can defined him with a class

template <typename S>
class Stack{

  // the stack need know what is the last element 
  Node<S> *index = NULL;

  public:
    /*
      the stack have two method
        push --> add a element to the stack
        pop --> remove a element from the stack
    */ 

    bool push(S);
    bool pop();
};
  
template <typename S>
bool Stack<S>::push(S value){
  /*
    1)  store in memory a node
    2) load the value in the node value
    3) store index in the node next pointer
    4) add new node to index
  */
  Node<S> *newNode = new Node<S>();
  newNode->value =  value;
  newNode->next = this->index;
  this->index = newNode;

  return true;
}

template <typename S>
bool Stack<S>::pop(){
  while (this->index != NULL)
  {
 
    Node<S> *aux = this->index;
    // std::cout<<"borro el: "<<aux->value<<"\n";
    this->index = aux->next;
    delete aux;
    
  }
  return true;
}



int main(){
  Stack<char> stackTest;
  char a = 'a', b = 'b';

  stackTest.push(a);
  stackTest.push(b);

  stackTest.pop();
  stackTest.pop();
  
}
