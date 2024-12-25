package chapter2;

public class ShenFenZheng{
	String number;

	public ShenFenZheng(String number) {
		this.setNumber(number);
	}

	//set 
	public void setNumber(String number) {
		if(number.length() == 18) {
			this.number = number;
		} else {
			System.out.printf("Error:In the setNumbre: ");
			System.out.printf("number is error%n");
		}
	}

	//get 
	public String getNumber() {
		return this.number;
	}

	public String getBlock(int start,int end) {
		String re = "";

		for(int i = start;i <= end;i ++) {
			re += this.getNumber().charAt(i);
		}

		return re;
	}

	public String getBlock(int i) {
		String re = "";

		re += this.getNumber().charAt(i);

		return re;
	}
}
