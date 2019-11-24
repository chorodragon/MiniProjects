
import static java.lang.Math.sqrt;

public class EcuacionCuadratica {

    public static void main(String[] args) {
            if(args.length < 3)
            {
                System.out.println("Error, muy pocos argumentos.");
                return;
            }
            try
            {
                long a = Long.valueOf(args[0]);
                long b = Long.valueOf(args[1]);
                long c = Long.valueOf(args[2]);
                long discriminante = (long) sqrt((b*b) - (4*a*c));
                long r1 = (-b + discriminante) / (long)(2.0 * a);
                long r2 = (-b - discriminante) / (long)(2.0 * a);
                System.out.println("Respuestas: ");
                System.out.println("Respuesta 1: "+ r1);
                System.out.println("Respuesta 2: "+ r2);
            }
            catch (Exception ex)
            {
                System.out.println("Error de tipo de datos.");
                return;
            }
            
    }
    
}
