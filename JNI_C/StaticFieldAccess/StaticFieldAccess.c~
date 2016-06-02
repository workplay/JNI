#include <stdio.h>
#include <jni.h>
#include "StaticFieldAccess.h"

JNIEXPORT void JNICALL Java_StaticFieldAccess_accessField
  (JNIEnv *env, jobject obj){
	jfieldID fid;
	jint si;	

	jclass cls = (*env)->GetObjectClass(env,obj);
	
	printf("In c:\n");

	fid = (*env)->GetStaticFieldID(env,cls,"si","I");
	if (fid == NULL){
		return;
	}
	
	/* Access the static field si */
	si = (*env)->GetStaticIntField(env, cls, fid);
	printf("  StaticFieldAccess.si = %d\n", si);
	(*env)->SetStaticIntField(env, cls, fid, 200);
}
