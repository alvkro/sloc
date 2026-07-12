#include <string>
#include <iostream>

int main() {
    std::string url = "https://sigaa.ufrn.br/";    
    std::string aspas = "Ele gritou: \"Cuidado com o // !\" ";
    std::string fake_block = "Isso não é um /* comentário */ de verdade";
    std::cout << url << aspas << fake_block;

    return 0;
}
