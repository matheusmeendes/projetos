#include "hash.h" 
#include <iostream>
using namespace std;

//Construtor da classe Hash
Hash::Hash(int max) {  
  length = 0; //Inicializa o número de elementos como zero
  max_items = max; //Define o número máximo de elementos na tabela
  structure = new Produto[max_items]; //Aloca memória para a estrutura de dados
}

//Destrutor da classe Hash
Hash::~Hash(){
  delete [] structure; //Libera a memória alocada para a estrutura de dados
}

//Verifica se a tabela está cheia
bool Hash::isFull() const {
  return (length == max_items); //Retorna verdadeiro se o número de elementos for igual ao número máximo de elementos
}

//Obtém o número de elementos na tabela
int Hash::getLength() const {
  return length; //Retorna o número de elementos na tabela
}

//Recupera um produto da tabela
void Hash::retrieveItem(Produto& produto, bool& found) {
  int startLoc = getHash(produto); //Calcula o hash do produto
  bool moreToSearch = true; 
  int location = startLoc;
  //Realiza busca linear até encontrar o produto ou encontrar uma posição vazia (-1)
  do {
    if (structure[location].getPreco() == produto.getPreco() ||
  structure[location].getPreco() == -1)
      moreToSearch = false;
    else
      location = (location + 1) % max_items;
  } while (location != startLoc && moreToSearch);

  found = (structure[location].getPreco() == produto.getPreco() ); //Verifica se o produto foi encontrado
  if (found) { 
    produto = structure[location]; //Retorna o produto encontrado
  }
}

//Insere um produto na tabela
void Hash::insertItem(Produto produto) {
  int location;
  location = getHash(produto); //Calcula o hash do produto
  while (structure[location].getPreco() > 0) //Encontra a próxima posição vazia na tabela
    location = (location + 1) % max_items;
  structure[location] = produto; //Insere o produto na posição encontrada
  length++; //Incrementa o número de elementos na tabela
}

//Remove um produto da tabela
void Hash::deleteItem(Produto produto) {
  int startLoc = getHash(produto); //Calcula o hash do produto
  bool moreToSearch = true; 
  int location = startLoc;
  //Realiza busca linear até encontrar o produto ou encontrar uma posição vazia (-1)
  do {
    if (structure[location].getPreco() == produto.getPreco() ||
  structure[location].getPreco() == -1)
      moreToSearch = false;
    else
      location = (location + 1) % max_items;
  } while (location != startLoc && moreToSearch);

  if (structure[location].getPreco() == produto.getPreco()) { //Verifica se o produto foi encontrado
    structure[location] = Produto(-2,""); //Marca a posição como vazia
    length--; //Decrementa o número de elementos na tabela
  }
}

//Imprime todos os produtos na tabela
void Hash::print() {
  for (int i = 0; i < max_items; i++) {
    cout << i << ":" << structure[i].getPreco() << ", " << structure[i].getProduto() << endl; //Imprime o preço e o produto
  }
}

//Calcula o hash do produto
int Hash::getHash(Produto produto){
  return produto.getPreco() % max_items; //Retorna o resultado da divisão do preço do produto pelo número máximo de elementos na tabela
}
