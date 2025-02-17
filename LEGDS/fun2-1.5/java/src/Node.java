package src;

import src.LinkedList;
import src.MetaNode;

public class Node extends MetaNode {
	private int data;

	public Node() {
		super();
	}

	public Node(int data) {
		super();
		this.setData(data);
	}

	public void setData(int data) {
		this.data = data;
	}

	public int getData() {
		return this.data;
	}
	@Override
	public Node getNext() {
		return (Node)this.next;
	}

	public static void print(LinkedList ll) {
		Node current = (Node) ll.getHead().getNext();
		int count = 0;

		while( current != null) {
			char separator = (current.getNext() == null)?('\n'):(' ');
			count ++;

			System.out.printf("%d%c",current.getData(),separator);
			if(count % 10 == 0 && current.getNext() != null) {
				System.out.printf("%n");
			}

			current = current.getNext();
		}
	}

	public int findNode(LinkedList ll) {
		int re = 0;
		Node current = (Node) ll.getHead().getNext();

		while(current != null && current.getData() != this.getData()) {
			current = current.getNext();
			re ++;
		}

		if(current == null) {
			re = -1;
		}

		return re;
	}
}
