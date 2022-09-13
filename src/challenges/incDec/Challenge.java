package challenges.incDec;

public class Challenge {

	// https://edabit.com/challenge/5DAuj96xupYTbFTXw
	
	private static int[] digits(int number) {
		int[] digits = new int[Integer.toString(number).length()];
		for (int i = 0; i <= digits.length; i++) {
			digits[digits.length-i] = (int) ((number % Math.pow(10, i)) / Math.pow(10, i-1));
		}
		return digits;
	}
	
	public static int incDec(int n) {
		int incdec = 0;
		for (int i = 0; i < Math.pow(10, n); i++) {
			int[] digits = digits(i);
			if (digits.length == 1) {
				incdec++;
				continue;
			}
			else {
				boolean isInc = true, isDec = true;
				for (int e = 1, min = digits[0]; e < digits.length; e++) {
					isInc &= (digits[e] >= min);
					min = (digits[e] >= min) ? digits[e] : min;
				}
				for (int e = 1, max = digits[0]; e < digits.length; e++) {
					isDec &= (digits[e] <= max);
					max = (digits[e] <= max) ? digits[e] : max;
				}
				if (isInc || isDec) {
					incdec++;
				}
			}
		}
		return incdec;
	}
	
	public static void main(String[] args) {
		System.out.println(incDec(3));
	}
}
