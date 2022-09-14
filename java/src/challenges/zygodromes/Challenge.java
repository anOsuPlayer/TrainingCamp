package challenges.zygodromes;

public class Challenge {

	// https://edabit.com/challenge/QdENiEqqhHtYFrk5A
	
	private static int[] partition(long num) {
		int[] digits = new int[Long.toString(num).length()];
		for (int i = 1; i <= digits.length; i++) {
			digits[digits.length-i] = (int) ((num % Math.pow(10, i)) / Math.pow(10, i-1));
		}
		return digits;
	}
	
	public static boolean isZygodrome(long num) {
		if (num / 10 == 0 || num < 0) { return false; }
		int[] digits = partition(num);
		boolean isEqual = true, isZygo = true, wasEqual = false;
		for (int i = 1; i < digits.length; i++) {
			isEqual = (digits[i] == digits[i-1]);
			isZygo &= (isEqual || wasEqual);
			wasEqual = isEqual;
		}
		isZygo &= (digits[digits.length-2] == digits[digits.length-1]);
		return isZygo;
	}
	
	public static void main(String[] args) {
		System.out.println(isZygodrome(8866611229999L));
	}
}
