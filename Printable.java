
public interface Printable {

	public void print();
	public static void print(Printable list[]) {
		for (Printable i : list) {
			i.print();
		}
	}
	
}
