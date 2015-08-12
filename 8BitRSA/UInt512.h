#ifndef UINT512_H
#define UINT512_H

#include <stdint.h>

#define UINT512_BYTES_LEN 4

class UInt512
{
private:
	uint8_t _bits[64];
public:
	UInt512();
	UInt512(const uint8_t &src);
	UInt512(const uint16_t &src);
	UInt512(const uint32_t &src);
  UInt512(const int8_t &src);
  UInt512(const int16_t &src);
  UInt512(const int32_t &src);
  UInt512(const UInt512 &src);

	void Clear();
  void DebugPrint();

	UInt512 operator + (const UInt512 &right) const;
	UInt512 operator - (const UInt512 &right) const;
	UInt512 operator * (const UInt512 &right) const;
  UInt512 operator / (const UInt512 &right) const;
	UInt512 operator % (const UInt512 &right) const;
  UInt512 PowMod(const UInt512 &pow, const UInt512 &mod) const;
};

#endif
