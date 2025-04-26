#include "pwd.hpp"
#include "user.hpp"
#include <iostream>
#include <cassert>

int main() {
    Password password("Wesley le bg");
    User user(1, password);
    assert(password == "Wesley le bg");
    // Petit tips : Evitez de laisser des espaces en début de lignes vides
    // Evidemment cela ne change rien, simplement en plus d'être moins "propre"
    // c'est un signe que le code a très probablement été copié collé.
    std::cout << "OK" << std::endl;

    user.save();

    std::shared_ptr<User> retrieved_user = User::get(1);
    if (retrieved_user->login("gabichou")) {
        std::cout << "Login success" << std::endl;
    } else {
        std::cout << "Login failed" << std::endl;
    }

    return 0;
}
