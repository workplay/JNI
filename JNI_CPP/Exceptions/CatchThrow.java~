class CatchThrow{
	private native void doit()
		throws IllegalArgumentException;
	private void callback() throws NullPointerException{
		throw new NullPointerException("CathThrow.callback");	
	}
	public static void main(String args[]){
		Thread.setDefaultUncaughtExceptionHandler(new UnCaughtExceptionHandler());
		CatchThrow c = new CatchThrow();
		try {
			c.doit();
		} catch (Exception e){
			System.out.println("In Java:\n\t" + e);	
		}
	}
	static {
		System.loadLibrary("CatchThrow");
	}

}
