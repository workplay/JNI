class CatchThrow{
	private native void doit()
		throws IllegalArgumentException;

	public static void main(String args[]){
		Thread.setDefaultUncaughtExceptionHandler(new UnCaughtExceptionHandler());
		CatchThrow c = new CatchThrow();
		c.doit();
	}
	static {
		System.loadLibrary("CatchThrow");
	}
}
