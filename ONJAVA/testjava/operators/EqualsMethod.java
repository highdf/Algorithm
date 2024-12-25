package operators;

public class EqualsMethod{

	public static void main(String[] args) {
		ValA v0 = new ValA();
		ValA v1 = new ValA();
		ValB v2 = new ValB();
		ValB v3 = new ValB();

		v0.i = v1.i = 2;
		v2.i = v3.i = 4;

		System.out.println("ValA:v0.Equals(b1)" + (v0.equals(v1)));
		System.out.println("ValB:v1.equals(v3)" + (v2.equals(v3)));

	}
}
class ValA{
	int i;
}
class ValB{
	int i;

	public boolean equals(Object o) {
		ValB v = (ValB)o;
		return (v.i == this.i);
	}
}
