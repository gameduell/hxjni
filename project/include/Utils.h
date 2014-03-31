#ifndef HXJNI_UTILS_H
#define HXJNI_UTILS_H

#include <android/log.h>

#ifdef VERBOSE
#define VLOG(args...) __android_log_print(ANDROID_LOG_INFO, "hxjni",args)
#else
#define VLOG(args...)
#endif

#define ELOG(args...) __android_log_print(ANDROID_LOG_ERROR, "hxjni",args)


namespace hxjni
{

typedef char OSChar;

} // end namespace hxjni

#endif
