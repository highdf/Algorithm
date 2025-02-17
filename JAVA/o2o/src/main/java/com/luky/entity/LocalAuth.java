package com.luky.entity;

import java.util.Date;

public class LocalAuth {
	private Long localAuthId;
	private String userName;
	private String password;
	private Date createTime;
	private Date lastEditTime;
	private User user;


	public LocalAuth() {
		;
	}
	public LocalAuth(
		Long localAuthId, String userName, String password,
	   	Date createTime, Date lastEditTime, User user
	) {
		;
	}

	// Set
	public void setLastEditTime(Date lastEditTime) {
		this.lastEditTime = lastEditTime;
	}
	public void setCreateTime(Date createTime) {
		this.createTime = createTime;
	}
	public void setUserName(String userName) {
		this.userName = userName;
	}
	public void setPassword(String password) {
		this.password = password;
	}
	public void setLocalAuthId(Long localAuthId) {
		this.localAuthId = localAuthId;
	}
	public void setUser(User user) {
		this.user = user;
	}

	// Get
	public Date getLastEditTime() {
		return lastEditTime;
	}	
	public Date getCreateTime() {
		return createTime;
	}
	public Long getLocalAuthId() {
		return localAuthId;
	}
	public String getUserName() {
		return userName;
	}
	public String getPassword() {
		return password;
	}
	public User getUser() {
		return user;
	}
}
