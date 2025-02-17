import java.util.Scanner;

import src.LinkedList;

import src.Node;
import src.NodeOfLinkedList;

public class Main {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		LinkedList ll = new LinkedList();

		System.out.printf("Please enter length of array%n");
		int length = scan.nextInt();

		System.out.printf("Please enter a array%n");
		for(int i = 0;i < length;i ++) {
			int data = scan.nextInt();
			Node node = new Node(data);
			ll.addNode(node);
			System.out.printf("ll.getHead() = %h,ll.getLast() = %h\n",ll.getHead(),ll.getLast());
		}

		System.out.printf("Please enter a number%n");
		Node node = new Node(scan.nextInt());

		int position = Main.findNode(ll, node);
		ll.addNode(node, position);

		System.out.printf("Insert after %n");
		NodeOfLinkedList head = ll.getHead();
		while( (head = head.getNext()) != null) {
			char c = (head.getNext() == null)?('\n'):(' ');
			System.out.printf("%d%c",head.getData(),c);
		}
	}

	public static int findNode(LinkedList ll,Node node) {
		int re = 0;
		Node index = (Node)ll.getHead();

		do {
			index = index.getNext();
			re ++;
		} while(index != null && index.getData() <= node.getData());
		
		if(index == null) {
			re --;
		}

		return re;
	}
}
