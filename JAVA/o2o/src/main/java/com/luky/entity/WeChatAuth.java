package com.luky.entity;

import java.util.Date;

public class WeChatAuth {
	private Long weChatAuth;
	private String openId;
	private Date createTime;
	private User user;

	public WeChatAuth() {
		;
	}
	public WeChatAuth(
		Long weChatAuthId, String openId,
		Date createTime, User user
	) {
		;
	}

	// Set
	public void setUser(User user) {
		this.user = user;
	}
	public void setOpenId(String openId) {
		this.openId = openId;
	}
	public void setCreateTime(Date createTime) {
		this.createTime = createTime;
	}
	public void setWeChatAuth(Long weChatAuth) {
		this.weChatAuth = weChatAuth;
	}
	
	// Get
	public String getOpenId() {
		return openId;
	}
	public Date getCreateTime() {
		return createTime;
	}
	public Long getWeChatAuth() {
		return weChatAuth;
	}
	public User getUser() {
		return user;
	}
}
