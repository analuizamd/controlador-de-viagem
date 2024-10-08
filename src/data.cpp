#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "../include/controladorDeTransito.hpp"


using namespace std;

void ControladorDeTransito::carregarCidades()
{
  ifstream arquivo("data/cidade.txt");
  string linha;
  if(arquivo.is_open())
  {
    while(getline(arquivo, linha))
    {
      if(!linha.empty())
      {
        Cidade* novaCidade = new Cidade(linha);
        listaCidades.push_back(novaCidade);
      }
    }
  }
}

void ControladorDeTransito::carregarTransportes()
{
  ifstream arquivo("data/transporte.txt");
  string linha;
  if(arquivo.is_open())
  {
    while(getline(arquivo, linha))
    {
      istringstream xx(linha);
      string nome, localAtualS, entrada;
      int tipo, capacidade, distanciaDescansos, tempoDescanso;
      float velocidade;
      bool emTransito;

      Cidade* localAtual = nullptr;

      getline(xx, nome, ',');
      xx >> tipo;
      xx.ignore();
      xx >> capacidade;
      xx.ignore();
      xx >> velocidade;
      xx.ignore();
      xx >> distanciaDescansos;
      xx.ignore();
      xx >> tempoDescanso;
      xx.ignore();
      getline(xx, localAtualS, ',');
      getline(xx, entrada);
      if(entrada == "false")
      {
        emTransito = false;
      }
      else if(entrada == "true")
      {
        emTransito = true;
      }

      localAtual = new Cidade(localAtualS);

      Transporte* trajetoArquivo = new Transporte(nome, tipo, capacidade, velocidade, distanciaDescansos, tempoDescanso, localAtual, emTransito);

      listaTransportes.push_back(trajetoArquivo);
    }
  }
}

void ControladorDeTransito::carregarPassageiros()
{
  ifstream arquivo("data/passageiro.txt");
  string linha;
  if(arquivo.is_open())
  {
    while(getline(arquivo, linha)){
      istringstream xx(linha);
      string nome, localAtualS, entrada;
      bool emTransito;

      getline(xx, nome, ',');
      getline(xx, localAtualS, ',');
      getline(xx, entrada);
      if(entrada == "false")
      {
        emTransito = false;
      }
      else if(entrada == "true")
      {
        emTransito = true;
      }
      Cidade* localAtual = new Cidade(localAtualS);

      Passageiro* passageiroArquivo = new Passageiro(nome, localAtual, emTransito);

      listaPassageiros.push_back(passageiroArquivo);
    }
  }
}

void ControladorDeTransito::carregarTrajetos()
{
  ifstream arquivo("data/trajeto.txt");
  string linha;
  if(arquivo.is_open())
  {
    while(getline(arquivo, linha)){
      istringstream xx(linha);
      string origemS, destinoS;
      int tipo;
      float distancia;

      getline(xx, origemS, ',');
      getline(xx, destinoS, ',');
      xx >> tipo;
      xx.ignore();
      xx >> distancia;

      Cidade* origem = new Cidade(origemS);
      Cidade* destino = new Cidade(destinoS);

      Trajeto* TrajetoArquivo = new Trajeto(origem, destino, tipo, distancia);

      listaTrajetos.push_back(TrajetoArquivo);
    }
  }
}
