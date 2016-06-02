class InstanceOfMethodCall{
	private static native void initIDs();

	Static{
		System.loadLibrary("InstanceOfMethodCall");
		initIDs();
	}
}



in .c file,
jmethodID mid;

initIDs(JNIEnv *env, jclass cls){
	mid = (*env)->GetMethodID(env, cls, "METHOD_NAME","()V");
}
