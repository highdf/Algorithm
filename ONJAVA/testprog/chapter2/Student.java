package chapter2;

public class Student {
	private String number;
	private String name;
	private int age;

	public Student() {

	}

	public Student(String number,String name,int age) {
		this.setNumber(number);
		this.setName(name);
		this.setAge(age);
	}

	//set
	public void setNumber(String number) {
		this.number = number;
	}
	public void setName(String name) {
		this.name = name;
	}
	public void setAge(int age) {
		this.age = age;
	}

	//get
	public String getNumber() {
		return this.number;
	}
	public String getName() {
		return this.name;
	}
	public int getAge() {
		return this.age;
	}
	public void getInfo() {
		System.out.printf("Number\tName\tAge%n");
		System.out.printf("%s\t%s\t%d%n",this.getNumber(),this.getName(),this.getAge());

	}
}
