/*
 * Copyright (C) 2007-2013 Siemens AG
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

/*******************************************************************
 *
 * @author Daniel.Peintner.EXT@siemens.com
 * @version 0.8 
 * @contact Joerg.Heuer@siemens.com
 *
 * <p>Code generated by EXIdizer.com</p>
 * <p>Schema: input/test_v2g/V2G_CI_MsgDef.xsd</p>
 *
 *
 ********************************************************************/



#ifdef __cplusplus
extern "C" {
#endif

#include "EXITypes.h"

/**
 * \file 	UCSString.h
 * \brief 	UCS String utilities
 *
 */

#ifndef UCS_STRING_H
#define UCS_STRING_H

/**
 * \brief 		Converts characters to USC string
 *
 * \param       chars	   		Characters
 * \param       s				UCS String
 * \return                  	Error-Code <> 0
 *
 */
int toUCSString(char* chars, exi_string_ucs_t* s);


/**
 * \brief 		Converts String to ASCII characters
 *
 * 				Note: fails if string contains non ASCII characters.
 * 				Note: Make also sure that the char array is large enough.
 *
 * \param       string			UCS String
 * \param       string	   		Input String
 * \param       outASCII	   	ASCII Characters (out)
 * \return                  	Error-Code <> 0
 *
 */
int toASCIIString(exi_string_ucs_t* string, char* outASCII);

#endif


#ifdef __cplusplus
}
#endif
