/*
 * math.cpp
 * 
 * Copyright 2018  Alvarito050506 <donfrutosgomez@gmail.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

#include "types.hpp"
#include "macros.hpp"
#include "math.hpp"

// Funciones
dint Math::Operations::Add(dint a, dint b)
{
	return (a + b);
}

dint Math::Operations::Subs(dint a, dint b)
{
	return (a - b);
}

dint Math::Operations::Mult(dint a, dint b)
{
	return (a * b);
}

dint Math::Operations::Div(dint a, dint b)
{
	return (a / b);
}

dint Math::Operations::Rcd(dint c)
{
	return (c / c);
}

dint Math::Operations::Acl(dint c)
{
	return (c * c);
}

dint Math::Operations::Acu(dint c)
{
	return (c * c * c);
}
