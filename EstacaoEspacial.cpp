#include "EstacaoEspacial.hpp"
#include <iostream>
#include <fstream>
#include <sstream>


EstacaoEspacial::EstacaoEspacial(int linhas, int colunas) : linhas(linhas), colunas(colunas) {
    matriz.resize(linhas, std::vector<Modulo*>(colunas, nullptr));
}


EstacaoEspacial::~EstacaoEspacial() {
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            delete matriz[i][j];
        }
    }
}


void EstacaoEspacial::inicializarEstacao(const std::string& arquivo) {
    std::ifstream file(arquivo);
    if (!file.is_open()) {
        throw std::runtime_error("Erro ao abrir o arquivo!");
    }

    std::string line;
    
    // Lê a primeira linha do arquivo (tamanho da matriz)
    if (!std::getline(file, line)) {
        throw std::runtime_error("Erro: Arquivo vazio ou leitura incorreta da primeira linha.");
    }

    std::stringstream ss(line);
    if (!(ss >> linhas >> colunas)) {
        throw std::runtime_error("Erro: Formato incorreto ao ler as dimensões da matriz.");
    }

    matriz.resize(linhas, std::vector<Modulo*>(colunas, nullptr));

    // Lê os dados da matriz
    for (int i = 0; i < linhas; ++i) {
        if (!std::getline(file, line)) {
            throw std::runtime_error("Erro: Linhas da matriz insuficientes.");
        }

        for (int j = 0; j < colunas; ++j) {
            if (j >= line.size()) continue;
            char tipo = line[j];

            switch (tipo) {
                case 'S': matriz[i][j] = new ModuloSeguranca(); break;
                case 'A': matriz[i][j] = new ModuloAstronauta(); break;
                case '#': matriz[i][j] = new ModuloObstaculo(); break;
                case '~': matriz[i][j] = new ModuloVazio(); break;
                case 'F': matriz[i][j] = new ModuloFogo(); break;
                case '.': matriz[i][j] = new ModuloNormal(); break;
                case '-': matriz[i][j] = new ModuloRastro(); break;
                default: 
                    throw std::runtime_error("Erro: Caractere inválido encontrado na matriz.");
            }
        }
    }

    // Lê os astronautas
    if (!std::getline(file, line) || line != "Astronautas:") {
        throw std::runtime_error("Erro: Cabeçalho 'Astronautas:' não encontrado.");
    }

    std::vector<std::string> nomesAstronautas;
    std::vector<int> saudes;
    std::vector<bool> urgencias;

    while (std::getline(file, line) && !line.empty() && line != "Posições dos astronautas na matriz:") {
        std::stringstream ss(line);
        std::string nome;
        int saude, urgente;

        if (std::getline(ss, nome, ',') && ss >> saude && ss.ignore() && ss >> urgente) {
            nomesAstronautas.push_back(nome);
            saudes.push_back(saude);
            urgencias.push_back(urgente);
        } else {
            throw std::runtime_error("Erro ao ler informações dos astronautas.");
        }
    }

    // Lê as posições dos astronautas
    if (line != "Posições dos astronautas na matriz:") {
        throw std::runtime_error("Erro: Cabeçalho 'Posições dos astronautas na matriz:' não encontrado.");
    }

    int index = 0;
    while (std::getline(file, line) && index < nomesAstronautas.size()) {
        std::stringstream ss(line);
        std::string nome;
        char lixo;
        int x, y;

        if (std::getline(ss, nome, ':') && ss >> lixo >> x >> lixo >> y >> lixo) {
            if (index < nomesAstronautas.size()) {
                adicionarAstronauta(Astronauta(nomesAstronautas[index], saudes[index], urgencias[index], x, y));
                index++;
            }
        } else {
            throw std::runtime_error("Erro ao ler posição dos astronautas.");
        }
    }
}


void EstacaoEspacial::mostrarEstacao() const {
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            std::cout << matriz[i][j]->getTipo() << " ";
        }
        std::cout << std::endl;
    }
}


bool EstacaoEspacial::podeAcessar(int linha, int coluna) const {
    if (linha >= 0 && linha < linhas && coluna >= 0 && coluna < colunas) {
        return matriz[linha][coluna]->podeAcessar();
    }
    return false;
}


void EstacaoEspacial::adicionarAstronauta(const Astronauta& astro) {
    astronautas.push_back(astro);
}


void EstacaoEspacial::removerAstronauta(const std::string& nome) {
    for (auto it = astronautas.begin(); it != astronautas.end(); ++it) {
        if (it->getNome() == nome) {
            astronautas.erase(it);
            return;
        }
    }
}


std::vector<Astronauta> EstacaoEspacial::getAstronautas() const {
    return astronautas;
}


void EstacaoEspacial::mostrarAstronautas() const {
    std::cout << "Astronautas na estação:\n";
    for (const auto& astro : astronautas) {
        std::cout << "- " << astro.getNome() << " | Saúde: " << astro.getSaude()
                  << " | Atendimento Urgente: " << (astro.precisaAtendimentoUrgente() ? "Sim" : "Não")
                  << " | Posição: (" << astro.getX() << ", " << astro.getY() << ")\n";
    }
}


int EstacaoEspacial::getLinhas() const {
    return linhas;
}


int EstacaoEspacial::getColunas() const {
    return colunas;
}

Modulo* EstacaoEspacial::getModulo(int x, int y) const {
    if (x < 0 || x >= linhas || y < 0 || y >= colunas) {
        return nullptr; // Fora dos limites
    }
    return matriz[x][y]; // Retorna o módulo da posição
}
