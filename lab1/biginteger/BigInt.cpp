//
// Created by Maxim on 05.09.2022.
//
#include <BigInt.h>
#include <iomanip>  // std::setw
#include <iostream> // std::cout, std::left

bool BigInt::IsSignNegative() const { return is_negative; }

std::vector<int> const &BigInt::GetDigits() const { return digits; }

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
    digits.push_back(digit % kBase);
    digits.push_back(digit / kBase);
  }
}

namespace ParseUtil {
inline bool IsFirstCharSign(std::string const &str) {

  const char &i = str.at(0);
  if (i == '-' || i == '+') {
    return true;
  }
  return false;
}
inline bool IsSignNegative(char c) {
  if (c == '-') {
    return true;
  }
  return false;
}
inline int MoveLeftBoundIfHasLeadingZeros(int left_bound,
                                          std::string const &str) {
  while (left_bound < str.length() && str.at(left_bound) == '0') {
    left_bound++;
  }
  return left_bound;
}
} // namespace ParseUtil

BigInt::BigInt(std::string str) {
  int left_bound = 0;
  if (ParseUtil::IsFirstCharSign(str)) {
    is_negative = ParseUtil::IsSignNegative(str.at(0));
    left_bound++;
  } else {
    is_negative = false;
  }
  left_bound = ParseUtil::MoveLeftBoundIfHasLeadingZeros(left_bound, str);
  if (left_bound == str.length()){
    digits.push_back(0);
  }
  for (int i = str.length() - 1; i >= left_bound; i -= kMaxDigitLen) {
    std::string tmp;
    if (i-left_bound < kMaxDigitLen) {
      tmp = str.substr(left_bound,i- left_bound);
    } else {
      tmp = str.substr(i-kMaxDigitLen+1,kMaxDigitLen);
    }
    int to_push = std::stoi(tmp);
    digits.push_back(to_push);
  }
}

BigInt::~BigInt() {}

std::ostream &operator<<(std::ostream &o, const BigInt &i) {
  if (i.IsSignNegative()) {
    o << '-';
  }
  long size = i.GetDigits().size();
  o << i.GetDigits()[size - 1];
  for (int j = size - 2; j >= 0; j--) {
    o << std::right << std::setw(kMaxDigitLen) << std::setfill('0')
      << i.GetDigits()[j];
  }
  return o;
}
