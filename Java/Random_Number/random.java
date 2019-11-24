import java.lang.Math.*;

class random{
	
	public static void main(String[] args){
		int number=0;
		double random;

		try{
			number = Integer.parseInt(args[0]);
		}
		catch (Exception ex){
			System.out.println ("Error: "+ex);
			return;
		}
		
		random = Math.random();
		number = (int) (number * random);
		System.out.println("Numero: "+ number);
	}
}
