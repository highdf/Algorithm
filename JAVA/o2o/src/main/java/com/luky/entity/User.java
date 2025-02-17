package com.luky.entity;

import java.util.Date;

public class User {
	private Long id;
	private String name;
	private String profileImg;
	private String email;
	private String gender;
	private Integer status;
	private Integer userTyep;
	private Date create_time;
	private Date lastEditTime;

	public User() {
		;
	}
	public User(
		Integer id, String name, String profileImg,
		String email, String gender, Integer userTyep,
		Date createTime, Date lastEditTime
	) {
		;
	}
	// Set
	public void setId(Long id) {
		this.id = id;
	}
	public void setName(String name) {
		this.name = name;
	}
	public void setProfileImg(String profileImg) {
		this.profileImg = profileImg;
	}
	public void setCreate_time(Date create_time) {
		this.create_time = create_time;
	}
	public void setLastEditTime(Date lastEditTime) {
		this.lastEditTime = lastEditTime;
	}
	public void setStatus(Integer status) {
		this.status = status;
	}
	public void setGender(String gender) {
		this.gender = gender;
	}
	public void setEmail(String email) {
		this.email = email;
	}
	public void setUserTyep(Integer userTyep) {
		this.userTyep = userTyep;
	}

	// Get
	public String getName() {
		return name;
	}
	public Date getLastEditTime() {
		return lastEditTime;
	}
	public Date getCreate_time() {
		return create_time;
	}
	public Long getId() {
		return id;
	}
	public String getGender() {
		return gender;
	}
	public String getProfileImg() {
		return profileImg;
	}
	public String getEmail() {
		return email;
	}
	public Integer getUserTyep() {
		return userTyep;
	}
	public Integer getStatus() {
		return status;
	}
}
