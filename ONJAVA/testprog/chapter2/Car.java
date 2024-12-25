package chapter2;

public class Car{
	private String name;
	private int price;
	private String colour;

	public Car() {

	}

	public Car(String name,int price,String colour) {
		this.setName(name);
		this.setPrice(price);
		this.setColour(colour);
	}

	//set
	public void setName(String name) {
		this.name = name;
	}
	public void setColour(String colour) {
		this.colour = colour;
	}
	public void setPrice(int price) {
		this.price = price;
	}

	//get
	public String getName() {
		return this.name;
	}
	public String getColour() {
		return this.colour;
	}
	public int getPrice() {
		return this.price;
	}

	public void getInfo() {
		System.out.printf("Name\tPrice\tColour%n");
		System.out.printf("%s\t%d\t%s%n",this.getName(),this.getPrice(),
				this.getColour());
		//System.out.printf("%s\t%d\t",this.getName(),this.getPrice());
		//System.out.printf("%s%n",this.getColour());
	}
}

