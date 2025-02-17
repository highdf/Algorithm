package src;

public class NodeOfLinkedList{
	protected NodeOfLinkedList next;

	public NodeOfLinkedList() {
		this.setNext(null);
	}
	public NodeOfLinkedList(NodeOfLinkedList next) {
		this.setNext(next);
	}

	public void setNext(NodeOfLinkedList next) {
		this.next = next;
	}

	public NodeOfLinkedList getNext() {
		return this.next;
	}
}
