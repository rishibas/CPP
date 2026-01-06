#include "FragTrap.hpp"


int main() {
    std::cout << "===== TEST 1: Construction & Destruction Chaining =====" << std::endl;
    {
        // 1. 親(ClapTrap)が先に作られ、その後に子(FragTrap)が作られる様子を確認
        FragTrap frag("frag-01");
        frag.Info();
        
        // 2. スコープを抜ける際、子(FragTrap)が先に壊れ、その後に親(ClapTrap)が壊れる様子を確認
    }
    std::cout << "====================================================\n" << std::endl;

    std::cout << "===== TEST 2: FragTrap Stats & Attack =====" << std::endl;
    {
        FragTrap frag("Guardian");
        
        // ステータスの確認（HP: 100, Energy: 50, Damage: 20）
        std::cout << "Name: " << frag.getName() << " | HP: " << frag.getHitPoints() 
                  << " | Energy: " << frag.getEnergyPoints() << " | Damage: " << frag.getAttackDamage() << std::endl;

        // FragTrap独自のattackメッセージを確認
        frag.attack("Bad Guy");
        
        // ダメージを受けるテスト
        frag.takeDamage(30);
        frag.beRepaired(10);

        frag.Info();
    }
    std::cout << "==========================================\n" << std::endl;

    std::cout << "===== TEST 3: Special Ability (guardGate) =====" << std::endl;
    {
        FragTrap frag("GateKeeper");
        
        // 特殊能力のテスト
        frag.highFivesGuys();
        frag.Info();
    }
    std::cout << "===============================================\n" << std::endl;

    std::cout << "===== TEST 4: Out of Energy Test =====" << std::endl;
    {
        FragTrap frag("TiredRobot");
        
        // エネルギーを使い果たすテスト（本来は50回ループが必要だが、1回でも挙動は同じ）
        // 意図的にHPを0にするなどのテストも有効
        frag.takeDamage(100);
        frag.attack("Target"); // 行動不能のはず
        frag.beRepaired(100); // 行動不能のはず
        frag.highFivesGuys();      // 死亡状態でもガードできるか？（実装次第ですが、一般的にはチェックが必要）
        frag.Info();
    }
    std::cout << "=======================================" << std::endl;

    return 0;
}
