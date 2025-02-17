package com.luky.entity;

import java.util.Date;

public class HeadLine {
	private Integer id;
	private String name;
	private String link;
	private Integer status;
	private Integer priorty;
	private Date createTime;
	private Date lastEditTime;
	private String image;

	// Set
	public void setLastEditTime(Date lastEditTime) {
		this.lastEditTime = lastEditTime;
	}
	public void setCreateTime(Date createTime) {
		this.createTime = createTime;
	}
	public void setName(String name) {
		this.name = name;
	}
	public void setStatus(Integer status) {
		this.status = status;
	}
	public void setId(Integer id) {
		this.id = id;
	}
	public void setPriorty(Integer priorty) {
		this.priorty = priorty;
	}
	public void setLink(String link) {
		this.link = link;
	}
	public void setImage(String image) {
		this.image = image;
	}
	
	// Get
	public Date getLastEditTime() {
		return lastEditTime;
	}
	public Date getCreateTime() {
		return createTime;
	}
	public String getName() {
		return name;
	}
	public Integer getStatus() {
		return status;
	}
	public Integer getId() {
		return id;
	}
	public Integer getPriorty() {
		return priorty;
	}
	public String getLink() {
		return link;
	}
	public String getImage() {
		return image;
	}
}
