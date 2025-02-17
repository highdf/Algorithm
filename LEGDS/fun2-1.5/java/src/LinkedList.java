package src;

import src.MetaNode;

public class LinkedList {
	private MetaNode head;
	private MetaNode last;

	public LinkedList() {
		this.setHead();
		this.setLast(this.getHead());
	}

	public void setHead() {
		this.head = new MetaNode();
	}
	public void setLast(MetaNode node) {
		this.last = node;
	}

	public MetaNode getHead() {
		return this.head;
	}
	public MetaNode getLast() {
		return this.last;
	}

	public boolean addNode(MetaNode node) {
		MetaNode last = this.getLast();
		node.setNext(last.getNext());
		last.setNext(node);
		this.setLast(node);

		return true;
	}
	public boolean addNode(MetaNode node,int position) {
		boolean re = true;

		if(position >= 0 ) {
			MetaNode index = this.getHead();
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

	public boolean deleteNode(int index) {
		boolean re = true;

		if(index >= 0) {
			MetaNode previous = this.getHead();
			MetaNode current = this.getHead().getNext();

			while(current != null && index > 0 ) {
				current = current.getNext();
				previous = previous.getNext();
				index --;
			}

			if(current != null) {
				previous.setNext(current.getNext());
			} else {
				re = false;
				System.out.printf("Error:In the deleteNode() of LinkedList%n");
				System.out.printf("argument is error%n");
			}
		} else {
			re = false;
			System.out.printf("Error:In the deleteNode() of LinkedList%n");
			System.out.printf("argument is error%n");
		}

		return re;
	}
}
