-- #############
-- table drop ##
-- #############
DROP DATABASE IF EXISTS
	db_o_two_o
;

-- #############
-- 创建数据库 ##
-- #############
CREATE DATABASE IF NOT EXISTS
	db_o_two_o
;

use db_o_two_o;

-- #############
-- 创建表	####
-- #############
CREATE TABLE IF NOT EXISTS
	tb_area
	(
		id INT COMMENT "编号" PRIMARY KEY AUTO_INCREMENT,
		name VARCHAR(200) COMMENT "名称" NOT NULL UNIQUE KEY,
		priority INT COMMENT "权重" DEFAULT '0',
		create_time DATETIME COMMENT "创建时间" DEFAULT NULL,
		last_edit_time DATETIME COMMENT "最近修改时间" DEFAULT NULL
	)
;

CREATE TABLE IF NOT EXISTS
	tb_user
	(
		id INT COMMENT "编号" PRIMARY KEY AUTO_INCREMENT,
		name VARCHAR(32) COMMENT "姓名" DEFAULT NULL,
		profile_img VARCHAR(1024) COMMENT "头像" DEFAULT NULL,
		email VARCHAR(32) COMMENT "邮箱地址" DEFAULT NULL,
		gender VARCHAR(1) COMMENT "性别" DEFAULT NULL,
		status INT COMMENT "状态" DEFAULT '0',
		user_type INT COMMENT "身份标识" DEFAULT '0',
		create_time DATETIME COMMENT "创建时间" DEFAULT NULL,
		last_edit_time DATETIME COMMENT "最近修改时问"
	)
;
		
CREATE TABLE IF NOT EXISTS
	tb_wechat_auth
	(
		wechat_auth_id INT COMMENT "编号" PRIMARY KEY AUTO_INCREMENT,
		open_id VARCHAR(1024) DEFAULT NULL,
		create_time DATETIME COMMENT "创建时间" DEFAULT NULL,
		user_id INT COMMENT "使用者ID" DEFAULT '0',
		CONSTRAINT fk_wechat_auth_user
		FOREIGN KEY (user_id)
		REFERENCES tb_user(id)
	)
;

CREATE TABLE IF NOT EXISTS
	tb_local_auth
	(
		id INT COMMENT "编号" PRIMARY KEY AUTO_INCREMENT,
		user_name varchar(32) COMMENT "用户名" DEFAULT NULL,
		password varchar(16) COMMENT "密码" NOT NULL,
		user_id INT COMMENT "使用者ID" NOT NULL,
		create_time DATETIME COMMENT "创建时间" DEFAULT NULL,
		last_edit_time DATETIME COMMENT "最近修改时间" DEFAULT NULL,
		CONSTRAINT fk_local_auth_user 
		FOREIGN KEY (user_id)
		REFERENCES tb_user(id)
	)
;

CREATE TABLE 
	tb_headlink
	(
		id int COMMENT "编号" PRIMARY KEY AUTO_INCREMENT,
		name VARCHAR(1023) COMMENT "名称" DEFAULT NULL,
		link VARCHAR(1024) COMMENT "链接" DEFAULT NULL,
		status INT COMMENT "状态" DEFAULT '0',
		priority INT COMMENT "权重" DEFAULT '0',
		create_time DATETIME COMMENT "创建时间" DEFAULT NULL,
		last_edit_time DATETIME COMMENT "最近修改时间" DEFAULT NULL,
		image VARCHAR(1024) COMMENT "图片" DEFAULT NULL
	)
;

CREATE TABLE 
	tb_shopcategory
	(
		id INT COMMENT "编号" PRIMARY KEY AUTO_INCREMENT,
		parent_id INT COMMENT "父级ID" DEFAULT '0',
		name VARCHAR(32) COMMENT "名称" DEFAULT NULL,
		`desc` VARCHAR(1024) COMMENT "描述" DEFAULT NULL,
		image VARCHAR(1024) COMMENT "图片" DEFAULT NULL,
		priority INT COMMENT "权重" DEFAULT 0,
		create_time DATETIME COMMENT "创建时间" DEFAULT NULL,
		last_edit_time DATETIME COMMENT " 修改时间" DEFAULT NULL,
		CONSTRAINT tb_shopcategory
		FOREIGN KEY (parent_id)
		REFERENCES tb_shopcategory(id)
	)
;
		
CREATE TABLE
	tb_shop
	(
		id INT COMMENT "编号" PRIMARY KEY AUTO_INCREMENT,
		status INT COMMENT "忕态" DEFAULT '0',
		priority INT COMMENT "权重" DEFAULT '0',
		image VARCHAR(1024) COMMENT "图片" DEFAULT NULL,
		name VARCHAR(128) COMMENT "名称" DEFAULT NULL,
		`desc` VARCHAR(1024) COMMENT "描迏" DEFAULT NULL,
		phone VARCHAR(13) COMMENT "电话" DEFAULT NULL,
		address VARCHAR(128) COMMENT "地址" DEFAULT NULL,
		create_time DATETIME COMMENT "创建时间" DEFAULT NULL,
		last_edit_time DATETIME COMMENT "修改时间" DEFAULT NULL,
		user_id INT COMMENT "使用者ID" DEFAULT NULL,
		area_id INT COMMENT "地址ID" DEFAULT NULL,
		shop_category_id INT COMMENT "类别ID" DEFAULT NULL,

		CONSTRAINT fk_shop_user
		FOREIGN KEY (user_id)
		REFERENCES tb_user(id),

		CONSTRAINT fk_shop_area
		FOREIGN KEY (area_id)
		REFERENCES tb_area(id),

		CONSTRAINT fk_shop_category
		FOREIGN KEY ( shop_category_id )
		REFERENCES tb_shopcategory(id)
	)
;
	
desc tb_shop;
