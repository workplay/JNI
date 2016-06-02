#include <stdio.h>
#include <jni.h>
#include <stdlib.h>
#include <string.h>
#include "Prompt.h"

JNIEXPORT jstring JNICALL Java_Prompt_getLine
  (JNIEnv *env, jobject this, jstring prompt){
	char buf[128];	
	const jbyte *str;
	str = (*env)->GetStringUTFChars(env, prompt, NULL);
	
	//There are two methods to get the length of a String.
	//1. strlen(jbyte cstring)
	//2. (*env)->GetStringUTFLength(env, prompt)
	printf("The length of String is (by str.strlen) : %d\n",(int)strlen(str));
	printf("The length of String is (by GetStringUTFLength) : %d\n",(int)(*env)->GetStringUTFLength(env, prompt));
	
	if (str == NULL){
		return NULL;	
	}
	printf("%s", str);
	(*env)->ReleaseStringUTFChars(env, prompt, str);
	scanf("%s" , buf);
	return (*env)->NewStringUTF(env,buf);
}
