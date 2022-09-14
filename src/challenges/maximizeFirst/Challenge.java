package challenges.maximizeFirst;

public class Challenge {
	
	public static int maxPossible(int num, int digits) {
		String nums = String.valueOf(num) + String.valueOf(digits);
		char[] arr = nums.toCharArray();
		for (int i = 0; i < nums.length(); i++) {
			for (int e = 0; e < nums.length()-i-1; e++) {
				if (arr[e] < arr[e+1]) {
					char swap = arr[e];
					arr[e] = arr[e+1];
					arr[e+1] = swap;
				}
			}
		}
		return Integer.parseInt(new String(arr).substring(0, String.valueOf(num).length()));
	}
	
	public static void main(String[] args) {
		System.out.println(maxPossible(9328, 456));
	}
}
