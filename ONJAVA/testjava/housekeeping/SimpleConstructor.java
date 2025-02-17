package housekeeping;

public class SimpleConstructor {

	public static void main(String[] args) {
		for(int i = 0;i < 10;i ++) {
			new Rock(i);
		}
	}
}
class Rock{

	Rock(int i) {
		System.out.printf("in the Rock %d %n",i);
	}
}
