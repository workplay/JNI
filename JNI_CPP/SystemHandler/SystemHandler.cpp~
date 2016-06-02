#include <jni.h>
#include <iostream>
#include "SystemHandler.h"
#include <iostream>
#include <csignal>
#include <stdlib.h>
#include <setjmp.h>

using namespace std;

jmp_buf return_to_top_level;

JNIEnv* env = NULL;
//We can do something in the handler.
void handler(int a){
	signal(SIGFPE, SIG_DFL);
	cout <<"Signal  "<<a <<" here!"<<endl;
	
	//throw an exception
	jclass newExcCls;
	newExcCls = env->FindClass("java/lang/IllegalArgumentException");
	if (newExcCls == NULL){
		cout <<"FindClass(\"java/lang/IllegalArgumentException\") failed!"<<endl;
		return;
	}
	env->ThrowNew( newExcCls, "thrown from C code");
	
	//change SIGFPE to the Default Value	

	signal(SIGFPE,handler);
	longjmp (return_to_top_level, 1);
}

JNIEXPORT void JNICALL Java_SystemHandler_print
  (JNIEnv *_env, jobject obj)
{
	env = _env;

	signal(SIGFPE,handler);

	if (setjmp (return_to_top_level) == 0){
		int d = 5;
		d = d/(d-5);
	}

	return;
}

