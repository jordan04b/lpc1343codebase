/**************************************************************************/
/*! 
    @file     cmd_tbl.h
    @author   K. Townsend (microBuilder.eu)
    @date     22 March 2010
    @version  0.10

    @section LICENSE

    Software License Agreement (BSD License)

    Copyright (c) 2010, microBuilder SARL
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:
    1. Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.
    3. Neither the name of the copyright holders nor the
    names of its contributors may be used to endorse or promote products
    derived from this software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ''AS IS'' AND ANY
    EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE FOR ANY
    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
/**************************************************************************/

#ifndef __CMD_TBL_H__ 
#define __CMD_TBL_H__

#include <stdio.h>
#include <stdlib.h>

#ifdef CFG_INTERFACE_UART
#include "core/uart/uart.h"
#endif

// A full list of function prototypes for the command table
void cmd_help(uint8_t argc, char **argv);         // Mandatory - handled by cmd.c
void cmd_hello(uint8_t argc, char **argv);
void cmd_sysinfo(uint8_t argc, char **argv);

/**************************************************************************/
/*! 
    Command list for the command-line interpreter and the name of the
    corresponding method that handles the command
*/
/**************************************************************************/
cmd_t cmd_tbl[] = 
{
  { "help",        0, 0, cmd_help        , "Displays a list of all available commands",       "'help' has no parameters" },
  { "hello",       0, 1, cmd_hello       , "Displays 'Hello World!'",                         "'hello [<name>]'" },
  { "sysinfo",     0, 0, cmd_sysinfo     , "Displays current system configuration settings",  "'sysinfo' has no parameters" },
};

#define CMD_COUNT (sizeof(cmd_tbl)/sizeof(cmd_t))

#endif