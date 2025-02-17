package src;

import java.util.ArrayList;

import src.BinSearch;

public class Insert{

	public static void insert(ArrayList<Integer> arr,int insert) {
		int re = BinSearch.binSearch(arr,insert);

		arr.add(re, insert);
	}
}
