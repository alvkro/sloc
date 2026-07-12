#include <iostream>

const char* query_sql = R"(
    SELECT * FROM tabela
    /* Isso aqui dentro
       não é um comentário C++ */
    WHERE id = 1; // Nem isso
)";

int main() {
    std::cout << "Fim dos testes!\n";
    return 0;
}
