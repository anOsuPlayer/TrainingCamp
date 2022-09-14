package challenges.centrifuge;

public class Challenge {

	private static boolean isPrime(int p) {
		if (p == 2 || p == 3 || p == 5 || p == 7) { return true; }
		if (p % 2 != 0 && p % 3 != 0 && p % 5 != 0 && p % 7 != 0) { return true; }
		return false;
	}
	
	private static int[] factors(int n) {
		int[] primes = new int[n];
		for (int i = 2, c = 0; i < n; i++) {
			if (n % i == 0 && isPrime(n)) {
				primes[c++] = i;
			}
		}
		return primes;
	}
	
	public static boolean cFuge(int n, int k) {
		if (n <= 1 || k <= 1 || k > n) {
			return false;
		}
		return false;
	}
	
	public static void main(String[] args) {
		System.out.println(factors(15)[1]);
	}
}
