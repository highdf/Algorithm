package com.luky.entity;

import java.util.Date;

public class ShopCategory {
	private Integer id;
	private ShopCategory parent_id;
	private String name;
	private String desc;
	private String image;
	private Integer priority;
	private Date createTime;
	private Date lastEditTime;

	// Set
	public void setLastEditTime(Date lastEditTime) {
		this.lastEditTime = lastEditTime;
	}
	public void setId(Integer id) {
		this.id = id;
	}
	public void setName(String name) {
		this.name = name;
	}
	public void setCreateTime(Date createTime) {
		this.createTime = createTime;
	}
	public void setParent_id(Integer parent_id) {
		this.parent_id = parent_id;
	}
	public void setImage(String image) {
		this.image = image;
	}
	public void setPriority(Integer priority) {
		this.priority = priority;
	}
	public void setDesc(String desc) {
		this.desc = desc;
	}

	// Get
	public Date getCreateTime() {
		return createTime;
	}
	public Date getLastEditTime() {
		return lastEditTime;
	}
	public String getName() {
		return name;
	}
	public Integer getId() {
		return id;
	}
	public String getDesc() {
		return desc;
	}
	public Integer getPriority() {
		return priority;
	}
	public Integer getParent_id() {
		return parent_id;
	}
	public String getImage() {
		return image;
	}
}
