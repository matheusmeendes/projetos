#include "produto.h" //Inclui o arquivo de cabeçalho da classe Produto

class Hash {
 public:
  //Construtor da classe Hash
  Hash(int max_items = 100);
  //Destrutor da classe Hash
  ~Hash();
  //Verifica se a tabela está cheia
  bool isFull() const;
  //Obtém o número de elementos na tabela
  int getLength() const;

  //Recupera um produto da tabela
  void retrieveItem(Produto& produto, bool& found);   
  //Insere um produto na tabela
  void insertItem(Produto produto); 
  //Deleta um produto da tabela
  void deleteItem(Produto produto);  
  //Imprime a tabela
  void print();
 private:
  //Calcula o hash de um produto
  int getHash(Produto produto);

  //Variáveis membros
  int max_items; //Capacidade máxima da tabela
  int length; //Número atual de elementos na tabela
  Produto* structure; //Estrutura de dados para armazenar os produtos
};
