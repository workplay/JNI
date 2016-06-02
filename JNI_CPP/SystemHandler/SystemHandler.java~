class SystemHandler{
	private native void print();
	public static void main(String[] args){
		SystemHandler sh = new SystemHandler();
		try{
			sh.print();	
		}
		catch (Exception e){
			System.out.println("In Java:\n\t" + e);	
		}
	}
	static{
		System.loadLibrary("SystemHandler");	
	}
}
