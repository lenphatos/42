#ifndef BRAIN_HPP
# define BRAIN_HPP



class Brain {

  public:
    //constructeur
     Brain();
     ~Brain();

    // methodes
    std::string identify();
    void setQI(int qi);
    void setAge(int age);
    int getQI(void);
    int getAge(void);




  private:
    // atributs
    int   m_nbQi;
    int   m_age;

};

#endif
