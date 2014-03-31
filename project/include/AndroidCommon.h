#ifndef _AndroidCommon_h
#define _AndroidCommon_h

#include <jni.h>

#ifdef __GNUC__
  #define JAVA_EXPORT __attribute__ ((visibility("default"))) JNIEXPORT
#else
  #define JAVA_EXPORT JNIEXPORT
#endif


JNIEnv *GetEnv();
jclass FindClass(const char *className);

#endif