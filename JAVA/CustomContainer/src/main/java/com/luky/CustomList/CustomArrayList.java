package com.luky.CustomList;

import java.util.Iterator;

public class CustomArrayList<T>
implements Iterable<T>, List<T>
{
	private Object[] elements;
	private int size;
	private int last;

	public CustomArrayList() {
		Object[] elements = new Object[10];
		this.setSize(10);
		this.setElements(elements);
		this.setLast(-1);
	}
	public CustomArrayList(int size) {
		Object[] elements =  new Object[size];
		this.setSize(size);
		this.setElements(elements);
		this.setLast(-1);
	}

	public void setSize(int size) {
	    this.size = size;
	}
	public void setLast(int last) {
	    this.last = last;
	}
	public void setElements(Object[] elements) {
	    this.elements = elements;
	}
	public int getSize() {
	    return size;
	}
	public int getLast() {
	    return last;
	}
	public Object[] getElements() {
	    return elements;
	}
	public void getInfo() {
		int size = this.getSize();
		int last = this.getLast();

		System.out.printf("Size = %d, Last = %d%n", size, last);
	}
	@SuppressWarnings("unchecked")
	public T get (int index) {
		return  (T) this.getElements()[index];
	}
	public boolean isFull() {
		return (this.getLast() + 1 == this.getSize());
	}
	public boolean isEmpty() {
		return (this.getLast() == -1);
	}
	public boolean add (T element) {
		boolean re = false;

		if (this.isFull() == false) {
			int next_index = this.getLast() + 1;

			this.getElements()[next_index] = element;
			this.setLast(next_index);
			re = true;
		} else {
			throw new IndexOutOfBoundsException("In the ArrayList.add(T elements): The arraylist is full");
		}

		return re;
	}
	public boolean add (int index, T element) {
		boolean re = false;
		StringBuilder str = new StringBuilder("In the ArrayList.add (index, element):%n");

		if (this.isFull() == false ) {
			
			if (index <= (this.getLast() + 1) && index >= 0)  {
				for(int i = this.getLast() + 1;i > index ;i --) {
					int prev_index = i - 1;
					Object[] elements = this.getElements();
					elements[i] = elements[prev_index];
				}
				this.getElements()[index] = element;
				int last = this.getLast() + 1;
				this.setLast(last);
			} else  {
				str.append("Index OUt bounds");
				throw new IndexOutOfBoundsException(str.toString());
			}
		} else {
			str.append("The arraylist is full%n");
			throw new IndexOutOfBoundsException(str.toString());
		}

		return re;
	}

	public  boolean remove() {
		boolean re = false;
		StringBuilder str = new StringBuilder("In the ArrayList.remove()%n");

		if (this.isEmpty() == false) {
			int new_last = this.getLast() - 1;
			this.setLast(new_last);
		} else {
			str.append("The arraylist is empty%n");
			throw new IndexOutOfBoundsException(str.toString());
		}

		return re;
	}
	public boolean remove(int index) {
		boolean re = false;
		StringBuilder str = new StringBuilder("In the ArrayList.remove()%n");

		if (this.isEmpty() == false) {

			if (index >= 0 && index <= this.getLast())  {
				Object[] elements = this.getElements();
				for(int i = index + 1; i <= this.getLast();i ++) {
					elements[i - 1] = elements[i];
				}

				int last = this.getLast() - 1;
				this.setLast(last);
			} else  {
				str.append("Index out of bounds");
				throw new IndexOutOfBoundsException(str.toString());
			}
		} else {
			str.append("The arraylist is full");
			throw new IndexOutOfBoundsException(str.toString());
		}

		return re;
	}
	public boolean isContains(T element) {
		boolean ret = true;
		int index = this.find(element);

		if (index == -1) {
			ret = false;
		}

		return ret;
	}

	public int find(T element) {
		int re = -1;
		Object[] elements = this.getElements();

		for(int i = 0;i <= this.getLast();i ++ ) {
			if(elements[i].equals(element)) {
				re = i;
				break;
			}
		}

		return re;
	}
	public String toString() {
		StringBuilder re = new StringBuilder("[");
		Iterator<T> iterator = this.iterator();
		while (iterator.hasNext() == true) {
			T value = iterator.next();
			re.append(value.toString());
			if (iterator.hasNext() == true) {
				re.append(", ");
			}
		}
		re.append("]");
		return re.toString();
	}

	public Iterator<T> iterator() {
		return new ArrayList_Iterator();
	}

	private class ArrayList_Iterator implements Iterator<T> {
		private int current_index;

		public ArrayList_Iterator() {
			this.current_index = 0;
		}

		@Override
		public boolean hasNext() {
			boolean re = false;

			if (this.current_index <= CustomArrayList.this.getLast()) {
				re = true;
			}

			return re;
		}

		@SuppressWarnings("unchecked")
		public T next() {
			T re = null;
			if (this.hasNext() == true) {
				int current_index = this.current_index;
				re = (T) CustomArrayList.this.getElements()[current_index];
				this.current_index ++;
			}

			return re;
		}
	}
}
