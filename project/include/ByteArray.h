/*
 * Copyright (c) 2003-2015, GameDuell GmbH
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef HXJNI_BYTE_ARRAY_H
#define HXJNI_BYTE_ARRAY_H

#include "QuickVec.h"

namespace hxjni
{


// If you put this structure on the stack, then you do not have to worry about GC.
// If you store this in a heap structure, then you will need to use GC roots for mValue...
struct ByteArray
{
   ByteArray(int inSize);
   ByteArray(const ByteArray &inRHS);
   ByteArray();
   ByteArray(struct _value *Value);
   ByteArray(const QuickVec<unsigned char>  &inValue);

   void          Resize(int inSize);
   int           Size() const;
   unsigned char *Bytes();
   const unsigned char *Bytes() const;
   bool          Ok() { return mValue!=0; }


   struct _value *mValue;

   static ByteArray FromFile(const OSChar *inFilename);
   #ifdef HX_WINDOWS
   static ByteArray FromFile(const char *inFilename);
   #endif
};

}

#endif
