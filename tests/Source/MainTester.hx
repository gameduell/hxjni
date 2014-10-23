import unittest.implementations.TestHTTPLogger;
import unittest.implementations.TestJUnitLogger;
import unittest.implementations.TestSimpleLogger;

import unittest.TestRunner;

import FilesystemTest;

import duell.DuellKit;

class MainTester
{
    private static var r : TestRunner;
    static function main()
    {
        DuellKit.initialize(start);
    }

    static function start() : Void
    {
        r = new TestRunner(testComplete);
		r.add(new HXJNITest());

        #if test
        r.addLogger(new TestHTTPLogger(new TestJUnitLogger()));
        #else
        r.addLogger(new TestSimpleLogger());
        #end

        r.run();
    }

    static function testComplete()
    {
        trace(r.result);
    }

}