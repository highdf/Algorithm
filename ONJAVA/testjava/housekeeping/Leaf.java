package housekeeping;

public class Leaf{

	public static void main(String[] args) {
		Leaf0 leaf = new Leaf0();

		leaf.add().add().add().print();
	}
}

class Leaf0{
	private int i;

	Leaf0(){
		this.i = 0;
	}

	Leaf0 add() {
		this.i ++;

		return this;
	}

	void print() {
		System.out.println("i = " + (i));
	}
}
