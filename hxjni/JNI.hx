package hxjni;

import cpp.Lib;

import cpp.zip.Uncompress;
import haxe.crypto.BaseCode;
import haxe.io.Bytes;


class JNI {
    
    
    private static var initialized = false;
    
    
    private static function init ():Void {
        
        if (!initialized) {
            
            initialized = true;
            var method = Lib.load ("hxjni", "hxjni_jni_init_callback", 1);
            method (onCallback);

            
        }
        
    }
    
    
    private static function onCallback (object:Dynamic, method:Dynamic, args:Dynamic):Dynamic {
        
        var field = Reflect.field (object, method);
        
        if (field != null) {
            
            return Reflect.callMethod (object, field, args);
            
        }
        
        trace ("onCallback - unknown field " + method);
        return null;
        
    }
    
    
    public static function createMemberMethod (className:String, memberName:String, signature:String, useArray:Bool = false):Dynamic {
        
        init ();
        
        var method = new JNIMethod (hxjni_jni_create_method (className, memberName, signature, false));
        return method.getMemberMethod (useArray);
        
    }
    
    
    public static function createStaticMethod (className:String, memberName:String, signature:String, useArray:Bool = false):Dynamic {
        
        init ();
        var method = new JNIMethod (hxjni_jni_create_method (className, memberName, signature, true));
        return method.getStaticMethod (useArray);
        
    }
    
    
    
    
    // Native Methods
    
    
    
    
    private static var hxjni_jni_create_method = Lib.load ("hxjni", "hxjni_jni_create_method", 4);
    
    
}


class JNIMethod {
    
    
    private var method:Dynamic;
    
    
    public function new (method:Dynamic) {
        
        this.method = method;
        
    }

    public function callMember (args:Array<Dynamic>):Dynamic {
        
        var jobject = args.shift ();
        return hxjni_jni_call_member (method, jobject, args);
        
    }
    
    
    public function callStatic (args:Array<Dynamic>):Dynamic {
        
        return hxjni_jni_call_static (method, args);
        
    }
    
    
    public function getMemberMethod (useArray:Bool):Dynamic {
        
        if (useArray) {
            
            return callMember;
            
        } else {
            
            return Reflect.makeVarArgs (callMember);
            
        }
        
    }
    
    
    public function getStaticMethod (useArray:Bool):Dynamic {
        
        if (useArray) {
            
            return callStatic;
            
        } else {
            
            return Reflect.makeVarArgs (callStatic);
            
        }
        
    }
    
    
    
    
    // Native Methods
    
    
    
    
    private static var hxjni_jni_call_member = Lib.load ("hxjni", "hxjni_jni_call_member", 3);
    private static var hxjni_jni_call_static = Lib.load ("hxjni", "hxjni_jni_call_static", 2);
    
    
}

