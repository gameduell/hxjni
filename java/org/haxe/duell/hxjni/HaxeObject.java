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
