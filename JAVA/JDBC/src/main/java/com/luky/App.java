package com.luky;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.sql.Connection;
import java.sql.SQLException;
import java.util.Properties;
import javax.sql.DataSource;

import com.alibaba.druid.pool.DruidDataSourceFactory;

public class App 
{
	public static void main( String[] args ) {
		String url = "jdbc:mariadb://127.0.0.1/test";
		String user = "luky";
		String password = "275365";

		Connection conn = null;
		Statement stat = null;

		try {
			conn = DriverManager.getConnection(url, user, password);
			System.out.printf("Connection mariadb sucessfully\n");

			stat = conn.createStatement();
			String sql_stat = "CREATE TABLE IF NOT EXISTS test(id int comment \"编号\")";
			stat.execute(sql_stat);

			sql_stat = "SELECT * FROM student";
			ResultSet ret_set = stat.executeQuery(sql_stat);

			System.out.printf("Id\t\tName\t\tAge\t\tGender\n");
			while (ret_set.next() == true)  {
				int id = ret_set.getInt("id");
				String name = ret_set.getString("name");
				int age = ret_set.getInt("age");
				String gender = ret_set.getString("gender");

				System.out.printf("%d\t\t%s\t\t%d\t\t%s\n", id, name, age, gender);
			}
		} catch (SQLException e)  {
			System.out.printf("Connection mariadb failed:\n%s\n", e.getMessage());
		} finally  {
			try  {
				stat.close();
				conn.close();
			} catch (SQLException e)  {
				System.out.printf("Connection or Statment close failed\n");
			}
			System.out.printf("Connectio and Statment closed\n");
		}
	}
}
