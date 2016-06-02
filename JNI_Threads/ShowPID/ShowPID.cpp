#include <jni.h>
#include <stdio.h>
#include <unistd.h>
#include "ShowPID.h"

JNIEXPORT void JNICALL Java_ShowPID_print
  (JNIEnv *env, jobject obj)
{
	printf("Progress ID in C \n\tpid=%d\n", getpid());
	return;
}

