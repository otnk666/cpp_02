/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 21:25:51 by skomatsu          #+#    #+#             */
/*   Updated: 2026/01/05 22:40:13 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>

#include "Fixed.hpp"

// プロトタイプ宣言
void runSubjectTest();
void testComparisons();
void testArithmetic();
void testIncrementDecrement();
void testMinMax();

int main(void)
{
    // 課題で指定された必須テスト
    runSubjectTest();

    // 追加の詳細テスト
    std::cout << "\n=========================================" << std::endl;
    std::cout << "Running Detailed Tests..." << std::endl;
    std::cout << "=========================================" << std::endl;

    testComparisons();
    testArithmetic();
    testIncrementDecrement();
    testMinMax();

    return 0;
}

// 課題(Subject)に記載されているオリジナルのテストケース
void runSubjectTest()
{
    std::cout << "--- Original Subject Test ---" << std::endl;

    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << Fixed::max(a, b) << std::endl;
}

/*

$> ./a.out
0
0.00390625
0.00390625
0.00390625
0.0078125
10.1016
10.1016

*/

// 比較演算子のテスト
void testComparisons()
{
    std::cout << "\n[Testing Comparison Operators]" << std::endl;
    Fixed a(10.5f);
    Fixed b(10.5f);
    Fixed c(5.05f);

    // true/false で表示させる設定
    std::cout << std::boolalpha;

    std::cout << "a(" << a << ") == b(" << b << "): " << (a == b) << std::endl;
    std::cout << "a(" << a << ") != b(" << b << "): " << (a != b) << std::endl;
    std::cout << "a(" << a << ") >  c(" << c << "): " << (a > c) << std::endl;
    std::cout << "a(" << a << ") <  c(" << c << "): " << (a < c) << std::endl;
    std::cout << "a(" << a << ") >= b(" << b << "): " << (a >= b) << std::endl;
    std::cout << "a(" << a << ") <= c(" << c << "): " << (a <= c) << std::endl;

    // 設定を戻す（必要に応じて）
    std::cout << std::noboolalpha;
}

// 算術演算子のテスト
void testArithmetic()
{
    std::cout << "\n[Testing Arithmetic Operators]" << std::endl;
    Fixed a(12.5f);
    Fixed b(2.5f);

    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "a + b = " << (a + b) << std::endl;
    std::cout << "a - b = " << (a - b) << std::endl;
    std::cout << "a * b = " << (a * b) << std::endl;
    std::cout << "a / b = " << (a / b) << std::endl;
}

// インクリメント・デクリメントのテスト
void testIncrementDecrement()
{
    std::cout << "\n[Testing Increment/Decrement]" << std::endl;
    Fixed a(42.42f);

    std::cout << "Original:  " << a << std::endl;
    std::cout << "Pre-Inc:   " << ++a << " (Expected: 42.42 + epsilon)"
              << std::endl;
    std::cout << "Current:   " << a << std::endl;
    std::cout << "Post-Inc:  " << a++ << " (Expected: same as Current)"
              << std::endl;
    std::cout << "Current:   " << a << " (Expected: incremented)" << std::endl;

    std::cout << "Pre-Dec:   " << --a << std::endl;
    std::cout << "Post-Dec:  " << a-- << std::endl;
    std::cout << "Final:     " << a << std::endl;
}

// min/max関数のテスト
void testMinMax()
{
    std::cout << "\n[Testing Min/Max Functions]" << std::endl;

    // 通常の変数
    Fixed a(100.1f);
    Fixed b(200.2f);
    std::cout << "Fixed:       min(" << a << ", " << b
              << ") = " << Fixed::min(a, b) << std::endl;
    std::cout << "Fixed:       max(" << a << ", " << b
              << ") = " << Fixed::max(a, b) << std::endl;

    // const 変数
    const Fixed c(300.3f);
    const Fixed d(400.4f);
    std::cout << "Const Fixed: min(" << c << ", " << d
              << ") = " << Fixed::min(c, d) << std::endl;
    std::cout << "Const Fixed: max(" << c << ", " << d
              << ") = " << Fixed::max(c, d) << std::endl;
}
