#pragma once

class Fixed {
private:
  int rawBits;
  static const int fractionalBits = 8;

public:
  Fixed();
  Fixed(const Fixed &other);
  Fixed &operator=(const Fixed &other);
  ~Fixed();

  int getRawBits() const;
  void setRawBits(int raw);
};