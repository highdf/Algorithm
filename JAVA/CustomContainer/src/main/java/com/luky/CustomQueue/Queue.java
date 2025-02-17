package com.luky.CustomQueue;

public interface Queue<T>  {
	public abstract boolean push (T data);
	public abstract T pop ();
	public abstract String toString();
}
