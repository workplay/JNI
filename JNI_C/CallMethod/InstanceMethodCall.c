#include <jni.h>
#include <stdio.h>
#include "InstanceMethodCall.h"

JNIEXPORT void JNICALL Java_InstanceMethodCall_nativeMethod
  (JNIEnv *env, jobject obj){
	jclass cls = (*env)->GetObjectClass(env,obj);
	jmethodID mid = (*env)->GetMethodID(env, cls, "callback","()V");
	if (mid == NULL){
		return;
	}
	printf("In C\n");
	//From C call java.
	(*env)->CallVoidMethod(env, obj, mid);
}
