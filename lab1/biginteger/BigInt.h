//
// Created by Maxim on 05.09.2022.
//

#ifndef LAB1_BIGINT_H
#define LAB1_BIGINT_H
#include <string>
#include <vector>

static const int kBase = 1000000000;
static const int kMaxDigitLen = 9;

class BigInt {

private:
  bool is_negative;
  std::vector<int> digits;
public:
  BigInt();
  BigInt(int);
  BigInt(std::string); // бросать исключение std::invalid_argument при ошибке
  BigInt(const BigInt &);
  ~BigInt();
  bool IsSignNegative();
  std::vector<int> GetDigits();
};

#endif // LAB1_BIGINT_H
