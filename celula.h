class Celula {
  private:
    int value;
    bool is_constant_flag;
  public:
    Celula();
    Celula(int new_value);
    int get_value();
    void set_value(int new_value);
    bool is_constant();
};

