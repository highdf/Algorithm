package com.luky;

import com.luky.CustomList.CustomArrayList;
import com.luky.CustomList.List;

public class CustomListTest  {

	public void testadd ()  {
		String[][] testCases =  {
			{"Heelo", "World", "Butcher"},
			{"Yws"},
			{},
		};

		List<String> list = new CustomArrayList<>(2);
		try {
			list.add("Hello");
			list.add("World");
			list.remove(10);
		} catch (IndexOutOfBoundsException e)  {
			System.out.printf("Have IndexOutOfBoundsException");
		}
	}
}

