package Static;

public class Classroon{
	private String studentName;
	private String teacherName;

	public Classroon() {
		;
	}

	public Classroon(String studentName,String teacherName) {
		this.setStudentName(studentName);
		this.setTeacherName(teacherName);
	}

	//set
	public void setStudentName(String studentName) {
		this.studentName = studentName;
	}
	public void setTeacherName(String teacherName) {
		this.teacherName = teacherName;
	}

	//get
	public String getStudentName() {
		return this.studentName;
	}

	public String getTeacherName() {
		return this.teacherName;
	}
}
