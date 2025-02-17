package com.luky.CustomList;

import java.util.Iterator;
import com.luky.CustomList.Node;

public class CustomLinkedList<T>
implements Iterable<T>, List<T>
{
	private Node<T> head;
	private Node<T> last;

	public CustomLinkedList() {
		Node<T> node = new Node<>();
		this.setHead(node);
		this.setLast(node);
	}

	public void setHead(Node<T> head) {
	    this.head = head;
	}
	public void setLast(Node<T> last) {
	    this.last = last;
	}
	public Node<T> getHead() {
	    return head;
	}
	public Node<T> getLast() {
	    return last;
	}

	public boolean isEmpty() {
		return (this.getHead().getNext() == null);
	}
	public boolean add(T data) {
		Node<T> new_node = new Node<T>(data, null);
		Node<T> last = this.getLast();
		last.setNext(new_node);
		this.setLast(new_node);

		return true;
	}
	public boolean add(int index, T data) {
		Node<T> current_node = this.findPrevNode(index);

		Node<T> new_node = new Node<T>(data, current_node.getNext());
		current_node.setNext(new_node.getNext());

		if (current_node == this.getLast()) {
			this.setLast(new_node);
		}
		return true;
	}
	public boolean remove() {
		boolean ret = false;

		if (this.isEmpty() == false) {
			Node<T> current_node = this.getHead();
			while (current_node.getNext() != this.getLast()) {
				current_node = current_node.getNext();
			}
			current_node.setNext(null);
			this.setLast(current_node);
			ret = true;
		} else {
			throw new IndexOutOfBoundsException("In the CustomLinkedList.remove(): The LinkedList is empty");
		}
		return ret;
	}
	public boolean remove(int index) {
		boolean re = false;
		Node<T> prev_node = this.findPrevNode(index);

		if (this.isEmpty() == false && prev_node != null && prev_node.getNext() != null) {
			Node<T> target_node = prev_node.getNext();
			prev_node.setNext(target_node.getNext());

			if (target_node == this.getLast()) {
				this.setLast(prev_node);
			}
		} else {
			throw new IndexOutOfBoundsException("In the CustomLinkedList.remove(): The LinkedList is empty");
		}

		return re;
	}
	public int find (T data) {
		int ret = -1;
		Node<T> current_node = this.getHead().getNext();

		while (current_node != null) {
			ret ++;
			if (current_node.getData().equals(data) == true) {
				break;
			}	
			current_node = current_node.getNext();
		}
		if (current_node == null) {
			ret = -1;
		}

		return ret;
	}
	public boolean isContains(T data) {
		boolean ret = true;
		int index = this.find(data);

		if (index == -1) {
			ret = false;
		}

		return ret;
	}
	public Iterator<T> iterator() {
		return new LinkedList_Iterator();
	}
	public String toString () {
		StringBuilder ret = new StringBuilder();
		Iterator<T> iterator = this.iterator();

		ret.append("[");
		while (iterator.hasNext() == true) {
			T data = iterator.next();
			ret.append(data.toString());
			if (iterator.hasNext() == true) {
				ret.append(", ");
			}
		}
		ret.append("]");

		return ret.toString();
	}
	public T get (int index) {
		T ret = null;
		Node<T> prev_node = findPrevNode(index);
		
		if (prev_node != null && prev_node.getNext() != null) {
			ret = prev_node.getNext().getData();
		} else {
			throw new IndexOutOfBoundsException("In the CustomLinkedList.get (): OUt Bounds");
		}

		return ret;
	}

	private Node<T> findPrevNode(int index) {
		Node<T> current_node = this.getHead();

		while (current_node != null && index > 0) {
			current_node = current_node.getNext();
			index --;
		}

		return current_node;
	}

	private class LinkedList_Iterator implements Iterator<T> {
		private Node<T> current_node;

		public LinkedList_Iterator() {
			this.setCurrent_node(CustomLinkedList.this.getHead());
		}
		public void setCurrent_node(Node<T> current_node) {
		    this.current_node = current_node;
		}
		public Node<T> getCurrent_node() {
		    return current_node;
		}
		public boolean hasNext() {
			boolean ret = false;

			if (this.getCurrent_node().getNext() != null) {
				ret = true;
			}

			return ret;
		}
		public T next() {
			T ret = null;

			if (this.hasNext() == true) {
				ret = this.getCurrent_node().getNext().getData();
				this.setCurrent_node(this.getCurrent_node().getNext());
			}

			return ret;
		}

	}
}
