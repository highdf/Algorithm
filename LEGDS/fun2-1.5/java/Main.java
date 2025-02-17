import java.util.Scanner;

import src.LinkedList;

import src.Node;
import src.MetaNode;

public class Main {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		LinkedList ll = new LinkedList();

		System.out.printf("Please enter length of linkedlist%n");
		int length = scan.nextInt();
		
		System.out.printf("Please enter element of linkedlist%n");
		for(int i = 0;i < length;i ++) {
			int value = scan.nextInt();
			Node node = new Node(value);
			ll.addNode(node);
		}

		Node.print(ll);

		System.out.printf("Please enter you want node of delete%n");
		int index = scan.nextInt();

		ll.deleteNode(index);

		System.out.printf("After node delete%n");
		Node.print(ll);

		scan.close();
	}

}
