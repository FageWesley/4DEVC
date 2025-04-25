#include "books.h"
#include <stdio.h>

void eq_function() {
    Person person1 = {50};
    Person person2 = {0};
    int same_age = are_equals(
        &person1, &person2,
        (int (*)(void *, void *)) are_persons_equals
    );
    if (same_age == 1) {printf("Same age.\n");};
}

void linear_search() {
    Person person1 = {50};
    Person people[] = {{20}, {50}};
    int found_person = is_in_array(
        &person1, &people,
        sizeof(people) / sizeof(Person), sizeof(Person),
        (int (*)(void *, void *)) are_persons_equals
    );
    if (found_person == 1) {printf("P1 is in the array.\n");};

    Book book1 = {50};
    Book books[] = {{20}, {50}};
    int found_book = is_in_array(
        &book1, &books,
        sizeof(books) / sizeof(Book), sizeof(Book),
        (int (*)(void *, void *)) are_books_equals
    );
    if (found_book == 1) {printf("B1 is in the array.\n");};
}

void generic_swap() {
    Person person1 = {50};
    Person person2 = {25};
    printf("Before swap: person1 = %d, person2 = %d\n", person1.age, person2.age);
    swap(&person1, &person2, sizeof(Person));
    printf("After swap: person1 = %d, person2 = %d\n", person1.age, person2.age);

    Book b1 = {50};
    Book b2 = {25};
    printf("Before swap: book1 = %d, book2 = %d\n", b1.pages, b2.pages);
    swap(&b1, &b2, sizeof(Book));
    printf("After swap: book1 = %d, book2 = %d\n", b1.pages, b2.pages);
}


int compare_persons(void *p1, void *p2) {
    return ((Person *)p1)->age > ((Person *)p2)->age;
}
// Une autre façon de comparer serait par exemple de renvoyer
// 1 si p1 est plus grand, -1 si p2 est plus grand et 0 si ils sont égaux.


int main() {
    eq_function();
    linear_search();
    generic_swap();

    Person people[] = {{20}, {50}, {188}, {2}};

    printf("Before sorted: ");
    for (int i = 0; i < sizeof(people) / sizeof(Person); i++) {
        printf("%d ", people[i].age);
    }
    printf("\n");
    
    sort(
        &people,
        sizeof(people) / sizeof(Person),
        sizeof(Person),
        compare_persons,
        swap
    );

    

    printf("Sorted people by age: ");
    for (int i = 0; i < sizeof(people) / sizeof(Person); i++) {
        printf("%d ", people[i].age);
    }


    // On peut éventuellement itérer sur les objets via leurs pointeurs
    // Un peu comme un foreach en JS ou for elem in elems en Python :
    for (Person *p = people; p < people + sizeof(people) / sizeof(Person); p++) {
        printf("%d ", p->age);
    }
    // Ici p est un pointeur vers le début du tableau
    // people + sizeof(people) / sizeof(Person) est également un pointeur, mais vers la fin du tableau
    // On l'incrémente donc p de la taille d'un élément du tableau (p++) pointant alors vers le suivant
    // et ce jusqu'à ce qu'il soit égal au pointeur vers la fin du tableau

    // C'est à titre d'exemple et pour montrer le fonctionnement des équivalents en C++, JS etc
    // Dans du code en production on évite souvent car un peu plus compliqué à lire / maintenir
    // et peut donc être source d'erreurs.

    printf("\n");

    return 0;
}
