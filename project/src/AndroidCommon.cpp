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

#include "AndroidCommon.h"

#include <android/log.h>
#include <string>
#include <map>
#include <stdint.h>
#include <pthread.h>

#define LOGE(msg,args...) __android_log_print(ANDROID_LOG_ERROR, "hxjni::System", msg, ## args)

JavaVM *_vm;
std::map<std::string, jclass> jClassCache;
static pthread_key_t s_thread_key;

static void ThreadDataDestroy (void *env)
{
  _vm->DetachCurrentThread();
}

JNIEnv *GetEnv()
{
    JNIEnv *env;
    int getEnvStat = _vm->GetEnv((void**)&env, JNI_VERSION_1_4);
    if (getEnvStat == JNI_EDETACHED) {
        LOGE("GetEnv: not attached");
        if (_vm->AttachCurrentThread(&env, 0) != 0) {
            LOGE("Failed to attach");
        }
        pthread_setspecific (s_thread_key, &env);
    }
    return env;
}

jclass FindClass(const char *className)
{
    std::string cppClassName(className);
    jclass ret;
    if(jClassCache[cppClassName]!=NULL)
    {
        ret = jClassCache[cppClassName];
    }
    else
    {
        JNIEnv *env = GetEnv();
        jclass tmp = env->FindClass(className);
        ret = (jclass)env->NewGlobalRef(tmp);
        jClassCache[cppClassName] = ret;
        env->DeleteLocalRef(tmp);
    }
    return ret;
}

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved)
{
    _vm = vm;
    jClassCache = std::map<std::string, jclass>();
    pthread_key_create(&s_thread_key, ThreadDataDestroy);

    return  JNI_VERSION_1_4;                    // the required JNI version
    
}

