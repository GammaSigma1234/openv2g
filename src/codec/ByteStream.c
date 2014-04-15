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



/* Avoid VS warning, put before your included header files */
/* warning C4996: �fopen�: This function or variable may be unsafe. Consider using fopen_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. */
#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>

#include "EXITypes.h"
#include "ErrorCodes.h"

#ifndef BYTE_STREAM_C
#define BYTE_STREAM_C

int readBytesFromFile(const char * filename, uint8_t* data, uint32_t size, uint32_t* pos) {
	FILE* f;
	int character;
	int errn = 0;

	f = fopen(filename, "rb");

	if (f == NULL) {
		errn = EXI_ERROR_INPUT_FILE_HANDLE;
	} else {
		/* read bytes */
		while (errn == 0 && (character = getc(f)) != EOF) {
			if (*pos >= size) {
				errn = EXI_ERROR_OUT_OF_BYTE_BUFFER;
			} else {
				data[(*pos)++] = (uint8_t) character;
			}
		}
		fclose(f);
	}

	return errn;
}

int writeBytesToFile(uint8_t* data, uint32_t len, const char * filename) {
	size_t rlen;
	FILE* f = fopen(filename, "wb+");

	if (f == NULL) {
		return -1;
	} else {
		rlen = fwrite(data, sizeof(uint8_t), len, f);
		fflush(f);
		fclose(f);
		if(rlen == len) {
			return 0;
		} else {
			return EXI_ERROR_OUTPUT_FILE;
		}
	}
}


#endif /* BYTE_STREAM_C */

