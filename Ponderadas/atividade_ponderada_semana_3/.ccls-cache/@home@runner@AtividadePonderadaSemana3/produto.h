#include <iostream> //Inclui a biblioteca para entrada/saída padrão
using namespace std; //Usa o namespace std para evitar a necessidade de escrever std:: antes de cada uso

//Definição da classe Produto
class Produto {
private:
  int preco; //Variável membro para armazenar o preço do produto
  std::string produto; //Variável membro para armazenar o nome do produto

public:
  //Protótipo do construtor padrão da classe Produto
  Produto();

  //Protótipo do construtor da classe Produto com parâmetros
  Produto(int preco, std::string produto);

  //Protótipo do método para obter o nome do produto
  std::string getProduto() const;

  //Protótipo do método para obter o preço do produto
  int getPreco() const;
};
