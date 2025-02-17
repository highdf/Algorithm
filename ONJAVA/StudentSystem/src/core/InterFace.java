package core;

import java.util.Random;
import java.util.ArrayList;
import java.util.Scanner;

public class InterFace{
	private ArrayList<User> list;	
	private User user;

	public InterFace() {
		this.setList();
	}

	public void setList() {
		this.list = new ArrayList<User>();
	}
	public void setUser(User user) {
		this.user = user;
	}

	public ArrayList<User> getList() {
		return this.list;
	}
	public User getUser() {
		return this.user;
	}

	public void welcome() {
		System.out.printf("WelCome to the Student System%n");
	}
	public void menu() {
		System.out.printf("%n");
		System.out.printf("\"1 login%n");
		System.out.printf("\"2 register%n");
		System.out.printf("\"3 forget the password%n");
		System.out.printf("\"4 quit interface%n");
		System.out.printf("Please enter your choose:");
	}

	public void into(Scanner scan) {
		boolean re;
		this.welcome();

		do{
			this.menu();
			String choose = scan.next();
			re = this.options(scan,choose);
		} while(re == false);
	}

	private boolean options(Scanner scan,String choose) {
		boolean re = true;

		switch(choose) {
			case "1":{
				re = this.logIn(scan);
				break;
			}
			case "2":{
				this.register(scan);
				re = false;
				break;
			}
			case "3":{
				this.findPassword(scan);
				re = false;
				break;
			}
			case "4":{
				System.out.printf("GoodBye%n");
				System.exit(0);
				break;
			}
			default :{
				System.out.printf("The command is error%n");
				System.out.printf("Pleace enter carrect command%n");
				re = false;
			}
		}

		return re;
	}

	private int findName(String name) {
		int index = -1;

		for(int i = 0;i < this.getList().size();i ++) {
			if(this.getList().get(i).getName().equals(name)) {
				index = i;
				break;
			}
		}

		// System.out.printf("index = %d%n",index);
		return index;
	}

	//get
	private String getName(Scanner scan) {
		System.out.printf("Please enter your name%n");
		return scan.next();
	}
	private String getIdcode(Scanner scan) {
		System.out.printf("Please enter your idcode%n");
		return scan.next();
	}
	private String getPhone(Scanner scan) {
		System.out.printf("Please enter your phone%n");
		return scan.next();
	}
	private String getPassword(Scanner scan) {
		System.out.printf("Please enter your Password%n");
		return scan.next();
	}

	// begin
	// mark a
	private boolean logIn(Scanner scan) {
		int number = 3;
		boolean re = false;
		boolean label = false;

		do{
			String name = this.getName(scan);
			String password = this.getPassword(scan);

			this.isCode(scan);

			int index = findName(name);

			if(index >= 0) {
				boolean re0 = this.isPassword(password,index);
				if(re0 == true) {
					label = true;
					re = true;
					this.setUser(this.getList().get(index));
					System.out.printf("Log in sucseeded%n");
				} else if(number > 0) {
					number --;
					System.out.printf("You can also %d times%n",number);
				} else if(number == 0) {
					System.out.printf("The number of attempts has exceeded three%n");
					System.out.printf("Please use forget password%n");
					label = true;
				}
			} else {
				System.out.printf("The username is unregistered%n");
				System.out.printf("Please registered%n");
				re = false;
				label = true;
			}
		}while(label == false);

		return re;
	}

	private boolean isPassword(String password,int index) {
		User user = this.getList().get(index);

		return user.getPassword().equals(password);
	}

	private void isCode(Scanner scan) {
		do {
			String code = this.getCode();
			System.out.printf("Code is %s%n",code);
			System.out.printf("Please enter code:");
			String usercode = scan.next();
			if(code.equals(usercode) == true) {
				break;
			} else {
				System.out.printf("Enter is error%n");
				System.out.printf("Please enter again%n");
			}
		} while(true);
	}

	private String getCode() {
		Random rand = new Random();
		int index = rand.nextInt(5);
		char[] code = new char[5];
		char[] arr = {'a','A'};

		for(int i = 0;i < code.length;i ++) {
			int i0 = rand.nextInt(2);
			int offset = rand.nextInt(26);
			code[i] = (char)(arr[i0] + offset);
		}
		code[index] = (char)('0' + rand.nextInt(10));

		String re = new String(code);

		return re;
	}
	
	// begin 
	// mark b
	private void register(Scanner scan) {
		String name = readName(scan);
		String idcode = readIdcode(scan);
		String phone = readPhone(scan);
		String password = readPassword(scan);

		User user = new User(name,password,idcode,phone);
		this.getList().add(user);

		System.out.printf("Congratulations register successfully%n");
	}

	private String readName(Scanner scan) {
		String re = "";
		boolean label = true;
		
		do{
			String name = this.getName(scan);

			if(User.checkName(name) == true) {
				int index = findName(name);

				if(index > 0) {
					label = false;
					System.out.printf("The name is already exist%n");
					System.out.printf("Please enter again%n");
				} else {
					re = name;
					label = true;
				}
			} else {
				label = false;
				System.out.printf("The name's famat is error%n");
				System.out.printf("Please enter again%n");
			}
			//int index = findName(name);
			//if(index > 0) {
			//	label = false;
			//	System.out.printf("The name is already exist%n");
			//	System.out.printf("Please enter again%n");
			//} else if(User.checkName(name) == false) {
			//	label = false;
			//	System.out.printf("The name's famat is error%n");
			//	System.out.printf("Please enter again%n");
			//} else {
			//	re = name;
			//	label = true;
			//}
		} while(label == false);

		return re;
	}

	private String readPassword(Scanner scan) {
		String re = "";
		boolean label = true;

		do{
			String password0 = this.getPassword(scan);
			System.out.printf("Please enter again%n");
			String password1 = scan.next();
			if(password0.equals(password1) == false) {
				label = false;
				System.out.printf("The first times is differant from sencond%n");
				System.out.printf("Please enter again%n");
			} else {
				re = password0;
				label = true;
			}
		} while(label == false);

		return re;
	}

	private String readIdcode(Scanner scan) {
		String re = "";
		boolean label = true;
		
		do{
			System.out.printf("Please enter your idcode%n");
			String idcode = scan.next();
			if(User.checkIdcode(idcode) == true) {
				label = true;
				re = idcode;
			} else {
				label = false;
				System.out.printf("The idcode is error%n");
				System.out.printf("Please enter again%n");
			}
		} while(label == false);

		return re;
	}

	private String readPhone(Scanner scan) {
		String re = "";
		boolean label = true;

		do{
			String phone = this.getPhone(scan);
			if(User.checkPhone(phone) == true) {
				re = phone;
				label = true;
			} else {
				label = false;
				System.out.printf("The phone is error%n");
				System.out.printf("Please enter again%n");
			}
		} while(label == false);

		return re;
	}

	// Forget Password
	// mark c
	private void  findPassword(Scanner scan) {
		String name = this.getName(scan);
		int index = this.findName(name);

		if(index >= 0) {
			String idcode = this.getIdcode(scan);
			String phone = this.getPhone(scan);

			User user = this.getList().get(index);

			if(user.getIdcode().equals(idcode) == true && user.getPhone().equals(phone) == true) {
				do{
					String password0 = this.getPassword(scan);
					System.out.printf("Plese enter again%n");
					String password1 = scan.next();
					if(password0.equals(password1) == true) {
						System.out.printf("The password is successfully retrieved%n");
						this.getList().get(index).setPassword(password1);
						break;
					} else {
						System.out.printf("The two inputs are inconsistent%n");
						System.out.printf("Please enter again%n");
					}
				}while(true);
			} else {
				System.out.printf("Failed to retrieved the password%n");
				System.out.printf("The idcode or phone is error%n");
			}
		} else {
			System.out.printf("Failed to retrieved the password%n");
			System.out.printf("The user's name is not find%n");
			System.out.printf("Please register%n");
		}
	}
}
