package Extends;
import Extends.Animal;

public class Cat extends Animal{
	public Cat() {
		;
	}

	public Cat(String name,String colour) {
		super(name, colour);
	}

	@Override
	public void eat(String something) {
		System.out.printf("Two years age and %s's cat eating %s%n",this.getColour(),something);
	}

	public void catchMouse() {
		System.out.printf("Cat catching mouse%n");	
	}
}
