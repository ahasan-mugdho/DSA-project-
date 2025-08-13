import java.util.*;

/**
 * Interface defining common course operations.
 */
interface CourseManager {
    /** Check if a course exists by ID. */
    boolean exists(int id);

    /**
     * Add a new course (fails if ID already exists).
     * @return true if added, false if duplicate
     */
    boolean addCourse(int id, String name);

    /** Remove a course by ID. */
    boolean removeCourse(int id);

    /**
     * Find a course name by ID.
     * @return Optional with name if present
     */
    Optional<String> findName(int id);

    /** Print all courses, sorted by ID. */
    void printCourses();
}

/**
 * Department implements the CourseManager rules.
 * It stores the department name and keeps courses sorted by ID.
 */
class Department implements CourseManager {
    private final String name;
    // TreeMap keeps keys sorted ascending by default (ID -> Course Name)
    private final TreeMap<Integer, String> courses = new TreeMap<>();

    public Department(String name) {
        this.name = name;
    }

    public String getName() { return name; }

    @Override
    public boolean exists(int id) {
        return courses.containsKey(id);
    }

    @Override
    public boolean addCourse(int id, String courseName) {
        if (courses.containsKey(id)) return false; // duplicate ID not allowed
        courses.put(id, courseName);
        return true;
    }

    @Override
    public boolean removeCourse(int id) {
        return courses.remove(id) != null;
    }

    @Override
    public Optional<String> findName(int id) {
        return Optional.ofNullable(courses.get(id));
    }

    @Override
    public void printCourses() {
        System.out.println("Department: " + name);
        if (courses.isEmpty()) {
            System.out.println("(no courses)");
            return;
        }
        for (Map.Entry<Integer, String> e : courses.entrySet()) {
            System.out.printf("%4d -> %s%n", e.getKey(), e.getValue());
        }
    }
}

/**
 * Demo main program per the problem statement:
 *  - Create a department
 *  - Add a few courses
 *  - Try adding a duplicate
 *  - Remove a course
 *  - Print all courses
 */
public class Main {
    public static void main(String[] args) {
        Department cse = new Department("CSE");

        // Add a few courses
        System.out.println("Adding courses...");
        System.out.println("Added 101: " + cse.addCourse(101, "Programming Fundamentals"));
        System.out.println("Added 205: " + cse.addCourse(205, "Data Structures"));
        System.out.println("Added 150: " + cse.addCourse(150, "Discrete Mathematics"));

        // Try adding a duplicate ID
        System.out.println("\nTrying duplicate add (ID 205)...");
        System.out.println("Added 205 again: " + cse.addCourse(205, "Advanced Data Structures"));

        // Check existence and find name
        System.out.println("\nExists 101? " + cse.exists(101));
        System.out.println("Name of 150: " + cse.findName(150).orElse("Not found"));

        // Remove a course
        System.out.println("\nRemoving course 101...");
        System.out.println("Removed 101: " + cse.removeCourse(101));

        // Print all courses (sorted by ID automatically)
        System.out.println("\nAll courses now:");
        cse.printCourses();
    }
}
