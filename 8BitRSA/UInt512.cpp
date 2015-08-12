#include "UInt512.h"

#define DEBUG 1
#if UINT512_BYTES_LEN == 4 && DEBUG
#include <iostream>

#endif

UInt512::UInt512()
{
  Clear();
}

UInt512::UInt512(const uint8_t &src)
{
  Clear();
  _bits[0] = src;
}

UInt512::UInt512(const uint16_t &src)
{
  Clear();
  _bits[0] = src & 0xFF;
  _bits[1] = (src >> 8) & 0xFF;
}

UInt512::UInt512(const uint32_t &src)
{
  Clear();
  _bits[0] = src & 0xFF;
  _bits[1] = (src >> 8) & 0xFF;
  _bits[2] = (src >> 16) & 0xFF;
  _bits[3] = (src >> 24) & 0xFF;
}

UInt512::UInt512(const int8_t &isrc)
{
  uint8_t src = (uint8_t) isrc;
  Clear();
  _bits[0] = src;
}

UInt512::UInt512(const int16_t &isrc)
{
  uint16_t src = (uint16_t) isrc;
  Clear();
  _bits[0] = src & 0xFF;
  _bits[1] = (src >> 8) & 0xFF;
}

UInt512::UInt512(const int32_t &isrc)
{
  uint32_t src = (uint32_t) isrc;
  Clear();
  _bits[0] = src & 0xFF;
  _bits[1] = (src >> 8) & 0xFF;
  _bits[2] = (src >> 16) & 0xFF;
  _bits[3] = (src >> 24) & 0xFF;
}

UInt512::UInt512(const UInt512 &src)
{
  for(uint8_t i = 0; i < UINT512_BYTES_LEN; i++)
    _bits[i] = src._bits[i];
}

void UInt512::Clear()
{
  for(uint8_t i = 0; i < UINT512_BYTES_LEN; i++)
    _bits[i] = 0;
}

void UInt512::DebugPrint()
{
#if UINT512_BYTES_LEN == 4 && DEBUG
  std::cout << "DBG: " << (*(uint32_t *) _bits) << std::endl;
#endif
}

UInt512 UInt512::operator + (const UInt512 &right) const
{
  UInt512 temp;
  uint8_t carry = 0;
  for(uint8_t i = 0; i < UINT512_BYTES_LEN; i++)
  {
    const uint8_t byteA = _bits[i];
    const uint8_t byteB = right._bits[i];
    uint16_t byteRes = byteA + byteB + carry;
    temp._bits[i] = byteRes;
    carry = byteRes >> 8;
  }

  return temp;
}

UInt512 UInt512::operator - (const UInt512 &right) const
{
  UInt512 temp;
  // NOT IMPLEMENTED
  return temp;
}

UInt512 UInt512::operator * (const UInt512 &right) const
{
  UInt512 temp;
  // NOT IMPLEMENTED
  return temp;
}

UInt512 UInt512::operator / (const UInt512 &right) const
{
  UInt512 temp = *this;
  while(temp > right)
  {
    temp -= right;
  }
  return temp;
}

UInt512 UInt512::operator % (const UInt512 &right) const
{
  UInt512 temp;
  // NOT IMPLEMENTED
  return temp;
}

UInt512 UInt512::PowMod(const UInt512 &pow, const UInt512 &mod) const
{
  UInt512 temp;
  // NOT IMPLEMENTED
  return temp;
}