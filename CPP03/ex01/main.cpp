#include "ScavTrap.hpp"


int main() {
    std::cout << "===== TEST 1: Construction & Destruction Chaining =====" << std::endl;
    {
        // 1. 親(ClapTrap)が先に作られ、その後に子(ScavTrap)が作られる様子を確認
        ScavTrap scav("SCAV-01");
        scav.Info();
        
        // 2. スコープを抜ける際、子(ScavTrap)が先に壊れ、その後に親(ClapTrap)が壊れる様子を確認
    }
    std::cout << "====================================================\n" << std::endl;

    std::cout << "===== TEST 2: ScavTrap Stats & Attack =====" << std::endl;
    {
        ScavTrap scav("Guardian");
        
        // ステータスの確認（HP: 100, Energy: 50, Damage: 20）
        std::cout << "Name: " << scav.getName() << " | HP: " << scav.getHitPoints() 
                  << " | Energy: " << scav.getEnergyPoints() << " | Damage: " << scav.getAttackDamage() << std::endl;

        // ScavTrap独自のattackメッセージを確認
        scav.attack("Bad Guy");
        
        // ダメージを受けるテスト
        scav.takeDamage(30);
        scav.beRepaired(10);

        scav.Info();
    }
    std::cout << "==========================================\n" << std::endl;

    std::cout << "===== TEST 3: Special Ability (guardGate) =====" << std::endl;
    {
        ScavTrap scav("GateKeeper");
        
        // 特殊能力のテスト
        scav.guardGate();
        scav.Info();
    }
    std::cout << "===============================================\n" << std::endl;

    std::cout << "===== TEST 4: Out of Energy Test =====" << std::endl;
    {
        ScavTrap scav("TiredRobot");
        
        // エネルギーを使い果たすテスト（本来は50回ループが必要だが、1回でも挙動は同じ）
        // 意図的にHPを0にするなどのテストも有効
        scav.takeDamage(100);
        scav.attack("Target"); // 行動不能のはず
        scav.beRepaired(100); // 行動不能のはず
        scav.guardGate();      // 死亡状態でもガードできるか？（実装次第ですが、一般的にはチェックが必要）
        scav.Info();
    }
    std::cout << "=======================================" << std::endl;

    return 0;
}
