#include <jni.h>
#include <stdio.h>
#include "CatchThrow.h"

/*
void throwUtil(JNIEnv *env){
	jclass newExcCls;
	jthrowable exc;
	newExcCls = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
	if (newExcCls == NULL){
		return;
	}
	(*env)->ThrowNew(env, newExcCls, "thrown from C code");
}
*/

/*
	jclass cls = (*env)->GetObjectClass(env,obj);
	jmethodID mid = (*env)->GetMethodID(env, cls, "callback", "()V");
	if (mid == NULL) return;
	(*env)->CallVoidMethod(env, obj, mid);
*/

JNIEXPORT void JNICALL Java_CatchThrow_doit
  (JNIEnv *env, jobject obj){
	jint d = 5;
	jint result = 2/(d-5);	
	
	jthrowable exc;
	exc = (*env)->ExceptionOccurred(env);
	if (exc){
		(*env)->ExceptionDescribe(env);
		(*env)->ExceptionClear(env);
		return;
	}
	
}

