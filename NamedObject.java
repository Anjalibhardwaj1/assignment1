
public interface NamedObject {

	default String getName() {
		return this.getClass().getName();
	}
	
}
