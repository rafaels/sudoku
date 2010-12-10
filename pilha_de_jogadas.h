class PilhaDeJogadas {
  private:
    Jogada * jogadas;
    int qtd;
    void resize_jogadas();

  public:
    PilhaDeJogadas();
    Jogada peek();
    Jogada pop();
    void push(Jogada jogada);
    void empty();
};
