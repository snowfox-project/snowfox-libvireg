/**
 * Snowfox is a modular RTOS with extensive IO support.
 * Copyright (C) 2017 - 2020 Alexander Entinger / LXRobotics GmbH
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TEST_INCLUDE_REGISTER_H_
#define TEST_INCLUDE_REGISTER_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <stdint.h>

#include <vector>
#include <string>
#include <memory>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace snowfox
{

namespace vireg
{

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

template <typename T>
class VirtualRegister
{

public:

  VirtualRegister(T const init_reg_val, std::string const & name);

  inline T *         ptr ()       { return &_reg_val; }
  inline T           val () const { return  _reg_val; }
  inline std::string name() const { return  _name;    }

  bool   operator == (T const val) const;
  void   operator =  (T const val);


  void   setBit      (uint32_t const bit_pos);
  void   clrBit      (uint32_t const bit_pos);

  bool   isBitSet    (uint32_t const bit_pos) const;
  bool   isBitClr    (uint32_t const bit_pos) const;
  bool   isBitVectSet(std::vector<uint32_t> const bit_pos_vect) const;


private:

  T                 _reg_val;
  std::string const _name;

};

/**************************************************************************************
 * TYPEDEF
 **************************************************************************************/

typedef std::shared_ptr<VirtualRegister<uint8_t>>  Vireg8;
typedef std::shared_ptr<VirtualRegister<uint16_t>> Vireg16;
typedef std::shared_ptr<VirtualRegister<uint32_t>> Vireg32;
typedef std::shared_ptr<VirtualRegister<uint64_t>> Vireg64;

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* vireg */

} /* snowfox */

/**************************************************************************************
 * TEMPLATE IMPLEMENTATION
 **************************************************************************************/

#include "VirtualRegister.ipp"

#endif /* TEST_INCLUDE_REGISTER_H_ */
