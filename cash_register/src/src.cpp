// standar library
#include <iostream>
#include <cstring>
#include "header.h"
#include <stack> 
#include <bits/stdc++.h> 
#include <stdlib.h>

CashRegister::CashRegister(){
  this->currentClient.isPartner = false; 
  this->discount = 5;
}

float CashRegister::getShoppingCartPrice(){

  float amount = 0;
  std::stack<Product> tmpStore = this->store; 

  while (!tmpStore.empty())
  {
    Product tmpProduct = tmpStore.top();
    tmpStore.pop();
    amount += tmpProduct.quantity * tmpProduct.price;
  }

  if(this->currentClient.isPartner){
    amount = amount - this->getDiscount(amount);
  }

  return amount;
}

float CashRegister::getDiscount(float amount){
  return this->discount > 100 ||  this->discount <= 0 ?  
            0.05 * amount : 
            (this->discount / 100 ) * amount;
}

bool CashRegister::setProductCart(Product product){
    this->store.push(product);
    // tells me when the product is register
    return true;
}

int CashRegister::getQuantityProduct(){
  // maybe i should return the empty directly? e.e
  return this->store.empty() ? 0 : this->store.size();
}

std::stack<Product> CashRegister::getShoppingCarList(){
  return this->store;
}

void CashRegister::setClient(Client client){
  this->currentClient = client;
}

Client CashRegister::getCurrentClient(){
  return this->currentClient;
}


ProductStore::ProductStore(){
  Product p1, p2, p3, p4, p5;

  strcpy(p1.name, "Jamon"); 
  strcpy(p2.name, "Queso"); 
  strcpy(p3.name, "Tomates"); 
  strcpy(p4.name, "Cervezas"); 
  strcpy(p5.name, "Pan"); 

  p1.price = 10;
  p2.price = 20;
  p3.price = 15;
  p4.price = 8;
  p5.price = 10;
 
  this->store[0] = p1;
  this->store[1] = p2;
  this->store[2] = p3;
  this->store[3] = p4;
  this->store[4] = p5;

  this->storeSize = 5;

}

Product* ProductStore::getStore(){
  return this->store;
}

Product ProductStore::getProductFromTheStore(int index){
  return index > 6 || index < 1 ? this->store[0] : this->store[index - 1];
}

int ProductStore::getStoreSize(){
  return this->storeSize;
}



//  ------------- app ------------------------

void app(ProductStore *store, CashRegister *cashRegister, Client *client){
  registerClient(client, cashRegister);
  appMenu(store, cashRegister, client);
}


void appMenu(ProductStore *store, CashRegister *cashRegister, Client *client){
 if (system("CLS")) system("clear");
  int menu;
  printfStoreInProductStore(store->getStore(), store->getStoreSize());
  std::cout<<"-----------Menu-------------"<<"\n";
  std::cout<<"1 -- Add a product to cart"<<"\n";
  std::cout<<"2 -- See Shopping Car"<<"\n";
  std::cout<<"3 -- See Client data"<<"\n";
  std::cout<<"4 -- cancel purchase"<<"\n\n";
  std::cout<<"Select an opcion: ";
  std::cin>>menu;
  switch (menu)
  {
  case 1:
    selectProductFromList(store, cashRegister, client);
    break;
  case 2:
    appShoppingCar(store, cashRegister, client);
    break;
  case 3:
    appClientData(cashRegister, client, store);
    break;
  case 4:
    std::cout<<"Good bye"<<"\n";
  default:
    break;
  }
}


void appShoppingCar(ProductStore *store, CashRegister *cashRegister, Client *client){
  if (system("CLS")) system("clear");
  int selectOption;

  std::cout<<"---- My shopping car ----"<<"\n\n";
  printfCarShoppingList(cashRegister->getShoppingCarList());
  std::cout<<"Total: "<<cashRegister->getShoppingCartPrice()<<" Bs\n";

  std::cout<<"\n1-- go back to menu "<<"\n";
  std::cout<<"2-- Buy "<<"\n";
  std::cout<<"3-- cancel purchase "<<"\n";
  std::cout<<"Select an opcion: ";
  std::cin>>selectOption;

  switch (selectOption)
  {
    case 1:
      appMenu(store, cashRegister, client);
      break;
    case 2:
      appBuyProducts(store, cashRegister);
      break;
    default:
      break;
  }
}

void appBuyProducts(ProductStore *store, CashRegister *cashRegister){
  if (system("CLS")) system("clear");
  std::cout<<"----------- acquittance -------------"<<"\n\n";
  printfCarShoppingList(cashRegister->getShoppingCarList());
  std::cout<<"\nTotal: "<<cashRegister->getShoppingCartPrice()<<" Bs \n\n";
  std::cout<<"--- Thanks for your purchase --------"<<"\n";
}

void appClientData(CashRegister *cashRegister, Client *client, ProductStore *store){
  if (system("CLS")) system("clear");
  int selectOption;
  std::cout<<"     My personal data      "<<"\n\n";
  std::cout<<"First Name: "<<cashRegister->getCurrentClient().name<<"\n";
  std::cout<<"Last Name: "<<cashRegister->getCurrentClient().lastName<<"\n";
  if(cashRegister->getCurrentClient().isPartner){
    std::cout<<"Client status: Partner"<<"\n";
  }else{
    std::cout<<"Client status: common"<<"\n";
  }

  std::cout<<"\n1-- go back to menu "<<"\n";
  std::cout<<"2-- cancel purchase "<<"\n";
  std::cout<<"Select an opcion: ";
  std::cin>>selectOption;

  switch (selectOption)
  {
    case 1:
      appMenu(store, cashRegister, client);
      break;
    default:
      break;
  }
}



void registerClient(Client *client, CashRegister *cashRegister){
  if (system("CLS")) system("clear");
  char selectOpction;
  std::cout<<"-----Welcome to Garzon-----"<<"\n";
  std::cout<<"    Cash Register Program  "<<"\n\n";
  std::cout<<"What is your name? ";
  std::cin>>client->name;
  std::cout<<"What is your last name? ";
  std::cin>>client->lastName;
  std::cout<<"Are you a partner? Y/n ";
  std::cin>>selectOpction;
  switch (selectOpction)
  {
    case 'y':
      client->isPartner = true;
      break;
    case 'Y':
      client->isPartner = true;
      break;
    case 'n':
      client->isPartner = false;
      break;
    case 'N':
      client->isPartner = false;
      break;
    default:
      
      break;
  }
  cashRegister->setClient(*client);
}

void getClientData(Client *client){
  char isPartner;
  std::cout<<"Welcome to garzon cash shopping"<<'\n';
  std::cout<<"What is your name?"<<"\n";
  std::cin>>client->name;
  std::cout<<"What is your last name?"<<'\n';
  std::cin>>client->lastName;
  std::cout<<"are you a partner? Y/n"<<'\n';
  std::cin>>isPartner;
  switch (isPartner)
  {
  case 'y':
    client->isPartner = true;
    break;
  case 'Y':
    client->isPartner = true;
    break;
  default:
    break;
  }
}

void selectProductFromList(ProductStore *store, CashRegister *cashRegister, Client *client){
  if (system("CLS")) system("clear");
  int selectIndex = 0;
  int endOpcionSelect;
  Product selectProduct;

  std::cout<<"----Product List in Garzon----"<<"\n\n";
  printfStoreInProductStore(store->getStore(), store->getStoreSize());
  std::cout<<"--------------------------------------------\n";
  std::cout<<"-Enter the product id that you want to buy: ";
  std::cin>>selectIndex;

  selectProduct = store->getProductFromTheStore(selectIndex);
  std::cout<<"-How may "<<selectProduct.name<<" do you want to buy? ";
  std::cin>>selectProduct.quantity;
  cashRegister->setProductCart(selectProduct);



  std::cout<<"1-- Add other product to cart "<<"\n";
  std::cout<<"2-- go back to menu "<<"\n\n";
  std::cout<<"Select an opcion: ";
  std::cin>>endOpcionSelect;
  std::cout<<"--------------------------------------------\n";

  switch (endOpcionSelect)
  {
    case 1:
      selectProductFromList(store, cashRegister, client);
      break;
    case 2:
      appMenu(store, cashRegister, client);
      break;
    default:
      std::cout<<"Good bye"<<"\n";
      break;
  }
}


void printfCarShoppingList(std::stack <Product> s) 
{    

    if(!s.empty())
    {
      std::cout<<"Quantity  /  Product  /  Price"<<"\n";
      while (!s.empty()) 
      { 
          std::cout<<s.top().quantity<<"x             "; 
          std::cout<<s.top().name<<"        ";
          std::cout<<s.top().price<<'\n'; 
          s.pop(); 
      } 
    }
    else
    {
      std::cout<<"you have not selected a product yet"<<"\n";
    }
} 

void printfStoreInProductStore(Product *store, int size){
 std::cout<<"Product Id / Product Name"<<"\n";
  for (size_t i = 0; i < size; i++)
  {
    std::cout<<(i + 1)<<" "<<store[i].name<<"\n";
  }
}








