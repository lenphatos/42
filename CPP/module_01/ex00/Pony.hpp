#ifndef PONY_HPP
# define PONY_HPP



class Pony {

  public:
    //constructeur
     Pony();
     ~Pony();
     Pony(int age, int size, std::string color, std::string name);

    // methodes
    void describe();





  private:
    // atributs
    std::string m_color;
    std::string m_name;
    int         m_size;
    int         m_age;

};

#endif
