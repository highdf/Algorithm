import Extends.HuaShiQi;
import Extends.LiHua;
import Extends.ShaPi;
import Extends.TianYuanQian;

public class Main {

	public static void main(String[] args) {
		HuaShiQi hsq = new HuaShiQi();
		ShaPi sq = new ShaPi();
		TianYuanQian tyq = new TianYuanQian();

		hsq.chiFan();
		sq.chiFan();
		tyq.chiFan();
		hsq.kanJia();
	}
}
