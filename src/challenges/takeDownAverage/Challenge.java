package challenges.takeDownAverage;

public class Challenge {

	// https://edabit.com/challenge/QdENiEqqhHtYFrk5A
	
	public static String takeDownAverage(String[] scores) {
		float[] scrs = new float[scores.length];
		for (int i = 0; i < scrs.length; i++) {
			scrs[i] = Float.parseFloat(scores[i].substring(0, scores[i].length()-1));
		}
		float total = 0;
		for (float f : scrs) {
			total += f;
		}
		float avg = total / scrs.length;
		float buffdAvg = avg - (avg * 0.05f);
		int score = 0;
		for (score = 100; ((total + score) / (scrs.length + 1)) > buffdAvg; score--);
		return String.valueOf(score + "%");
	}
	
	public static void main(String[] args) {
		System.out.println(takeDownAverage(new String[] {"10%"}));
	}
}
