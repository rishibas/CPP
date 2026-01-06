#include "Dog.hpp"
#include "Cat.hpp"
#include <iomanip>
#include "Brain.hpp"

int main() {
    // --- 1. Animal配列の作成と削除 (要件：半分Dog、半分Cat) ---
    std::cout << "--- 1. Array of Animals Test ---" << std::endl;
    const int numAnimals = 4;
    Animal* animals[numAnimals];

    for (int i = 0; i < numAnimals; i++) {
        if (i < numAnimals / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "--- Array setup complete, now deleting ---" << std::endl;
    for (int i = 0; i < numAnimals; i++) {
        delete animals[i]; // Animal*型でdeleteし、Dog/Cat -> Brainの順で呼ばれるか
    }

    // // --- 2. ディープコピーの厳格なテスト (Dogを使用) ---
    std::cout << "\n--- 2. Deep Copy and Independence Test ---" << std::endl;
    Dog* dogA = new Dog();
    
    // Brainに特定のアイデアをセット
    dogA->getBrain()->setIdeas(0, "I want a bone");
    
    // コピー作成 (コピーコンストラクタ)
    Dog* dogB = new Dog(*dogA);

    // コピー先のアイデアを確認
    std::cout << "DogA idea[0]: " << dogA->getBrain()->getIdeas(0) << std::endl;
    std::cout << "DogB idea[0]: " << dogB->getBrain()->getIdeas(0) << std::endl;

    // dogAのアイデアを書き換える
    std::cout << "--- Changing DogA's idea ---" << std::endl;
    dogA->getBrain()->setIdeas(0, "I want to sleep");

    // 結果の比較
    std::cout << "DogA idea[0] (updated): " << dogA->getBrain()->getIdeas(0) << std::endl;
    std::cout << "DogB idea[0] (should stay same): " << dogB->getBrain()->getIdeas(0) << std::endl;

    if (dogA->getBrain()->getIdeas(0) != dogB->getBrain()->getIdeas(0)) {
        std::cout << ">> SUCCESS: Deep Copy Confirmed (Independent Brains!)" << std::endl;
    } else {
        std::cout << ">> FAILURE: Shallow Copy (Sharing Brains!)" << std::endl;
    }

    delete dogA;
    std::cout << "--- DogA deleted. Testing DogB's access ---" << std::endl;
    std::cout << "DogB idea[0]: " << dogB->getBrain()->getIdeas(0) << std::endl;
    delete dogB;

    // --- 3. 代入演算子のテスト (Catを使用) ---
    std::cout << "\n--- 3. Assignment Operator Test ---" << std::endl;
    Cat cat1;
    Cat cat;
}
