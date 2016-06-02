#include <jni.h>
#include <stdio.h>
#include "InstanceFieldAccess.h"

JNIEXPORT void JNICALL Java_InstanceFieldAccess_accessField
  (JNIEnv *env, jobject obj){
	jfieldID fid;
	jstring jstr;
	const char *str;

	/* Get a reference to obj's class */
	jclass cls = (*env)->GetObjectClass(env, obj);

	printf("In c:\n");

	/* Look for the instance field s in cls */
	fid = (*env)->GetFieldID(env, cls, "s", "Ljava/lang/String;");
	if (fid == NULL){
		return;	
	}
	/* Read the instance field s */
	jstr = (*env)->GetObjectField(env, obj, fid);
	str = (*env)->GetStringUTFChars(env, jstr, NULL);
	if (str == NULL){
		return;	
	}
	printf("  c.s = \"%s\"\n",str);
	(*env)->ReleaseStringUTFChars(env,jstr,str);

	/* Create a new String overwrite the instance field */
	jstr = (*env)->NewStringUTF(env,"123");
	if (jstr == NULL){
		return;	
	}
	(*env)->SetObjectField(env, obj, fid, jstr);
}
