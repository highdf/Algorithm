package operators;

public class Casting{

	public static void main(String[] args) {
		int i = 200;
		long log = i;
		log = (long) i;
		
		i = (int)log;
	}
}
