package com.luky.CustomList;

public interface List<T> {
	public abstract
	boolean add (T element);

	public abstract
	boolean add (int index, T element);

	public abstract
	boolean remove ();

	public abstract
	boolean remove (int index);

	public abstract
	T get (int index);

	public abstract
	int find (T data);

	public abstract
	boolean isContains(T data);

	public abstract
	String toString();
}
