#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main() {
    std::cout << "--- 正常なテスト (Polymorphism) ---" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    j->makeSound(); // Dogの音
    i->makeSound(); // Catの音
    meta->makeSound(); // Animalの音

    delete meta;
    delete j;
    delete i;

    std::cout << "\n--- 失敗のテスト (Wrong Classes) ---" << std::endl;
	const WrongAnimal *wrongAnimal = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    std::cout << wrongCat->getType() << " " << std::endl;
    wrongCat->makeSound(); // ここで WrongAnimal の音が出ることを確認！
	wrongAnimal->makeSound();
	delete wrongAnimal;
    delete wrongCat; // WrongCatのデストラクタが呼ばれないことを確認

    return 0;
}
