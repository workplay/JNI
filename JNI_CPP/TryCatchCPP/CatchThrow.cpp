#include <jni.h>
#include <stdio.h>
#include <iostream>
#include "CatchThrow.h"
using namespace std;

JNIEXPORT void JNICALL Java_CatchThrow_doit
  (JNIEnv *env, jobject obj){
	cout <<"I can print out this line"<<endl;
	jint d = 5;
	jint result = 2/(d-5);	
}

