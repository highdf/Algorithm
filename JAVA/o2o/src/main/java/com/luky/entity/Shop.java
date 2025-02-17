package com.luky.entity;

import java.util.Date;

public class Shop {
	private Integer status;
	private Integer priority;
	private Integer id;
	private String image;
	private String name;
	private String desc;
	private String phone;
	private String address;
	private Date createTime;
	private Date lastEditTime;

	private ShopCategory shopCategory;
	private Area area;
	private User user_id;

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
	public void setId(Integer id) {
		this.id = id;
	}
	public void setStatus(Integer status) {
		this.status = status;
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
	public void setShopCategory(ShopCategory shopCategory) {
		this.shopCategory = shopCategory;
	}
	public void setPhone(String phone) {
		this.phone = phone;
	}
	public void setArea(Area area) {
		this.area = area;
	}
	public void setUser_id(User user_id) {
		this.user_id = user_id;
	}
	public void setAddress(String address) {
		this.address = address;
	}

	// Get
	public String getName() {
		return name;
	}
	public Date getCreateTime() {
		return createTime;
	}
	public Date getLastEditTime() {
		return lastEditTime;
	}
	public Integer getId() {
		return id;
	}
	public Integer getStatus() {
		return status;
	}
	public String getImage() {
		return image;
	}
	public Integer getPriority() {
		return priority;
	}
	public String getDesc() {
		return desc;
	}
	public Area getArea() {
		return area;
	}
	public String getPhone() {
		return phone;
	}
	public String getAddress() {
		return address;
	}
	public User getUser_id() {
		return user_id;
	}
	public ShopCategory getShopCategory() {
		return shopCategory;
	}
}
