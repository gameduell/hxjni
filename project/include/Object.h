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
