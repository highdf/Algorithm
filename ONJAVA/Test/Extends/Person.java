package Extends;

public class Person {
	private String name;
	private int age;

	public Person() {
		;
	}

	public Person(String name,int age) {
		this.setName(name);
		this.setAge(age);
	}

	//set
	public void setName(String name) {
		this.name = name;
	}
	public void setAge(int age) {
		this.age = age;
	}

	//get 
	public String getName() {
		return this.name;
	}
	public int getAge() {
		return this.age;
	}

	public void keepPet(Dog dog,String something) {
		int personAge = this.getAge();
		String personName = this.getName();
		String dogColour = dog.getColour();
		String dogName = dog.getName();

		System.out.printf("%d years ago %s hane a %s and name is %s dog%n",personAge,personName,dogColour,dogName);
		dog.eat(something);
	}

	public void eepPet(Cat cat,String something) {
		int personAge = this.getAge();
		String personName = this.getName();
		String catColour = cat.getColour();
		String catName = cat.getName();

		System.out.printf("%d years old Mr %s hane a %s and name is %s cat%n",personAge,personName,catColour,catName);
		cat.eat(something);
	}
}
