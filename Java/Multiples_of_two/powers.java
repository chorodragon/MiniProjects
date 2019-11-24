import java.util.*;

class powers{
	
	public static void main(String[] args){
		int powers = 0;
	
		try{
			System.out.println("Se imprimiran todos los valores multiplos de 2 que sean menores a " + args[0]);
		
			for (int aux = 1; powers < Integer.parseInt(args[0]); aux++){
				System.out.println("Valor: " + powers);
				powers = aux * 2;
			}
		}
		catch(Exception ex){
				System.out.println("Error: "+ex);
		}
	}
}
