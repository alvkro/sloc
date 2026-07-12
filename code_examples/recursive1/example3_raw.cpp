#include <iostream>
#include <string>

/// esse exemplo foi gerado por IA...

int main() {
    std::string caminho_normal = "C:\\novos_arquivos\\tabelas.csv";
    std::string caminho_raw = R"(C:\novos_arquivos\tabelas.csv)";

    std::cout << "--- Caminhos ---" << std::endl;
    std::cout << "Normal: " << caminho_normal << std::endl;
    std::cout << "Raw:    " << caminho_raw << std::endl;
    std::cout << "\n";

    std::string arquivo_json = R"({
    "usuario": "Maria",
    "profissao": "Engenheira de Software",
    "linguagens": ["C++", "Python"]
})";

    std::cout << "--- Arquivo JSON ---" << std::endl;
    std::cout << arquivo_json << std::endl;

    return 0;
}
