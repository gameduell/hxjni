package org.haxe.duell.hxjni;

import android.util.Log;

public class HaxeObject
{
   public long __haxeHandle;

   public HaxeObject(long value)
   {
      __haxeHandle = value;
   }

   public static HaxeObject create(long inHandle) { return new HaxeObject(inHandle); }


   protected void finalize() throws Throwable {
    try {
        NativeInterface.releaseReference(__haxeHandle);
    } finally {
        super.finalize();
    }
   }
   public Object call0(String function)
   {
      //Log.e("HaxeObject","Calling obj0" + function + "()" );
      return NativeInterface.callObjectFunction(__haxeHandle,function,new Object[0]);
   }
   public Object call1(String function,Object arg0)
   {
      Object[] args = new Object[1];
      args[0] = arg0;
      //Log.e("HaxeObject","Calling obj1 " + function + "(" + arg0 + ")" );
      return NativeInterface.callObjectFunction(__haxeHandle,function,args);
   }
   public Object call2(String function,Object arg0,Object arg1)
   {
      Object[] args = new Object[2];
      args[0] = arg0;
      args[1] = arg1;
      //Log.e("HaxeObject","Calling obj2 " + function + "(" + arg0 + "," + arg1 + ")" );
      return NativeInterface.callObjectFunction(__haxeHandle,function,args);
   }
   public Object call3(String function,Object arg0,Object arg1,Object arg2)
   {
      Object[] args = new Object[3];
      args[0] = arg0;
      args[1] = arg1;
      args[2] = arg2;
      //Log.e("HaxeObject","Calling obj3 " + function + "(" + arg0 + "," + arg1 + "," + arg2 + ")" );
      return NativeInterface.callObjectFunction(__haxeHandle,function,args);
   }
   public Object call4(String function,Object arg0,Object arg1,Object arg2,Object arg3)
   {
      Object[] args = new Object[4];
      args[0] = arg0;
      args[1] = arg1;
      args[2] = arg2;
      args[3] = arg3;
      //Log.e("HaxeObject","Calling obj4 " + function + "(" + arg0 + "," + arg1 + "," + arg2 + "," + arg3 + ")" );
      return NativeInterface.callObjectFunction(__haxeHandle,function,args);
   }

   public double callD0(String function)
   {
      //Log.e("HaxeObject","Calling objD0 " + function + "()" );
      return NativeInterface.callNumericFunction(__haxeHandle,function,new Object[0]);
   }
   public double callD1(String function,Object arg0)
   {
      Object[] args = new Object[1];
      args[0] = arg0;
      //Log.e("HaxeObject","Calling D1 " + function + "(" + arg0 + ")" );
      return NativeInterface.callNumericFunction(__haxeHandle,function,args);
   }
   public double callD2(String function,Object arg0,Object arg1)
   {
      Object[] args = new Object[2];
      args[0] = arg0;
      args[1] = arg1;
      //Log.e("HaxeObject","Calling D2 " + function + "(" + arg0 + "," + arg1 + ")" );
      return NativeInterface.callNumericFunction(__haxeHandle,function,args);
   }
   public double callD3(String function,Object arg0,Object arg1,Object arg2)
   {
      Object[] args = new Object[2];
      args[0] = arg0;
      args[1] = arg1;
      args[2] = arg2;
      //Log.e("HaxeObject","Calling D3 " + function + "(" + arg0 + "," + arg1 + "," + arg2 + ")" );
      return NativeInterface.callNumericFunction(__haxeHandle,function,args);
   }





   public Object call(String function, Object[] args)
   {
      return NativeInterface.callObjectFunction(__haxeHandle,function,args);
   }
   public double callD(String function, Object[] args)
   {
     return NativeInterface.callNumericFunction(__haxeHandle,function,args);
   }
}