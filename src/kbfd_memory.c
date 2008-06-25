/* 
 *  BFD Memory Management
 *
 * base from draft-ietf-bfd-base-05.txt
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 *
 * Copyright (C) Hajime TAZAKI, 2007
 */

#include "kbfd_sys.h"

#include "kbfd_memory.h"

void *
bfd_malloc(size_t size)
{
  void *mem = NULL;
#ifdef linux
  mem = kmalloc(size, GFP_KERNEL);
#elif defined __NetBSD__
  mem = malloc(size, M_TEMP, M_WAITOK);
#endif
  return mem;
}

void
bfd_free(void *mem)
{
#ifdef linux
  kfree(mem);
#elif defined __NetBSD__
  free(mem, M_TEMP);
#endif
  return;
}