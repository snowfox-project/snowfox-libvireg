/**
 * Snowfox is a modular RTOS with extensive IO support.
 * Copyright (C) 2017 - 2019 Alexander Entinger / LXRobotics GmbH
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

/*****************************************************************************
 * INCLUDE
 *****************************************************************************/

#include <stdlib.h>
#include <assert.h>

#include <vireg/VirtualRegister.hpp>
#include <vireg/VirtualRegisterLoader.h>

/*****************************************************************************
 * CLASS UNDER TEST
 *****************************************************************************/

class LedDriver
{
public:

  LedDriver(volatile uint8_t * ddrb, volatile uint8_t * portb) : _ddrb(ddrb), _portb(portb)
  { 
    (*_ddrb) |= (1<<0);
  }

  void on () { (*_portb) |=  (1<<0); }
  void off() { (*_portb) &= ~(1<<0); }

private:

  volatile uint8_t * _ddrb,
                   * _portb;
};

/*****************************************************************************
 * TEST CODE
 *****************************************************************************/

using namespace snowfox::vireg;

int main(int /* argc */, char ** /* argv */)
{
  VirtualRegisterMap vregmap = VirtualRegisterLoader::load("example-01.json");

  Vireg8 virtual_ddrb  = vregmap.get<Vireg8>("DDRB" );
  Vireg8 virtual_portb = vregmap.get<Vireg8>("PORTB");

  LedDriver led_driver(virtual_ddrb->ptr(), virtual_portb->ptr());

  assert(*virtual_ddrb  == 0x01);
  assert(*virtual_portb == 0x00);

  led_driver.on();
  assert(*virtual_portb == 0x01);
  
  led_driver.off();
  assert(*virtual_portb == 0x00);
  
  return EXIT_SUCCESS;
}
