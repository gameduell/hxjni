import unittest.TestCase;
import hxjni.JNI;

using StringTools;

class HXJNITest extends TestCase
{
	private static var hxjnitest_initialize_jni = JNI.createStaticMethod ("org/haxe/duell/HxJNITest", "initialize", "(Lorg/haxe/hxjni/HaxeObject;)V");
	private static var hxjnitest_calljtohxmethods = JNI.createStaticMethod ("org/haxe/duell/HxJNITest", "callJtoHxMethods", "()V");
	private static var hxjnitest_getinstance = JNI.createStaticMethod ("org/haxe/duell/HxJNITest", "getInstance", "()Lorg/haxe/duell/HxJNITest;");

	private static var hxjnitest_getx = JNI.createMemberMethod ("org/haxe/duell/HxJNITest", "getX", "()I");
	private static var hxjnitest_setx = JNI.createMemberMethod ("org/haxe/duell/HxJNITest", "setX", "(I)V");

    public function new ()
	{
        super();
		trace(untyped cpp.vm.Thread.current().handle.mThreadNumber);

        hxjnitest_initialize_jni(this);
		hxjnitest_calljtohxmethods();
		var javaObj = hxjnitest_getinstance();

		trace("should be zero:" + hxjnitest_getx(javaObj));

		hxjnitest_setx(javaObj, 10);

		trace("should be ten:" + hxjnitest_getx(javaObj));
	}


	public function testJtoHxNoParam() : Void
	{
		trace(cpp.vm.Thread.current().handle);
		trace("testJtoHxNoParam worked");
	}

	public function testJtoHxDynamicParam(param : Dynamic) : Void
	{
		trace("testJtoHxIntParam worked with " + param);
	}
	public function testJtoHxIntParam(param : Int) : Void
	{
		trace("testJtoHxIntParam worked with " + param);
	}

	public function testJtoHxStringParam(param : String) : Void
	{
		trace("testJtoHxStringParam worked with " + param);
	}

	public function testJtoHxIntArrayParam(param : Array<Int>) : Void
	{
		trace("testJtoHxIntArrayParam worked with " + param.toString());
	}

	public function testJtoHxFloatArrayParam(param : Array<Float>) : Void
	{
		trace("testJtoHxFloatArrayParam worked with " + param.toString());
	}

	public function testJtoHxStringArrayParam(param : Array<String>) : Void
	{
		trace("testJtoHxStringArrayParam worked with " + param.toString());
	}

	/// only string return is supported
	public function testJtoHxNoParamWithStringReturn() : String
	{
		trace("testJtoHxNoParamWithReturn");
		return "1";
	}

	public function testJtoHxIntParamWithStringReturn(param : Int) : String
	{
		trace("testJtoHxIntParamWithReturn");
		return "" + param + 1;
	}


	/// MAIN

	static function main () : Void
	{
		new HXJNITest();
	}

}