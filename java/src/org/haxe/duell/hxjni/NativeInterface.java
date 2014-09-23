package org.haxe.duell.hxjni;

// Wrapper for native library

public class NativeInterface {

     public static native Object callObjectFunction(long inHandle,String function, Object[] args);
     public static native double callNumericFunction(long inHandle,String function, Object[] args);
     public static native void releaseReference(long inHandle);
}
