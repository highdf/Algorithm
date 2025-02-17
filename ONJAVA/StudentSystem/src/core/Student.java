package core;

public class Student{
	private int id;
	private String name;
	private int age;
	private String address;

	public Student() {
		;
	}
	public Student(int id,String name,int age,String address) {
		this.setName(name);
		this.setAge(age);
		this.setId(id);
		this.setAddress(address);
	}

	//set
	public boolean setName(String name) {
		this.name = name;
		return true;
	}
	public boolean setAge(int age) {
		boolean re = true;
		if(age > 0 && age < 20) {
			this.age = age;
		} else {
			System.out.printf("Age is error%n");
			re = false;
		}

		return re;
	}
	public boolean setId(int id) {
		boolean re = true;

		if(id >= 0) {
			this.id = id;
		} else {
			System.out.printf("Id is error%n");
			re = false;
		}
		return re;
	}
	public boolean setAddress(String address) {
		this.address = address;
		return true;
	}

	//get
	public String getName() {
		return this.name;
	}
	public int getAge() {
		return this.age;
	}
	public int getId() {
		return this.id;
	}
	public String getAddress() {
		return this.address;
	}

	public void getInfo() {
		System.out.printf("Id\t\tName%n");
		System.out.printf("%d\t\t%s%n",this.getId(),this.getName());
		System.out.printf("Age\t\tAddress%n");
		System.out.printf("%d\t\t%s%n",this.getAge(),this.getAddress());
	}
}
