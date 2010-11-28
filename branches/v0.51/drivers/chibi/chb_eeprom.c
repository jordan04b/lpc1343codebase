/*******************************************************************
    Copyright (C) 2009 FreakLabs
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions
    are met:

    1. Redistributions of source code must retain the above copyright
       notice, this list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright
       notice, this list of conditions and the following disclaimer in the
       documentation and/or other materials provided with the distribution.
    3. Neither the name of the the copyright holder nor the names of its contributors
       may be used to endorse or promote products derived from this software
       without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS IS'' AND
    ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
    ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE
    FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
    DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
    OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
    HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
    LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
    OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
    SUCH DAMAGE.

    Originally written by Christopher Wang aka Akiba.
    Please post support questions to the FreakLabs forum.

*******************************************************************/
/*!
    \file 
    \ingroup


*/
/**************************************************************************/
#include "chb_eeprom.h"
#include "drivers/eeprom/mcp24aa/mcp24aa.h"

/**************************************************************************/
/*!

*/
/**************************************************************************/
void chb_eeprom_write(uint16_t addr, uint8_t *buf, uint16_t size)
{
  // Instantiate error message placeholder
  mcp24aaError_e error = MCP24AA_ERROR_OK;
  
  // Write the address one byte at a time
  uint16_t a = 0;
  while (a < size)
  {
    error = mcp24aaWriteByte(addr + a, buf[a]);
    if (error)
    {
      // ToDo: Handle any errors
    }
    a++;
  }
}

/**************************************************************************/
/*!

*/
/**************************************************************************/
void chb_eeprom_read(uint16_t addr, uint8_t *buf, uint16_t size)
{
  // Instantiate error message placeholder
  mcp24aaError_e error = MCP24AA_ERROR_OK;
  
  // Read the contents of address 0x0125
  error = mcp24aaReadBuffer(addr, buf, size);

  if (error)
  {
    // ToDo: Handle any errors
  }
}

