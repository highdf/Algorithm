package src;

import src.NodeOfLinkedList;

public class LinkedList {
	private NodeOfLinkedList head;
	private NodeOfLinkedList last;

	public LinkedList() {
		this.setHead();
		this.setLast(this.getHead());
	}

	public void setHead() {
		this.head = new NodeOfLinkedList();
	}
	public void setLast(NodeOfLinkedList node) {
		this.last = node;
	}

	public NodeOfLinkedList getHead() {
		return this.head;
	}
	public NodeOfLinkedList getLast() {
		return this.last;
	}

	public boolean addNode(NodeOfLinkedList node) {
		NodeOfLinkedList last = this.getLast();
		node.setNext(last.getNext());
		last.setNext(node);
		this.setLast(node);

		return true;
	}
	public boolean addNode(NodeOfLinkedList node,int position) {
		boolean re = true;

		if(position >= 0 ) {
			NodeOfLinkedList index = this.getHead();
			while(position > 0 && index != null) {
				index = index.getNext();
				position --;
			}

			if(index != null) {
				if(index.getNext() == null) {
					this.setLast(node);
				}
				node.setNext(index.getNext());
				index.setNext(node);
			} else {
				re = false;
				System.out.printf("Error:In the LinkedList.insertNode:%n");
				System.out.printf("Argument position is Overflow%n");
			}
		} else {
				re = false;
				System.out.printf("Error:In the LinkedList.insertNode:%n");
				System.out.printf("Argument position is Overflow%n");
		}

		return re;
	}
}
