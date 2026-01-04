#include"ClapTrap.hpp"

void	showPlayerInfo(ClapTrap &player){
    std::cout << std::endl;
	std::cout << "名前: " << player.getName() << std::endl;
	std::cout << "ヒットポイント: " << player.getHitPoints() << std::endl;
	std::cout << "エネルギーポイント" << player.getEnergyPoints() << std::endl;
	std::cout << "アタックダメージ: " << player.getAttackDamage() << std::endl;
}

int main(){
    std::cout << "--- Player Info ---" << std::endl;
    {
        ClapTrap player;
        showPlayerInfo(player);
    }

    std::cout << std::endl;
	std::cout << "--- Test 1: 基本的な動作（攻撃と修理） ---" << std::endl;
    {
        ClapTrap clappy("CL4P-TP");
        clappy.attack("Target-A");    // Energy: 10 -> 9
        clappy.takeDamage(5);         // HP: 10 -> 5
        clappy.beRepaired(3);         // HP: 5 -> 8, Energy: 9 -> 8
        showPlayerInfo(clappy);
    }

    std::cout << "\n--- Test 2: エネルギー切れのテスト ---" << std::endl;
    {
        ClapTrap lowEnergy("Weakling");
        // エネルギー10を使い切るまで攻撃
        for (int i = 0; i < 10; i++) {
            lowEnergy.attack("Target-B");
        }
        // 11回目は失敗するはず
        lowEnergy.attack("Target-B");
        lowEnergy.beRepaired(5);
        showPlayerInfo(lowEnergy);
    }

    std::cout << "\n--- Test 3: HP切れ（死亡状態）のテスト ---" << std::endl;
    {
        ClapTrap fragile("Glass-Joe");
        fragile.takeDamage(10);        // HP: 0
        fragile.attack("Target-C");    // 行動不能なはず
        fragile.beRepaired(1);         // 行動不能なはず
        showPlayerInfo(fragile);
    }

    std::cout << "\n--- Test 4: 過剰なダメージのテスト ---" << std::endl;
    {
        ClapTrap tank("Tank-Guy");
        tank.takeDamage(50);           // HPを大幅に超えるダメージ
        tank.beRepaired(10);           // 復活できないはず
        showPlayerInfo(tank);
    }

    return 0;
}
