#include "Object.h"

#include <jni.h>
#include <hx/CFFI.h>

namespace hxjni
{

vkind gObjectKind;

static void release_object(value inValue)
{
   if (val_is_kind(inValue,gObjectKind))
   {
      Object *obj = (Object *)val_to_kind(inValue,gObjectKind);
      if (obj)
         obj->DecRef();
   }
}

value ObjectToAbstract(Object *inObject)
{
   inObject->IncRef();
   value result = alloc_abstract(gObjectKind,inObject);
   val_gc(result, release_object);
   return result;
}

} // end namespace hxjni
