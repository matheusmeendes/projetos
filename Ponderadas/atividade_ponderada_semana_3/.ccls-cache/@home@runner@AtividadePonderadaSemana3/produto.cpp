#include "produto.h" //Inclui o arquivo de cabeçalho da classe Produto

//Implementação do construtor padrão da classe Produto
Produto::Produto() {
  this->preco = -1; //Define o preço como -1 (indicando valor inválido)
  this->produto = ""; //Define o nome do produto como uma string vazia
}

//Implementação do construtor da classe Produto com parâmetros
Produto::Produto(int preco, std::string produto) {
  this->preco = preco; //Define o preço conforme o parâmetro recebido
  this->produto = produto; //Define o nome do produto conforme o parâmetro recebido
}

//Implementação do método getProduto(), que retorna o nome do produto
std::string Produto::getProduto() const {
  return produto; //Retorna o nome do produto
}

//Implementação do método getPreco(), que retorna o preço do produto
int Produto::getPreco() const {
  return preco; //Retorna o preço do produto
}
