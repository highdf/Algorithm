package chapter2;

import java.util.Random;

public class Role{
	private String name;
	private int blood;
	private String gender;
	private String face;

	public Role() {
		;
	}

	public Role(String name,int blood,String gender) {
		this.setName(name);
		this.setBlood(blood);
		this.setGender(gender);
		this.setFace(this.extractFace(gender));
	}

	//set
	public void setName(String name) {
		this.name = name;
	}
	public void setBlood(int blood) {
		this.blood = blood;
	}
	public void setGender(String gender) {
		this.gender = gender;
	}
	public void setFace(String face) {
		this.face = face;
	}

	//get
	public String getName() {
		return this.name;
	}

	public int getBlood() {
		return this.blood;
	}
	public String getGender() {
		return this.gender;
	}
	public String getFace() {
		return this.face;
	}

	private String extractFace(String gender) {
		Random rand = new Random();
		int num = rand.nextInt(5);
		String re;

		String[] boyface = {"帅气","坚毅","凶恶","朴素","普通"};
		String[] girlface = {"魅惑","轻灵","清冷","可爱","秀气"};

		if(gender == "BOY") {
			re = boyface[num];
		} else {
			re = girlface[num];
		}

		return re;
	}

	public void attack(Role role) {
		Random rand = new Random();
		int hurt = rand.nextInt(20) + 1;

		System.out.println(this.getName() + " hit " + (role.getName()));
		System.out.printf("%s %d%n",(role.getName()),(-1*hurt));

		role.setBlood(role.getBlood() - hurt);

		if(role.getBlood() <= 0) {
			System.out.printf("%s is OK",role);
		}
	}
	
	public void printInfo() {
		System.out.printf("%s\t%s\t",this.getName(),this.getGender());
		System.out.printf("%d\t%s%n",this.getBlood(),this.getFace());
	}
}
