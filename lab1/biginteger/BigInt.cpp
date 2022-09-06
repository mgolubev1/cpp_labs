//
// Created by Maxim on 05.09.2022.
//
#include <BigInt.h>

bool BigInt::IsSignNegative() { return is_negative; }

std::vector<int> BigInt::GetDigits() { return digits; }

BigInt::BigInt() {
  is_negative = false;
  digits.push_back(0);
}

BigInt::BigInt(int digit) {
  if (digit < 0) {
    is_negative = true;
    digit = -digit;
  } else {
    is_negative = false;
  }
  if (digit < kBase) {
    digits.push_back(digit);
  } else {
    digits.push_back(digit / 10);
    digits.push_back(digit % 10);
  }
}



BigInt::BigInt(std::string) {

}

BigInt::~BigInt() {}
