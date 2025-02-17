package core;

import java.util.ArrayList;
import java.util.Scanner;

public class Home{
	private ArrayList<Student> list;

	public Home() {
		this.setList();
	}

	public void setList() {
		this.list = new ArrayList<Student>();
	}
	public ArrayList<Student> getList() {
		return this.list;
	}

	public void into(Scanner scan) {
		this.welcome();

		do{
			this.menu();
			String choose = scan.next();
			this.options(scan,choose);
		}while(true);
	}

	private  void welcome() {
		System.out.printf("\"-------WelCome Student System-------\"%n");
	}

	private void menu() {
		System.out.printf("%n");
		System.out.printf("\"1 add student%n");
		System.out.printf("\"2 delete student%n");
		System.out.printf("\"3 change student%n");
		System.out.printf("\"4 print student%n");
		System.out.printf("\"5 quit%n");
		System.out.printf("\"6 help%n");
		System.out.printf("Pleanse enter your choose:\"");
	}

	private void options(Scanner scan,String choose) {
		boolean re = true;

		switch(choose) {
			case "1":{
				Student student;
				student = getStudent(scan);

				if(addStudent(student) == true) {
					System.out.printf("addStudent true%n");
				} else {
					System.out.printf("addStudent false%n");
				}
				break;
			}
			case "2":{
				int id;
				while( (id = getId(scan)) < 0) {
					System.out.printf("error:please enter again%n");
				}

				if( deleteStudent(id) == true) {
					System.out.printf("deleteStudent true%n");
				} else {
					System.out.printf("deleteStudent false%n");
				}
				break;
			}
			case "3":{
				int id;
				while( (id = getId(scan)) < 0) {
					System.out.printf("error:please enter again%n");
				}

				if(findId(id) < 0) {
					Student newstudent = getStudent(scan);
					if(changeStudent(id,newstudent) == true) {
						System.out.printf("changeStudent true%n");
					} else {
						System.out.printf("changeStudent false%n");
					}
				} else {
					System.out.printf("The id already exist%n");
				}
				break;
			}
			case "4":{
				int id;
				while( (id = getId(scan)) < 0) {
					System.out.printf("error:please enter again%n");
				}
				if(printStudent(id) == true) {
					System.out.printf("print student true%n");
				} else {
					System.out.printf("print student false%n");
				}
				break;
			}
			case "5":{
				System.out.printf("GoogBye!!!%n");
				System.exit(0);
				break;
			}
			case "6":help();break;
			default:System.out.printf("Enter command is error%n");
		}

	}

	// "1
	private Student getStudent(Scanner scan) {
		System.out.printf("Please enter %n");
		System.out.printf("Id:");
		int id = scan.nextInt();

		System.out.printf("Name:");
		String name = scan.next();

		System.out.printf("Age:");
		int age = scan.nextInt();

		System.out.printf("Home address:");
		String add = scan.next();

		Student re = new Student(id,name,age,add);
		return re;
	}
	private boolean addStudent(Student student) {
		boolean re = true;
		int index = 0;

		index = findId(student.getId());
		if(index >= 0) {
			System.out.printf("Id is already exist%n");
			re = false;
		} else {
			this.getList().add(student);		
		}
		return re;
	}

	// "2
	private int getId(Scanner scan) {
		System.out.printf("Pleasen student's id%n");
		return scan.nextInt();
	}
	private boolean deleteStudent(int id) {
		boolean re = false;
		int index = findId(id);

		if(index >= 0) {
			this.getList().remove(index);
			re = true;
		} else {
			System.out.printf("In the deleteStudent():No find id in the ArrrayList%n");
			re = false;
		}

		return re;	
	}

	// "3
	private boolean changeStudent(int id,Student student) {
		boolean re = true;
		int index = findId(id);

		if(index >= 0) {
			this.getList().set(index,student);	
		} else {
			System.out.printf("In the changeStudent():No find id in the ArrrayList%n");
			re = false;
		}

		return re;
	}

	// "4
	private boolean printStudent(int id) {
		boolean re = true;
		int index = findId(id);

		if(index >= 0) {
			this.getList().get(index).getInfo();
		} else {
			System.out.printf("In the printStudent():No find id in the ArrrayList%n");
			re = false;
		}
		return re;
	}

	private int findId(int id) {
		int index = -1;

		for(int i = 0;i < this.getList().size();i ++) {
			if(this.getList().get(i).getId() == id) {
				index = i;
				break;
			}
		}

		return index;
	}

	// "6
	private void help() {
		System.out.printf("Help info%n");
		System.out.printf("Example%n");
		System.out.printf("Id:1\t\tName:xinxin%n");
		System.out.printf("Age:10\t\tHoem Address:xindi%n");
	}
}
