#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP



class Zombie {

  public:
    //constructeur
     Zombie();
     Zombie(std::string name, std::string type);
     ~Zombie();

    // methodes
    void announce();
    void setType(std::string type);
    void setName(std::string name);
    std::string getType(void);
    std::string getName(void);




  private:
    // atributs
    std::string m_name;
    std::string m_type;

};

#endif
