package org.haxe.duell;


import android.app.Activity;
import android.content.res.AssetManager;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.view.View;
import android.util.Log;
import java.lang.Thread;
import java.lang.StackTraceElement;
import java.lang.Exception;


/* 
	You can use the Android Extension class in order to hook
	into the Android activity lifecycle. This is not required
	for standard Java code, this is designed for when you need
	deeper integration.
	
	You can access additional references from the Extension class,
	depending on your needs:
	
	- Extension.assetManager (android.content.res.AssetManager)
	- Extension.callbackHandler (android.os.Handler)
	- Extension.mainActivity (android.app.Activity)
	- Extension.mainContext (android.content.Context)
	- Extension.mainView (android.view.View)
	
	You can also make references to static or instance methods
	and properties on Java classes. These classes can be included 
	as single files using <java path="to/File.java" /> within your
	project, or use the full Android Library Project format (such
	as this example) in order to include your own AndroidManifest
	data, additional dependencies, etc.
	
	These are also optional, though this example shows a static
	function for performing a single task, like returning a value
	back to Haxe from Java.
*/
public class HxJNITest extends Extension {
	
	private static final String TAG = "duell";
	public static org.haxe.hxjni.HaxeObject haxeAppDelegate;
	public static void initialize(org.haxe.hxjni.HaxeObject obj) 
	{
		haxeAppDelegate = obj;

		Log.v(TAG, "init " + Thread.currentThread().getName());
	}
	
	public static void callJtoHxMethods() 
	{
		
		Log.v(TAG, "call " + Thread.currentThread().getName());
		//org.haxe.duell.DuellActivity.callbackHandler.post (new Runnable () {
			
		//	@Override public void run () {


				haxeAppDelegate.call0("testJtoHxNoParam");

				haxeAppDelegate.call1("testJtoHxIntParam", 1);
				haxeAppDelegate.call1("testJtoHxStringParam", "testString");

		    	int [] array = {1, 2, 3, 4, 5};
				haxeAppDelegate.call1("testJtoHxIntArrayParam", array);

		    	float [] farray = {1.1f, 2.1f, 3.1f, 4.1f, 5.1f};
				haxeAppDelegate.call1("testJtoHxFloatArrayParam", farray);

				///this one crashes
		    	//String [] sarray = {"strA", "strB", "strC", "strD", "strE"};
				//haxeAppDelegate.call1("testJtoHxStringArrayParam", sarray);

				/// only string return is supported

				String ret1 = (String)haxeAppDelegate.call0("testJtoHxNoParamWithStringReturn");
		    	Log.d(TAG, "testJtoHxNoParamWithStringReturn worked with:" + ret1);

				String ret2 = (String)haxeAppDelegate.call1("testJtoHxIntParamWithStringReturn", 1);
		    	Log.d(TAG, "testJtoHxIntParamWithStringReturn worked with:" + ret2);
				
		//	}
			
		//});
		
	}

	public static HxJNITest getInstance()
	{
		return new HxJNITest();
	}

	private int x = 0;

	public int getX()
	{
		return x;
	}

	public void setX(int newX)
	{
		x = newX;
	}
}