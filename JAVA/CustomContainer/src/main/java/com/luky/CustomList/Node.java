package com.luky.CustomList;

public class Node<E> {
	private E data;
	private Node<E> next;

	public Node() {
		this.setData(null);
		this.setNext(null);
	}
	public Node(E data, Node<E> next) {
		this.setNext(next);
		this.setData(data);
	}

	public void setNext(Node<E> next) {
		this.next = next;
	}
	public void setData(E data) {
		this.data = data;
	}
	public E getData() {
		return data;
	}
	public Node<E> getNext() {
		return next;
	}
}
