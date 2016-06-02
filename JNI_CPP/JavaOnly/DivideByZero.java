public class DivideByZero{
	public static void main(String[] args){
		try {
			int d = 5;
			d = d/(d-5);		
		}	
		catch (Exception e){
			e.printStackTrace();
		}
	}
}
