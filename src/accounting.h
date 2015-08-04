/*Daala video codec
Copyright (c) 2013 Daala project contributors.  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

- Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

- Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.*/

#if !defined(_accounting_H)
# define _accounting_H (1)

# include <stdio.h>
# include "internal.h"
# include "../include/daala/daaladec.h"

#define OD_ACCT_FRAME (10)
#define OD_ACCT_MV (11)

int od_accounting_dict_lookup(od_accounting_dict *dict, const char *str);

void od_accounting_init(od_accounting *acct);

void od_accounting_reset(od_accounting *acct);

void od_accounting_clear(od_accounting *acct);

void od_accounting_set_location(od_accounting *acct, int layer, int level,
 int x, int y);

void od_accounting_record(od_accounting *acct, char *str, int bits_q3);

# if OD_ACCOUNTING
#  define OD_ACCOUNTING_SET_LOCATION(dec, layer, level, x, y) \
  od_accounting_set_location(&(dec)->acct, layer, level, x, y)
# else
#  define OD_ACCOUNTING_SET_LOCATION(dec, layer, level, x, y)
# endif

#endif
