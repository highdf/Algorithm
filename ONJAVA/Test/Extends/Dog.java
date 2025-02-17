package Extends;

import Extends.Animal;

public class Dog extends Animal{
	public Dog() {
		;
	}

	public Dog(String name,String colour) {
		super(name,colour);
	}

	@Override
	public void eat(String something) {
		System.out.printf("Two years age and %s's dog eating %s%n",this.getColour(),something);
	}

	public void lookHome() {
		System.out.printf("Dog looking the home%n");
	}
}
