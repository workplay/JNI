import java.lang.management.ManagementFactory; 
class ShowPID{
	private native void print();
	public static void main(String[] args){
		//First, we use java.lang.management.ManagementFactory to show the pid of java progress.
		String name = ManagementFactory.getRuntimeMXBean().getName();  
		System.out.println("Progress id in Java \n\t"+name);  		
		new ShowPID().print();	
	}

	static{
		System.loadLibrary("ShowPID");	
	}

}
