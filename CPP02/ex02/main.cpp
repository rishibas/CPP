#include "Fixed.hpp"

int main(void) {
    // --- 1. 基本的なコンストラクタと出力のテスト ---
    std::cout << "--- Basic Tests ---" << std::endl;
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    Fixed const c(10);
    Fixed const d(2.5f);

    std::cout << "a is " << a << " (expected 0)" << std::endl;
    std::cout << "b is " << b << " (expected 10.1016...)" << std::endl;
    std::cout << "c is " << c << " (expected 10)" << std::endl;
    std::cout << "d is " << d << " (expected 2.5)" << std::endl;

    // --- 2. 比較演算子のテスト ---
    std::cout << "\n--- Comparison Operators ---" << std::endl;
    std::cout << "c > d : " << (c > d) << " (expected 1)" << std::endl;
    std::cout << "c < d : " << (c < d) << " (expected 0)" << std::endl;
    std::cout << "c >= c : " << (c >= c) << " (expected 1)" << std::endl;
    std::cout << "c <= d : " << (c <= d) << " (expected 0)" << std::endl;
    std::cout << "c == c : " << (c == c) << " (expected 1)" << std::endl;
    std::cout << "c != d : " << (c != d) << " (expected 1)" << std::endl;

    // --- 3. 算術演算子のテスト ---
    std::cout << "\n--- Arithmetic Operators ---" << std::endl;
    std::cout << "c + d : " << (c + d) << " (expected 12.5)" << std::endl;
    std::cout << "c - d : " << (c - d) << " (expected 7.5)" << std::endl;
    std::cout << "c * d : " << (c * d) << " (expected 25)" << std::endl;
    std::cout << "c / d : " << (c / d) << " (expected 4)" << std::endl;
    
    // 割り算の精度テスト (1 / 3)
    Fixed one(1);
    Fixed three(3);
    std::cout << "1 / 3 : " << (one / three) << " (expected ~0.332)" << std::endl;

    // --- 4. インクリメント/デクリメントのテスト ---
    std::cout << "\n--- Increment / Decrement ---" << std::endl;
    Fixed e(0);
    std::cout << "e     : " << e << std::endl;
    std::cout << "++e   : " << ++e << " (pre-increment)" << std::endl;
    std::cout << "e     : " << e << std::endl;
    std::cout << "e++   : " << e++ << " (post-increment)" << std::endl;
    std::cout << "e     : " << e << std::endl;
    
    Fixed f(1);
    std::cout << "--f   : " << --f << " (pre-decrement)" << std::endl;
    std::cout << "f--   : " << f-- << " (post-decrement)" << std::endl;
    std::cout << "f     : " << f << " (should be negative epsilon)" << std::endl;

    // --- 5. min / max (static) のテスト ---
    std::cout << "\n--- Static min / max ---" << std::endl;
    Fixed g(10);
    Fixed h(20);
    std::cout << "min(g, h) : " << Fixed::min(g, h) << " (expected 10)" << std::endl;
    std::cout << "max(g, h) : " << Fixed::max(g, h) << " (expected 20)" << std::endl;

    // Const版のテスト
    Fixed const ci(3.14f);
    Fixed const cj(2.71f);
    std::cout << "const min : " << Fixed::min(ci, cj) << " (expected 2.71)" << std::endl;
    std::cout << "const max : " << Fixed::max(ci, cj) << " (expected 3.14)" << std::endl;
	return 0;
}
