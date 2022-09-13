package challenges.sumDigProd;

public class Challenge {

	private static int order(long number) {
		int order = 0;
		for (int i = 1; number / i > 0; i *= 10) {
			order++;
		}
		return order;
	}
	
	public static long sumDigProd(long...nums) {
		long[] def = new long[]{ 0, 0 };
		for (int i = 0; i < nums.length; i++) {
			def[0] += nums[i];
		}
		while (order(def[0]) > 1) {
			def[1] = 1;
			for (int i = 1; i <= order(def[0]); i++) {
				def[1] *= (int) ((def[0] % Math.pow(10, i)) / Math.pow(10, i-1));
			}
			def[0] = def[1];
		}
		return def[0];
	}
	
	public static void main(String[] args) {
		System.out.println(sumDigProd(16, 28));
	}
}