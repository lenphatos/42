#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

class Zombie {

  public:
    //constructeur
     Zombie();
     Zombie(std::string name, std::string type);
     ~Zombie();

    // methodes
    void advert();




  private:
    // atributs
    std::string m_name;
    std::string m_type;

};

#endif
