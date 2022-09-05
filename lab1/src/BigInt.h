//
// Created by Maxim on 05.09.2022.
//

#ifndef LAB1_BIGINT_H
#define LAB1_BIGINT_H
#include <string>
#include <vector>

class BigInt {

private:
  bool sign;
  std::vector<int> digits;
public:
  BigInt();
  BigInt(int);
  BigInt(std::string); // бросать исключение std::invalid_argument при ошибке
  BigInt(const BigInt &);
  ~BigInt();
};

#endif // LAB1_BIGINT_H
