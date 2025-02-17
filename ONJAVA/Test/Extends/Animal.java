package Extends;

public class Animal{
	private String name;
	private int size;

	public Animal() {
		;
	}
	public Animal(String name,int size) {
		this.setName(name);
		this.setSize(size);
	}

	//set
	public void setName(String name) {
		this.name = name;
	}
	public void setSize(int size) {
		this.size = size;
	}

	//get
	public String getName() {
		return this.name;
	}

	public int getSize() {
		return this.size;
	}

	public void eat() {
		System.out.printf("I'm eated%n");
	}

	public void sleep() {
		System.out.printf("I'm sleeped%n");
	}

	public void Zha() {
		System.out.printf("In the Animal:Zha()%n");
	}
}

