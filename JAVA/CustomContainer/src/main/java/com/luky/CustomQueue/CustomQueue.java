package com.luky.CustomQueue;

import java.util.Iterator;

import com.luky.CustomList.Node;

public class CustomQueue<T>
implements Iterable<T>, Queue<T>
{
	private Node<T> head;
	private Node<T> tail;

	public CustomQueue() {
		this.setHead(null);
		this.setTail(null);
	}

	public void setTail(Node<T> tail) {
	    this.tail = tail;
	}
	public void setHead(Node<T> head) {
	    this.head = head;
	}
	public Node<T> getTail() {
	    return tail;
	}
	public Node<T> getHead() {
	    return head;
	}

	public boolean isEmpty() {
		return (this.getHead() == null);
	}
	public boolean push (T data) {
		Node<T> new_node = new Node<>(data, null);

		if (this.isEmpty() == true) {
			this.setHead(new_node);
		} else {
			this.getTail().setNext(new_node);
		}
		this.setTail(new_node);

		return true;
	}
	public T pop () {
		T ret = null;

		if (this.isEmpty() == false) {
			ret = this.getHead().getData();
			this.setHead(this.getHead().getNext());
		} else {
			StringBuilder str = new StringBuilder("In the CustomQueue%n");
			str.append("The queue is empty%n");
			throw new IndexOutOfBoundsException(str.toString());
		}

		return ret;
	}
	public Iterator<T> iterator () {
		return new CustomIterator();
	}
	public String toString () {
		StringBuilder ret = new StringBuilder();

		ret.append("[");
		Iterator<T> iterator = this.iterator();
		while (iterator.hasNext() == true) {
			T data = iterator.next();
			ret.append(data.toString());

			if (iterator.hasNext() == true)  {
				ret.append(", ");
			}
		}
		ret.append("]");

		return ret.toString();
	}
	public void String()  {
		Node<T> current_node = this.getHead();

		while (current_node != null)  {
			current_node = current_node.getNext();
		}
	}

	private class CustomIterator implements Iterator<T> {
		private Node<T> current_node;

		public CustomIterator() {
			this.setCurrent_node(CustomQueue.this.getHead());
		}
		public void setCurrent_node(Node<T> current_node) {
		    this.current_node = current_node;
		}
		public Node<T> getCurrent_node() {
		    return current_node;
		}
		public boolean hasNext () {
			return this.getCurrent_node() != null;
		}
		public T next () {
			T ret = null;

			if (this.hasNext() == true) {
				// this.getInfo();;
				ret = this.getCurrent_node().getData();
				this.setCurrent_node(this.getCurrent_node().getNext());
			}

			return ret;
		}
	}
}
