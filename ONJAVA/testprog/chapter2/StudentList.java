package chapter2;

public class StudentList{
	private Student[] Arrst;
	private int last;

	public StudentList(int n) {
		this.setArrst(n);
		this.setLast(-1);
	}

	//set
	public void setArrst(int n) {
		Arrst = new Student[n];
	}
	public void setLast(int last) {
		this.last = last;
	}
	
	//get
	public Student[] getArrst() {
		return this.Arrst;
	}
	public int getLast() {
		return this.last;
	}
	public int getLength() {
		return this.Arrst.length;
	}

	public boolean find(Student stud) {
		boolean re = false;

		for(int i = 0;i <= this.getLast();i ++) {
			if(stud.getNumber() == this.getArrst()[i].getNumber()) {
				re = true;
				break;
			}
		}

		return re;
	}

	public void add(Student student,int pos) {
		if(pos >= 0 && pos <= (this.getLast() + 1) ) {
			for(int i = this.getLast();i >= pos;i --) {
				this.getArrst()[i + 1] = this.getArrst()[i];
			}
			this.getArrst()[pos] = student;
			this.setLast(this.getLast() + 1);
		} else {
			System.out.println("error:In the StudentList.add()");
			System.out.println("Position is error");
		}
	}

	public Student delete(int pos) {
		Student re = this.getArrst()[pos];

		for(int i = pos;i < this.getLast();i ++) {
			this.getArrst()[i] = this.getArrst()[i+1];
		}
		this.setLast(this.getLast() - 1);

		return re;
	}
}
