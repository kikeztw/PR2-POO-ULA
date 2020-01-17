#include <iostream>
#include <stdlib.h>

template <typename N>
struct Node
{ 
    N value;  
    Node *next; 
};


template <typename S>
class Tails{

  Node<S> *index = NULL;
  Node<S> *lastIndex = NULL;

  public:
    void add(S);
};
  
template <typename S>
void Tails<S>::add(S value){
  
  Node<S> *newNode = new Node<S>();
  newNode->value = value;
  newNode->next = NULL;
  if(this->index == NULL){
    this->index = newNode;
  }else{
    this->lastIndex->next = newNode;
  }
  this->lastIndex = newNode;
}


int main(){
  Tails<char> tails;
  char a = 'a', b = 'b';

  tails.add(a);
  tails.add(b);
  
}
