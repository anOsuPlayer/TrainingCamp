package challenges.numToEng;

import java.util.Arrays;
import java.util.List;

public class Challenge {

	private static List<String> nums = Arrays.asList(new String[] {"zero", "one", "two", "three", "four", "five",
			"six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen",
			"sixteen", "seventeen", "eighteen", "nineteen", "twenty", "thirty", "forty", "fifty", "sixty",
			"seventy", "eighty", "ninety"});
	
	public static String numToEng(int n) {
		if (n < 0 || n > 999) {
			throw new IllegalArgumentException("number not in range.");
		}
		if (n >= 0 && n <= 20) {
			return nums.get(n);
		}
		
		String result = "";
		if (n >= 100) {
			result += nums.get(n / 100) + " hundred";
			if (n % 100 > 0 && n % 100 <= 20) {
				result += " " + nums.get(n % 100);
			}
			else {
				result += " " + nums.get((n % 100) / 10 + 18);
				if (n % 10 != 0) {
					result += " " + nums.get(n % 10);
				}
			}
		}
		return result;
	}
	
	public static void main(String[] args) {
		System.out.println(numToEng(8));
	}
}
