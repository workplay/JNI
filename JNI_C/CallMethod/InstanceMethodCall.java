class InstanceMethodCall{
	private native void nativeMethod();
	private void callback(){
		System.out.println("In Java");
	}
	
	public static void main(String args[]){
		InstanceMethodCall c = new InstanceMethodCall();
		//java call C		
		c.nativeMethod();	
	}
	static{
		System.loadLibrary("InstanceMethodCall");	
	}
}
