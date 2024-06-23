import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int[] Dwarf = new int[9];
		int Sum = 0;
		for (int i = 0; i < Dwarf.length; i++) {
			Dwarf[i] = Integer.parseInt(br.readLine());
			Sum += Dwarf[i];
		}
		for (int i = 0; i < Dwarf.length; i++) {
			for (int j = i + 1; j < Dwarf.length; j++) {
				if (Sum - Dwarf[i] - Dwarf[j] == 100) {
					Dwarf[i] = -1;
					Dwarf[j] = -1;
				}
			}
		}
		for (int i = 0; i < Dwarf.length; i++) {
			if (Dwarf[i] != -1) {
				System.out.println(Dwarf[i]);
			}
		}
		br.close();
	}

}