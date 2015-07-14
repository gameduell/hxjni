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

        trace ("onCallback - unknown field " + method + " on object " + object);
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

