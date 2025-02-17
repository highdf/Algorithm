package core;

import java.util.Scanner;

public class StudentSystem{
	//private ArrayList<Student> list;
	private Home home;
	private InterFace face;

	public StudentSystem() {
		this.setHome();
		this.setFace();
	}

	public void setHome() {
		this.home = new Home();
	}
	public void setFace() {
		this.face = new InterFace();
	}

	public Home getHome() {
		return this.home;
	}
	public InterFace getFace(){
		return this.face;
	}

	public void into(Scanner scan) {
		this.getFace().into(scan);		
		this.getHome().into(scan);
	}
}
