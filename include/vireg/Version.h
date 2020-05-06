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

#ifndef VIREG_INCLUDE_VERSION_H_
#define VIREG_INCLUDE_VERSION_H_

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace snowfox::vireg
{

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

struct Version
{
  static constexpr uint32_t Major = 1;
  static constexpr uint32_t Minor = 0;
  static constexpr uint32_t Patch = 0;
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* snowfox::vireg */

#endif /* VIREG_INCLUDE_VERSION_H_ */
