package Extends;

import Extends.Cat;

public class LiHua extends Cat{
	public void Cua() {
		System.out.printf("In the LiHua%n");
	}
	@Override
	public void Zha() {
		super.Zha();;
		super.getSize();
		System.out.printf("In the LiHua:Zha()%n");
	}
}
