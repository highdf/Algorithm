package com.luky;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.Properties;
import javax.sql.DataSource;
import com.alibaba.druid.pool.DruidDataSourceFactory;

public class Druid {

	public static 
	void main(String[] args) {
		Properties prop = new Properties();

		try {
			prop.load(new FileInputStream("src/main/resources/druid.properties"));
		} catch (FileNotFoundException e) {
			System.out.printf("Not found druid.properties:\n%s\n", e.getMessage());
			System.exit(1);
		} catch (IOException e) {
			System.out.printf("Load druid.properties failed\n%s\n", e.getMessage());
			System.exit(1);
		}

		Connection conn = null;
		try {
			DataSource ds = DruidDataSourceFactory.createDataSource(prop);
			conn = ds.getConnection();
			
			Statement stat = conn.createStatement();
			String sql = "SELECT * FROM student";

			ResultSet rs = stat.executeQuery(sql);

			while (rs.next() == true) {
				int id = rs.getInt("id");
				String name = rs.getString("name");
				int age = rs.getInt("age");
				System.out.printf("|%d\t|%s\t|%d|\n", id, name, age);
			}

			stat.close();
			conn.close();
		} catch (SQLException e) {
			System.out.printf("Connection failed\n%s\n", e.getMessage());
			System.exit(1);

		} catch (Exception e) {
			System.out.printf("Create datasource failed\n%s\n", e.getMessage());
			System.exit(1);
		}
	}
}
