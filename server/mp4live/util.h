/*
 * The contents of this file are subject to the Mozilla Public
 * License Version 1.1 (the "License"); you may not use this file
 * except in compliance with the License. You may obtain a copy of
 * the License at http://www.mozilla.org/MPL/
 * 
 * Software distributed under the License is distributed on an "AS
 * IS" basis, WITHOUT WARRANTY OF ANY KIND, either express or
 * implied. See the License for the specific language governing
 * rights and limitations under the License.
 * 
 * The Original Code is MPEG4IP.
 * 
 * The Initial Developer of the Original Code is Cisco Systems Inc.
 * Portions created by Cisco Systems Inc. are
 * Copyright (C) Cisco Systems Inc. 2000, 2001.  All Rights Reserved.
 * 
 * Contributor(s): 
 *              Bill May        wmay@cisco.com
 */
#ifndef __UTIL_H__
#define __UTIL_H__

inline void* Malloc(size_t size) {
	void* p = malloc(size);
	if (p == NULL && size > 0) {
		throw;
	}
	return p;
} 

inline void imgcpy(
	u_int8_t* dst, u_int8_t* src, 
	u_int16_t width, u_int16_t height, u_int16_t src_stride) {

	if (width == src_stride) {
		memcpy(dst, src, width * height);
	} else {
		for (u_int16_t i = 0; i < height; i++) {
			memcpy(dst, src, width);
			dst += width;
			src += src_stride;
		}
	}
}


#ifdef __cplusplus
extern "C" {
#endif

void error_message(const char *fmt, ...)
       __attribute__((format(__printf__, 1, 2)))
;

void debug_message(const char *fmt, ...)
       __attribute__((format(__printf__, 1, 2)))
	   ;

void lib_message(int loglevel,
		 const char *lib,
		 const char *fmt,
		 va_list ap);

void message(int loglevel, const char *lib, const char *fmt, ...)
       __attribute__((format(__printf__, 3, 4)))
	   ;

char *get_host_ip_address(void);

#ifdef __cplusplus
}
#endif

extern bool PrintDebugMessages;
#endif
