package src;

public class MetaNode{
	protected MetaNode next;

	public MetaNode() {
		this.setNext(null);
	}
	public MetaNode(MetaNode next) {
		this.setNext(next);
	}

	public void setNext(MetaNode next) {
		this.next = next;
	}

	public MetaNode getNext() {
		return this.next;
	}
}
