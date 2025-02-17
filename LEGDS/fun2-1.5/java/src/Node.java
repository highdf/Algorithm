package src;

import src.NodeOfLinkedList;

public class Node extends NodeOfLinkedList {
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
}
