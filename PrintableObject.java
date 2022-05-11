
public abstract class PrintableObject implements NamedObject, Printable {
	
	public String toString() {
		return this.getClass().getName();
	}

	public void print() {
		System.out.println(this.toString());
	}
	
}
