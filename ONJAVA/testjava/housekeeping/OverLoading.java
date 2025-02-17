package housekeeping;

public class OverLoading{

	public static void main(String[] args) {
		for(int i = 0;i < 10;i ++) {
			Tree tree = new Tree(i);
			tree.info();
			tree.info(i);
		}
	}
}

class Tree{
	int high;

	Tree(int i) {
		this.high = i;
	}

	void info() {
		System.out.println("The is small tree");
	}

	void info(int i) {
		System.out.println("High is " + (i));
	}
}
