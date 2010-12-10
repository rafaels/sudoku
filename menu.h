class Menu {
  private:
    Jogo * jogo;
    bool validate_entrada(int linha, int coluna, int numero);
  public:
    Menu(Jogo * novo_jogo);
    void mostrar();
    void trata_entrada(string entrada);
    void mostrar_msg_de_vencedor();
};
