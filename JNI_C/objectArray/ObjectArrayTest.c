#include <jni.h>
#include <stdio.h>
#include "ObjectArrayTest.h"
JNIEXPORT jobjectArray JNICALL Java_ObjectArrayTest_initInt2DArray
  (JNIEnv *env, jclass cls, jint size){
	jobjectArray result;
	int i;
	//FindClass is to obtain a reference of the element class of the two-dimensinal int array. 
	// "[I" corresponds to int[] type
	//jclass intArrCls = int[]
	jclass intArrCls = (*env)->FindClass(env,"[I");
	if (intArrCls == NULL){
		return NULL;	
	}
	//allocate the 1st dimension.
	//It's an array of intArrCls.
	//It's an array of int[]
	result = (*env)->NewObjectArray(env,size,intArrCls,NULL);
	if (result == NULL){
		return NULL;	
	}
	for (i = 0;i < size;i++){
		jint tmp[256];
		int j;
		jintArray iarr = (*env)->NewIntArray(env,size);
		if (iarr == NULL){
			return NULL;		
		}		
		for (j=0;j<size;j++){
			tmp[j] = i+ j;		
		}	
		//set iarr[0..size] to temp
		(*env)->SetIntArrayRegion(env, iarr, 0, size, tmp);
		//set the i-th element of result to be iarr
		(*env)->SetObjectArrayElement(env, result, i, iarr);
		//Delete iarr.
		(*env)->DeleteLocalRef(env,iarr);
	}
	return result;
}
