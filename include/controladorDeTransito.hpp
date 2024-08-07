#ifndef CONTROLADORDETRANSITO_HPP
#define CONTROLADORDETRANSITO_HPP

#include <string>
#include <list>
#include "tipoTransporte.hpp"
#include "cidade.hpp"
#include "passageiro.hpp"
#include "trajeto.hpp"
#include "transporte.hpp"
#include "viagem.hpp"

using namespace std;

class ControladorDeTransito{
  private:
    list<Cidade*>listaCidades;
    list<Trajeto*>listaTrajetos;
    list<Transporte*>listaTransportes;
    list<Passageiro*>listaPassageiros;
    list<Viagem*>listaViagens;
  public:
    void cadastrarCidade(string nome);
    void cadastrarTrajeto(string nomeOrigem, string nomeDestino, TipoTransporte tipo, float distancia);
    void cadastrarTransporte(string nome, TipoTransporte tipoDeTrajeto, int capacidade, float velocidade, float distanciaDescansos, int tempoDescanso, string localAtual);
    void cadastrarPassageiro(string nome, string localAtual);

    void iniciarViagem(string nomeTransporte, list<string> nomesPassageiros, string nomeOrigem, string nomeDestino);
    void avancarHoras(int horas);
    void relatarEstado();
    
    // Carregar as informações dos arquivos nas listas
    void carregarCidades();
    void carregarTrajetos();
    void carregarTransportes();
    void carregarPassageiro();
    void carregarViagens();

    bool verificarCidade(string nome);
    bool verificarPassageiro(string nome, string localAtual);
};

#endif
