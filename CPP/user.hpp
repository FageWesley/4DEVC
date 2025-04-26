#ifndef USER_HPP
#define USER_HPP

#include "pwd.hpp"
#include <memory>

class User {
private:
    int id;
    std::shared_ptr<Password> password;
    bool is_logged_in;

public:
    User(int id, Password password);

    int login(const char *raw_password);
    void save();
    static std::shared_ptr<User> get(int id);

    User(const User&) = delete;
    User& operator=(const User&) = delete;
};

#endif
// Essayez d'être le plus consistant possible dans les noms de variables.
// Si on part en mettant des _ devant les variables privées comme dans pwd.hpp
// on le fait partout.
