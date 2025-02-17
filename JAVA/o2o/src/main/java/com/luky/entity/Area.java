package com.luky.entity;

import java.util.Date;

public class Area {
	private Integer id;
	private String name;
	private int priority;
	private Date create_time;
	private Date lastEditTime;

	public Area() {
		;
	}
	public Area(
		Integer id, String name,
		Integer priorty, Date create_time,
		Date lastEditTiem
	) {
		;
	}

	// Set
	public void setId(Integer id) {
		this.id = id;
	}
	public void setName(String name) {
		this.name = name;
	}
	public void setPriority(int priority) {
		this.priority = priority;
	}
	public void setCreate_time(Date create_time) {
		this.create_time = create_time;
	}
	public void setLastEditTime(Date lastEditTime) {
		this.lastEditTime = lastEditTime;
	}

	// Get
	public Integer getId() {
		return id;
	}
	public String getName() {
		return name;
	}
	public int getPriority() {
		return priority;
	}
	public Date getCreate_time() {
		return create_time;
	}
	public Date getLastEditTime() {
		return lastEditTime;
	}
}
