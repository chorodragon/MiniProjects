import java.lang.Math.*;

class flip{
	
	public static void main(String[] args){
		double rand;
		int resultado;

		rand = Math.random();
		resultado = (int) (2 * rand);

		switch(resultado){
			case 0:
				System.out.println("Cara");
				break;
			case 1:
				System.out.println("Escudo");
				break;
			case 2:
				System.out.println("Empate");
				break;
			default:
				System.out.println("Error");
				break;
		}
	}
}
