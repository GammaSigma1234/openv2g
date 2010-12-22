/*
 * Copyright (C) 2007-2010 Siemens AG
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
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

/*******************************************************************
 *
 * @author Daniel.Peintner.EXT@siemens.com
 * @version 0.3.1
 * @contact Joerg.Heuer@siemens.com
 *
 ********************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include "EXITypes.h"
#include "BitInputStream.h"

#ifndef BIT_INPUT_STREAM_C
#define BIT_INPUT_STREAM_C

/* internal method to (re)fill buffer */
int readBuffer(bitstream_t* stream)
{
	int errn = 0;
	if(stream->capacity==0)
	{
		if ( (*stream->pos) < stream->size ) {
			stream->buffer = stream->data[(*stream->pos)++];
			stream->capacity = BITS_IN_BYTE;
		} else {
			errn = -1;
		}
	}
	return errn;
}

int readBits(bitstream_t* stream, uint16_t num_bits, uint32_t* b)
{
	int errn = readBuffer(stream);
	if (errn < 0) {
		return errn;
	}

	/* read the bits in one step */
	if(num_bits <= stream->capacity)
	{
		stream->capacity -= num_bits;
		*b = (stream->buffer >> stream->capacity) & (0xff >> (BITS_IN_BYTE - num_bits));
	}
	else
	{
		/* read bits as much as possible */
		*b = stream->buffer & (0xff >> (BITS_IN_BYTE - stream->capacity));
		num_bits -= stream->capacity;
		stream->capacity = 0;

		/* read whole bytes */
		while(num_bits >= 8)
		{
			errn = readBuffer(stream);
			if (errn < 0) {
				return errn;
			}
			*b = ((*b) << BITS_IN_BYTE) | stream->buffer;
			num_bits -= BITS_IN_BYTE;
			stream->capacity = 0;
		}

		/* read the spare bits in the buffer */
		if(num_bits>0)
		{
			errn = readBuffer(stream);
			if (errn < 0) {
				return errn;
			}
			*b = ((*b) << num_bits) | (stream->buffer >> (BITS_IN_BYTE - num_bits));
			stream->capacity = BITS_IN_BYTE - num_bits;
		}
		
	}

	return errn;
}

#endif