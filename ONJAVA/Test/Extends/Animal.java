package Extends;

public class Animal{
	private String name;
	private String colour;

	public Animal() {
		;
	}
	public Animal(String name,String colour) {
		this.setName(name);
		this.setColour(colour);
	}

	//set
	public void setName(String name) {
		this.name = name;
	}
	public void setColour(String colour) {
		this.colour = colour;
	}

	//get
	public String getName() {
		return this.name;
	}

	public String  getColour() {
		return this.colour;
	}

	public void eat(String something) {
		;
	}
}

