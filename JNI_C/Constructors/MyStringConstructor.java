class MyStringConstructor{
	private native String MyNewString(char[] chars,int len);
	public static void main(String[] args){
		char[] ch = new char[]{'a','b','c','d','e'};
		String mystring = new MyStringConstructor().MyNewString(ch,5);
		System.out.println(mystring);
	}
	static{
		System.loadLibrary("HelloWorld");	
	}

}
