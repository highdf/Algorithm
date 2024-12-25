package chapter2;

public class Goods{
	private int id;
	private String name;
	private int price;
	private int number;

	//Construct
	public Goods() {
		
	}

	public Goods(int id,int price,int number,String name) {
		this.setId(id);
		this.setPrice(price);
		this.setNumber(number);
		this.setName(name);
	}

	//set
	public void setId(int id) {
		this.id = id;
	}
	public void setName(String name) {
		this.name = name;
	}
	public void setNumber(int number) {
		this.number = number;
	}
	public void setPrice(int price) {
		this.price = price;
	}

	//get
	public int getId() {
		return this.id;
	}
	public int getPrice() {
		return this.price;
	}
	public int getNumber() {
		return this.number;
	}
	public String getName() {
		return this.name;
	}

	public void getInfo() {
		System.out.printf("Id\tName\tPrice\tNumber%n");
		System.out.printf("%d\t%s\t",this.getId(),this.getName());
		System.out.printf("%d\t%d%n",this.getPrice(),this.getNumber());

	}
}
