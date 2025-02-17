package core;

public class User{
	String name;
	String password;
	String idcode;
	String phone;

	public User() {
		;
	}
	public User(String name,String password,String idcode,String phone) {
		this.setName(name);
		this.setPassword(password);
		this.setIdcode(idcode);
		this.setPhone(phone);
	}

	public void setName(String name) {
		this.name = name;
	}
	public void setPassword(String password) {
		this.password = password;
	}
	public void setIdcode(String idcode) {
		this.idcode = idcode;
	}
	public void setPhone(String phone) {
		this.phone = phone;
	}

	public String getName() {
		return this.name;
	}
	public String getPassword() {
		return this.password;
	}
	public String getIdcode() {
		return this.idcode;
	}
	public String getPhone() {
		return this.phone;
	}

	public void getInfo() {
		System.out.printf("Name\t\tidcode%n");
		System.out.printf("%s\t\t%s%En",this.getName(),this.getIdcode());
		System.out.printf("Password\t\tPhone%n");
		System.out.printf("%s\t\t%s%n",this.getPassword(),this.getPhone());
	}

	public static boolean checkName(String name) {
		boolean re = true;

		if( name.length() >= 3 && name.length() <= 15) {
			for(int i = 0;i < name.length();i ++) {
				if(isCharOrNumber(name.charAt(i)) == false) {
					re = false;
					break;
				}
			}
		} else {
			re = false;
		}

		return re;
	}

	public static boolean checkIdcode(String idcode) {
		boolean re = true;

		if(idcode.length() == 18 && idcode.charAt(0) != '0' && is(idcode.charAt(17)) == true) {
			for(int i = 0;i < 17;i ++ ) {
				if(isNumber(idcode.charAt(i)) == false) {
					re = false;
					break;
				}
			}
		} else {
			re = false;
		}

		return re;
	}

	public static boolean checkPhone(String phone) {
		boolean re = true;

		if(phone.length() == 11 && phone.charAt(0) != '0') {
			for(int i = 0;i < 11;i ++) {
				if(isNumber(phone.charAt(i)) == false) {
					re = false;
					break;
				}
			}
		} else {
			re = false;
		}

		return re;
	}

	private static boolean isNumber(char c) {
		boolean re = true;

		if(c < '0' || c > '9') {
			re = false;
		}

		return re;
	}

	private static boolean isChar(char c) {
		boolean re = true;

		if(c < 'A' || (c > 'Z' && c < 'a') || c > 'z') {
			re = false;
		}
		return re;
	}

	private static boolean isCharOrNumber(char c) {
		return isChar(c) || isNumber(c);
	}
}
