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

#ifndef HXJNI_OBJECT_H
#define HXJNI_OBJECT_H

#include <jni.h>
#include <hx/CFFI.h>

namespace hxjni
{

class Object
{
	public:

		Object(bool inInitialRef=0) : mRefCount(inInitialRef?1:0) { }

		Object *IncRef() 
		{ 
			mRefCount++; 
			return this; 
		}

		void DecRef() 
		{ 
			mRefCount--; 
			if (mRefCount<=0) 
				delete this; 
		}

	    int GetRefCount() 
	    { 
	    	return mRefCount; 
	    }

	protected:

		virtual ~Object() 
		{

		}

	    int mRefCount;
};

struct AutoHaxe
{
   int base;
   const char *message;
   AutoHaxe(const char *inMessage)
   {  
      base = 0;
      message = inMessage;
      gc_set_top_of_stack(&base,true);
      //__android_log_print(ANDROID_LOG_VERBOSE, "NME", "Enter %s %p", message, pthread_self());
   }
   ~AutoHaxe()
   {
      //__android_log_print(ANDROID_LOG_VERBOSE, "NME", "Leave %s %p", message, pthread_self());
      gc_set_top_of_stack(0,true);
   }
};

/// UTILS

extern vkind gObjectKind;

template<typename OBJ>
bool AbstractToObject(value inValue, OBJ *&outObj)
{	
   outObj = 0;
   if ( ! val_is_kind(inValue,gObjectKind) )
      return false;
   Object *obj = (Object *)val_to_kind(inValue,gObjectKind);
   outObj = dynamic_cast<OBJ *>(obj);
   return outObj;
}

value ObjectToAbstract(Object *inObject);

} // end namespace hxjni



#endif
